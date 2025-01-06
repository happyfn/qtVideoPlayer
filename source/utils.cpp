#include "utils.h"
#include <QMessageBox>
#include <QDateTime>
#include <QRegularExpression>
#include <cmath>

FFmpegDecoder::FFmpegDecoder() {
    //av_register_all(); // FFmpeg 初始化
}

FFmpegDecoder::~FFmpegDecoder() {
    closeVideo();
}

bool FFmpegDecoder::openVideo(const std::string& filePath) {
    closeVideo(); // 确保干净初始化

    if (avformat_open_input(&formatContext, filePath.c_str(), nullptr, nullptr) != 0) {
        return false;
    }
    if (avformat_find_stream_info(formatContext, nullptr) < 0) {
        return false;
    }

    // 找到视频流
    for (unsigned int i = 0; i < formatContext->nb_streams; i++) {
        if (formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
            videoStreamIndex = i;
            break;
        }
    }
    if (videoStreamIndex == -1) {
        return false;
    }

    // 解码器初始化
    const AVCodec* codec = avcodec_find_decoder(formatContext->streams[videoStreamIndex]->codecpar->codec_id);
    if (!codec) {
        return false;
    }
    codecContext = avcodec_alloc_context3(codec);
    avcodec_parameters_to_context(codecContext, formatContext->streams[videoStreamIndex]->codecpar);
    if (avcodec_open2(codecContext, codec, nullptr) < 0) {
        return false;
    }

    frame = av_frame_alloc();
    packet = av_packet_alloc();
    swsContext = nullptr;
    return true;
}

QImage FFmpegDecoder::pos2Image(int64_t postion) {
    QImage image{};
    if (!formatContext || !codecContext) {
        return image;
    }
    int64_t target_pts = postion * formatContext->streams[videoStreamIndex]->time_base.den / 1000;
    if (avformat_seek_file(formatContext, videoStreamIndex, INT64_MIN, target_pts, INT64_MAX, AVSEEK_FLAG_BACKWARD) < 0) {
        return image;
    }
    avcodec_flush_buffers(codecContext);

    bool found = false;
    while (av_read_frame(formatContext, packet) >= 0) {
        if (packet->stream_index == videoStreamIndex) {
            if (avcodec_send_packet(codecContext, packet) >= 0) {
                if (avcodec_receive_frame(codecContext, frame) >= 0) {
                    if (frame->pts >= target_pts) {
                        found = true;
                        image = frame2Image(frame);
                        av_packet_unref(packet);
                        break;
                    }
                }
            }
        }
        av_packet_unref(packet);
    }
    return image;
}

void FFmpegDecoder::closeVideo() {
    if (swsContext) {
        sws_freeContext(swsContext);
        swsContext = nullptr;
    }
    if (frame) {
        av_frame_free(&frame);
        frame = nullptr;
    }
    if (packet) {
        av_packet_free(&packet);
        packet = nullptr;
    }
    if (codecContext) {
        avcodec_free_context(&codecContext);
        codecContext = nullptr;
    }
    if (formatContext) {
        avformat_close_input(&formatContext);
        formatContext = nullptr;
    }
}

QImage FFmpegDecoder::frame2Image(AVFrame* frame) {
    // 将帧转换为RGB格式
    if (!swsContext) {
        swsContext = sws_getContext(frame->width, frame->height, codecContext->pix_fmt,
            frame->width, frame->height, AV_PIX_FMT_RGB24,
            SWS_BILINEAR, nullptr, nullptr, nullptr);
    }

    uint8_t* rgbData[4];
    int rgbLineSize[4];
    av_image_alloc(rgbData, rgbLineSize, frame->width, frame->height, AV_PIX_FMT_RGB24, 1);

    sws_scale(swsContext, frame->data, frame->linesize, 0, frame->height, rgbData, rgbLineSize);

    QImage img(rgbData[0], frame->width, frame->height, QImage::Format_RGB888);
    img = img.convertToFormat(QImage::Format_Grayscale8); // 确保 QImage 独立于 FFmpeg 的缓冲区
    av_freep(&rgbData[0]);
    return img;
}

namespace Utils {
    QString Pos2Time(qint64 position) {
        return QString("%1:%2:%3.%4")
            .arg(position / 3600000, 2, 10, QChar('0'))
            .arg((position / 60000) % 60, 2, 10, QChar('0'))
            .arg((position / 1000) % 60, 2, 10, QChar('0'))
            .arg(position % 1000, 3, 10, QChar('0'));
    }

    void DataProcessing(QVector<QStringList>& outData, const QStringList& inData) {
        QVector<QStringList> result;
        bool inserted = false;

        for (const auto& i : outData) {
            if (inData[0].toInt() <= i[0].toInt() && inData[1].toInt() >= i[1].toInt()) {
                continue;
            }
            else if (i[1].toInt() <= inData[0].toInt()) {
                result.append(i);
            }
            else if (i[0].toInt() >= inData[1].toInt()) {
                if (!inserted) {
                    result.append(inData);
                    inserted = true;
                }
                result.append(i);
            }
            else {
                if (i[0].toInt() < inData[0].toInt()) {
                    result.append(QStringList{ i[0], inData[0], i[2], i[3], i[4], i[5], i[6], i[7] });
                }
                result.append(inData);
                if (i[1].toInt() > inData[1].toInt()) {
                    result.append(QStringList{ inData[1], i[1], i[2], i[3], i[4], i[5], i[6], i[7] });
                }
                inserted = true;
            }
        }

        if (!inserted) {
            result.append(inData);
        }

        outData = result;
    }

    void InitFile(const QString& fileName, QVector<QStringList>& data) {
        QFile file(fileName);

        if (!file.exists()) {
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QMessageBox::critical(nullptr, "Error", QString("can not create: %1").arg(fileName));
                return;
            }
            QTextStream out(&file);
            out << DATA_HEADING;
            file.close();
            return;
        }

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::critical(nullptr, "Error", QString("can not read file: %1").arg(fileName));
            return;
        }
        QTextStream in(&file);
        QString firstLine = in.readLine() + "\n";
        if (firstLine != DATA_HEADING) {
            file.close();
            file.open(QIODevice::WriteOnly | QIODevice::Text);
            QTextStream out(&file);
            out << DATA_HEADING;
        }
        else {
            while (!in.atEnd()) {
                QString line = in.readLine();
                QStringList fields = line.split(",");
                if (fields.size() == 8) {
                    data.append(fields);
                }
            }
        }
        file.close();
    }
}

OcrEngine::OcrEngine() {
    int ret = m_ocrEngine.Init("../opensource/tesseract/tessdata", "eng", tesseract::OEM_LSTM_ONLY);
    if (ret != 0) {
        qDebug() << "Tesseract OCR Engine Init failed.";
        return;
    }
    m_ocrEngine.SetVariable("tessedit_char_whitelist", "0123456789:");
    m_isInit = true;
}

OcrEngine::~OcrEngine() {
    if (m_isInit) {
        m_ocrEngine.End();
    }
}

QString OcrEngine::image2Text(QImage& image) {
    Pix* pix = pixCreate(image.width(), image.height(), 8);
    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            QRgb pixel = image.pixel(x, y);
            int gray = qGray(pixel);
            pixSetPixel(pix, x, y, gray);
        }
    }

    m_ocrEngine.SetImage(pix);
    QString result = QString::fromUtf8(m_ocrEngine.GetUTF8Text());
    QRegularExpression timeRegex(R"(\b([0-1]?[0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9]\b)");
    QRegularExpressionMatch match = timeRegex.match(result);
    if (match.hasMatch()) {
        result = match.captured(0);
    }
    else {
        result = "";
    }
    pixDestroy(&pix);
    m_ocrEngine.Clear();
    return result;
}
