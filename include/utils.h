#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include <QVector>
#include <QFileInfo>
#include <QtGui/QIcon>
#include <QImage>
#include <QMap>

#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

extern "C" {
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libswscale/swscale.h>
#include <libavutil/imgutils.h>
}

#define SAFE_DELETE(ptr) \
    do { \
        delete ptr; \
        ptr = nullptr; \
    } while (0)

#define SAFE_DELETE_ARRAY(ptr) \
    do { \
        delete[] ptr; \
        ptr = nullptr; \
    } while (0)

#define DATA_HEADING "firstFrame,lastFrame,firstFrameTime,lastFrameTime,trueFirstTime,trueLastTime,laneCount,laneNum\n"

class FFmpegDecoder {
public:
    FFmpegDecoder();
    ~FFmpegDecoder();

    bool openVideo(const std::string& filePath);
    QImage pos2Image(int64_t postion); // postion为时间戳，单位毫秒
    void closeVideo();

private:
    AVFormatContext* formatContext = nullptr;
    AVCodecContext* codecContext = nullptr;
    AVFrame* frame = nullptr;
    AVPacket* packet = nullptr;
    SwsContext* swsContext = nullptr;
    int videoStreamIndex = -1;

    QImage frame2Image(AVFrame* frame);
};

class OcrEngine {
public:
    OcrEngine();
    ~OcrEngine();

    // Using Ocr engine convert QImage to QString
    QString image2Text(QImage& image);

private:
    bool m_isInit{false};               //Is it initialized
    tesseract::TessBaseAPI m_ocrEngine; //OCR engine
};

namespace Utils {
	static QIcon iconPlay(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackStart));
	static QIcon iconPause(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackPause));

	//Convert video position to time
	QString Pos2Time(qint64 position);

	//Process the entire annotation result based on the entered annotation data
	void DataProcessing(QVector<QStringList>& outData, const QStringList& inData);

	//Initialize annotation file
	void InitFile(const QString& fileName, QVector<QStringList>& data);
}

#endif
