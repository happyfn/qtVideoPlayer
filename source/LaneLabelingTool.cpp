#include "LaneLabelingTool.h"
#include "utils.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QMediaMetaData>
#include <QAudioOutput>
#include <QTextStream>
#include <QDebug>

LaneLabelingTool::LaneLabelingTool(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::LaneLabelingTool),
    getTimeUi(new Ui::getTimePos),
    getTimeWindow(new QWidget),
    player(new QMediaPlayer(this)),
    timer(new QTimer(this)),
    skipFrameTimer(new QTimer(this))
{
    ui->setupUi(this);
    getTimeUi->setupUi(getTimeWindow);
    player->setVideoOutput(ui->videoWidget);

    connect(ui->playPauseButton, &QPushButton::clicked, this, &LaneLabelingTool::playPause);
    connect(ui->saveButton, &QPushButton::clicked, this, &LaneLabelingTool::saveInfo);
    connect(ui->frameBegineButton, &QPushButton::clicked, this, &LaneLabelingTool::editFirstFrame);
    connect(ui->frameEndButton, &QPushButton::clicked, this, &LaneLabelingTool::editLastFrame);
    connect(ui->stopButton, &QPushButton::clicked, this, &LaneLabelingTool::stopVideo);
    connect(ui->openButton, &QPushButton::clicked, this, &LaneLabelingTool::openFile);
    connect(ui->eidtButton, &QPushButton::clicked, this, &LaneLabelingTool::editModel);
    connect(ui->cancelButton, &QPushButton::clicked, this, &LaneLabelingTool::cancelEdit);
    connect(ui->deleteButton, &QPushButton::clicked, this, &LaneLabelingTool::deleteMsg);
    connect(ui->getTimePosButton, &QPushButton::clicked, this, &LaneLabelingTool::getTimePos);
    connect(getTimeUi->getTimeButton, &QPushButton::clicked, this, &LaneLabelingTool::getTime);

    //此处监听进度条被拖动，不然完全绑定视频进度会导致播放卡顿
    connect(ui->playCtrSlider, &QSlider::sliderPressed, this, &LaneLabelingTool::onSliderPressed);
    connect(ui->playCtrSlider, &QSlider::sliderReleased, this, &LaneLabelingTool::onSliderReleased);
    connect(ui->playCtrSlider, &QSlider::sliderMoved, this, &LaneLabelingTool::onSliderMoved);
    connect(timer, &QTimer::timeout, this, &LaneLabelingTool::updateTime);
    connect(skipFrameTimer, &QTimer::timeout, this, &LaneLabelingTool::changeFrame);
    connect(ui->nextFrameButton, &QPushButton::pressed, this, &LaneLabelingTool::onNextFramePressed);
    connect(ui->nextFrameButton, &QPushButton::released, this, &LaneLabelingTool::onFrameReleased);
    connect(ui->prevFrameButton, &QPushButton::pressed, this, &LaneLabelingTool::onPrevFramePressed);
    connect(ui->prevFrameButton, &QPushButton::released, this, &LaneLabelingTool::onFrameReleased);

    connect(player, &QMediaPlayer::positionChanged, this, &LaneLabelingTool::updatePosition);
    connect(player, &QMediaPlayer::mediaStatusChanged, this, &LaneLabelingTool::mediaStatusChanged);

    timer->start(200);
    skipFrameTimer->setInterval(100);
    reSetButton(false);
    buttonVisible(false, false, false, false, false);
}

LaneLabelingTool::~LaneLabelingTool() {
    SAFE_DELETE(ui);
    SAFE_DELETE(getTimeUi);
    SAFE_DELETE(getTimeWindow);
    SAFE_DELETE(player);
    SAFE_DELETE(timer);
}

void LaneLabelingTool::reSetButton(bool needOpen) {
    ui->playPauseButton->setVisible(needOpen);
    ui->prevFrameButton->setVisible(needOpen);
    ui->nextFrameButton->setVisible(needOpen);
    ui->stopButton->setVisible(needOpen);
    ui->playCtrSlider->setVisible(needOpen);
    ui->getTimePosButton->setVisible(needOpen);
    ui->laneCountValue->setReadOnly(!needOpen);
    ui->laneNumValue->setReadOnly(!needOpen);
    ui->firstFrameValue->setReadOnly(!needOpen);
    ui->lastFrameValue->setReadOnly(!needOpen);
    ui->trueStartTimeValue->setReadOnly(!needOpen);
    ui->trueEndTimeValue->setReadOnly(!needOpen);
}

void LaneLabelingTool::buttonVisible(bool editFrame, bool edit, bool deleteMsg, bool cancelEidt, bool save) {
    ui->frameBegineButton->setVisible(editFrame);
    ui->frameEndButton->setVisible(editFrame);
    ui->eidtButton->setVisible(edit);
    ui->deleteButton->setVisible(deleteMsg);
    ui->cancelButton->setVisible(cancelEidt);
    ui->saveButton->setVisible(save);
}

void LaneLabelingTool::openFile() {
    videoLoaded = false;
    ui->videoFullTime->setText("00:00:00.000");
    data = {"0", "0", "0", "0", "0", "0", "0", "0"};
    reSetButton(false);
    buttonVisible(false, false, false, false, false);

    QString fileName = QFileDialog::getOpenFileName(this, "open video");
    if (fileName.isEmpty()) {
        return;
    }

    player->setSource(QUrl::fromLocalFile(fileName));
    ui->fileNameLabel->setText("video:" + fileName);

    QFileInfo fileInfo(fileName);
    this->csvFilePath = fileInfo.absolutePath() + "/" + fileInfo.completeBaseName() + ".csv";

    Utils::InitFile(this->csvFilePath, this->csvData);
    decoder.openVideo(fileName.toStdString());
    frame0Image = decoder.pos2Image(0);
    reSetButton(true);
}

void LaneLabelingTool::playPause() {
    if (player->playbackState() == QMediaPlayer::PlayingState) {
        player->pause();
        ui->playPauseButton->setIcon(Utils::iconPlay);
    }
    else {
        player->play();
        ui->playPauseButton->setIcon(Utils::iconPause);
    }
}

void LaneLabelingTool::stopVideo() {
    player->stop();
    ui->playPauseButton->setIcon(Utils::iconPlay);
    videoStatus = VideoStatus::STOPED;
    reSetButton(true);
    buttonVisible(false, false, false, false, false);
    ui->editStatusValue->setText("无");
    ui->frame->setText("0");
    ui->time->setText("00:00:00.000");
    ui->firstFrameValue->setText("");
    ui->trueStartTimeValue->setText("");
    ui->lastFrameValue->setText("");
    ui->trueEndTimeValue->setText("");
    ui->laneCountValue->setText("");
    ui->laneNumValue->setText("");
    firstFramePressed = false;
    lastFramePressed = false;
    editPressed = false;
}

void LaneLabelingTool::updatePosition(qint64 position) {
    ui->playCtrSlider->setValue(position);
    int frame = position * frameRate / 1000;
    ui->frame->setText(QString::number(frame));
    ui->time->setText(Utils::Pos2Time(position));
    if (editPressed || firstFramePressed || lastFramePressed) {
        return;
    }
    for (const QStringList& i : csvData) {
        if (frame >= i[0].toInt() && frame <= i[1].toInt()) {
            ui->firstFrameValue->setText(i[0]);
            ui->trueStartTimeValue->setText(i[4]);
            ui->lastFrameValue->setText(i[1]);
            ui->trueEndTimeValue->setText(i[5]);
            ui->laneCountValue->setText(i[6]);
            ui->laneNumValue->setText(i[7]);
            return;
        }
    }
    ui->firstFrameValue->setText("");
    ui->trueStartTimeValue->setText("");
    ui->lastFrameValue->setText("");
    ui->trueEndTimeValue->setText("");
    ui->laneCountValue->setText("");
    ui->laneNumValue->setText("");
}

void LaneLabelingTool::changeFrame() {
    if (isNextFrame) {
        qint64 newPosition = player->position() + 1 / frameRate * 1000;
        player->setPosition(newPosition);
    }
    else {
        qint64 newPosition = player->position() - 1 / frameRate * 1000;
        player->setPosition(newPosition < 0 ? 0 : newPosition);
    }
}

void LaneLabelingTool::onNextFramePressed() {
    isNextFrame = true;
    changeFrame();
    skipFrameTimer->start();
}

void LaneLabelingTool::onPrevFramePressed() {
    isNextFrame = false;
    changeFrame();
    skipFrameTimer->start();
}

void LaneLabelingTool::onFrameReleased() {
    skipFrameTimer->stop();
}

void LaneLabelingTool::onSliderPressed() {
    if (player->playbackState() == QMediaPlayer::PlayingState) {
        player->pause();
        ui->playPauseButton->setIcon(Utils::iconPlay);
        sliderUsed = 2;
    }
    else {
        sliderUsed = 1;
    }
}

void LaneLabelingTool::onSliderReleased() {
    player->setPosition(ui->playCtrSlider->value());
    if (player->playbackState() == QMediaPlayer::PausedState && sliderUsed == 2) {
        player->play();
        ui->playPauseButton->setIcon(Utils::iconPause);
    }
    sliderUsed = 0;
}

void LaneLabelingTool::onSliderMoved(qint64 position) {
    int frame = position * frameRate / 1000;
    QString currentTime = Utils::Pos2Time(position);

    ui->frame->setText(QString::number(frame));
    ui->time->setText(currentTime);
    if (editPressed || firstFramePressed || lastFramePressed) {
        return;
    }
    for (const QStringList& i : csvData) {
        if (frame >= i[0].toInt() && frame <= i[1].toInt()) {
            ui->firstFrameValue->setText(i[0]);
            ui->trueStartTimeValue->setText(i[4]);
            ui->lastFrameValue->setText(i[1]);
            ui->trueEndTimeValue->setText(i[5]);
            ui->laneCountValue->setText(i[6]);
            ui->laneNumValue->setText(i[7]);
            return;
        }
    }
    ui->firstFrameValue->setText("");
    ui->trueStartTimeValue->setText("");
    ui->lastFrameValue->setText("");
    ui->trueEndTimeValue->setText("");
    ui->laneCountValue->setText("");
    ui->laneNumValue->setText("");
}

void LaneLabelingTool::updateTime() {
    if (videoStatus == VideoStatus::UNLOADED || videoStatus == VideoStatus::STOPED) {
        return;
    }
    if (firstFramePressed || lastFramePressed || editPressed) {
        buttonVisible(true, false, false, true, true);
    }
    else {
        int frame = player->position() * frameRate / 1000;
        for (const QStringList& i : csvData) {
            if (frame >= i[0].toInt() && frame <= i[1].toInt()) {
                buttonVisible(false, true, true, false, false);
                return;
            }
        }
        buttonVisible(true, false, false, false, false);
    }
}

void LaneLabelingTool::editFirstFrame() {
    if (player->playbackState() == QMediaPlayer::PlayingState) {
        player->pause();
        ui->playPauseButton->setIcon(Utils::iconPlay);
    }
    firstFramePressed = true;
    ui->editStatusValue->setText("新增中...");
    qint64 position = player->position();
    QImage image = decoder.pos2Image(position).copy(getTimeUi->graphicsView->timePos.toRect());
    QString time = tesseracter.image2Text(image);
    data[0] = QString::number(int(position * frameRate / 1000));
    data[2] = Utils::Pos2Time(position);
    data[4] = time;
    ui->firstFrameValue->setText(data[0]);
    ui->trueStartTimeValue->setText(data[4]);
}

void LaneLabelingTool::editLastFrame() {
    if (player->playbackState() == QMediaPlayer::PlayingState) {
        player->pause();
        ui->playPauseButton->setIcon(Utils::iconPlay);
    }
    lastFramePressed = true;
    ui->editStatusValue->setText("新增中...");
    qint64 position = player->position();
    QImage image = decoder.pos2Image(position).copy(getTimeUi->graphicsView->timePos.toRect());
    QString time = tesseracter.image2Text(image);
    data[1] = QString::number(int(position * frameRate / 1000));
    data[3] = Utils::Pos2Time(position);
    data[5] = time;
    ui->lastFrameValue->setText(data[1]);
    ui->trueEndTimeValue->setText(data[5]);
}

void LaneLabelingTool::saveInfo() {
    if (!editPressed && !lastFramePressed && !firstFramePressed) {
        QMessageBox::warning(nullptr, "Wraning", "please use the setFrame or edit button first.");
        return;
    }
    data[0] = ui->firstFrameValue->text();
    data[1] = ui->lastFrameValue->text();
    data[4] = ui->trueStartTimeValue->text();
    data[5] = ui->trueEndTimeValue->text();

    QTime trueStartTime = QTime::fromString(data[4], "hh:mm:ss");
    QTime trueEndTime = QTime::fromString(data[5], "hh:mm:ss");
    if (!trueStartTime.isValid() || !trueEndTime.isValid()) {
        QMessageBox::warning(nullptr, "Wraning", "true time message error，please try again.");
        return;
    }
    bool isFFrameNum = true;
    bool isLFrameNum = true;
    data[0].toInt(&isFFrameNum);
    data[1].toInt(&isLFrameNum);

    if (!isFFrameNum ||
        !isLFrameNum ||
        data[0].toInt() < 0 ||
        data[0].toInt() >= frameCount ||
        data[1].toInt() <= data[0].toInt() ||
        data[1].toInt() <= 0 ||
        data[1].toInt() > frameCount)
    {
        QMessageBox::warning(nullptr, "Wraning", "frame message error，please try again.");
        return;
    }

    data[6] = ui->laneCountValue->text();
    data[7] = ui->laneNumValue->text();
    data[2] = Utils::Pos2Time((data[0].toDouble() / frameRate)* 1000);
    data[3] = Utils::Pos2Time((data[1].toDouble() / frameRate) * 1000);
    bool islaneCount = true;
    bool islaneNum = true;
    data[6].toInt(&islaneCount);
    data[7].toInt(&islaneNum);

    if (data[6].isEmpty()) {
        if (data[7].isEmpty() || !islaneNum) {
            QMessageBox::warning(nullptr, "Wraning", "lane message error，please try again.");
            return;
        }
    }
    else {
        if (data[7].isEmpty() ||
            !islaneCount ||
            !islaneNum ||
            data[6].toInt() <= data[7].toInt()) {
            QMessageBox::warning(nullptr, "Wraning", "lane message error，please try again.");
            return;
        }
    }

    Utils::DataProcessing(csvData, data);

    QFile file(this->csvFilePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QMessageBox::critical(nullptr, "Error", QString("Cannot open file: %1").arg(this->csvFilePath));
        return;
    }
    QTextStream out(&file);

    out << DATA_HEADING;
    for (auto row : csvData) {
        out << row.join(",") << "\n";
    }
    file.close();

    if (player->playbackState() == QMediaPlayer::PausedState) {
        player->play();
        ui->playPauseButton->setIcon(Utils::iconPause);
    }
    ui->editStatusValue->setText("无");
    firstFramePressed = false;
    lastFramePressed = false;
    editPressed = false;
}

void LaneLabelingTool::editModel() {
    if (player->playbackState() == QMediaPlayer::PlayingState) {
        player->pause();
        ui->playPauseButton->setIcon(Utils::iconPlay);
    }
    editPressed = true;
    ui->editStatusValue->setText("修改中...");
}

void LaneLabelingTool::cancelEdit() {
    firstFramePressed = false;
    lastFramePressed = false;
    editPressed = false;
    if (player->playbackState() == QMediaPlayer::PausedState) {
        player->play();
        ui->playPauseButton->setIcon(Utils::iconPause);
    }
    ui->editStatusValue->setText("无");
}

void LaneLabelingTool::deleteMsg() {
    if (player->playbackState() == QMediaPlayer::PlayingState) {
        player->pause();
        ui->playPauseButton->setIcon(Utils::iconPlay);
    }
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "确认删除", "确定要删除当前帧区间车道信息吗？",
        QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        qint64 position = player->position();
        int frame = int(position * frameRate / 1000);
        csvData.erase(std::remove_if(csvData.begin(), csvData.end(),
            [frame](const QStringList& list) {
                return (list[0].toInt() <= frame && frame <= list[1].toInt());
            }),
            csvData.end());
        QFile file(this->csvFilePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
            QMessageBox::critical(nullptr, "Error", QString("Cannot open file: %1").arg(this->csvFilePath));
            return;
        }
        QTextStream out(&file);

        out << DATA_HEADING;
        for (auto row : csvData) {
            out << row.join(",") << "\n";
        }
        file.close();
    }
    if (player->playbackState() == QMediaPlayer::PausedState) {
        player->play();
        ui->playPauseButton->setIcon(Utils::iconPause);
    }
}

void LaneLabelingTool::getTimePos() {
    getTimeUi->videoTimeValue->setText("00:00:00");
    getTimeUi->graphicsView->setImage(frame0Image);
    getTimeUi->graphicsView->show();
    getTimeWindow->show();
}

void LaneLabelingTool::getTime() {
    QImage image = frame0Image.copy(getTimeUi->graphicsView->timePos.toRect());
    QString time = tesseracter.image2Text(image);
    if (!time.isEmpty()) {
        getTimeUi->videoTimeValue->setText(time);
    }
}

void LaneLabelingTool::mediaStatusChanged(QMediaPlayer::MediaStatus status) {
    qint64 duration = 0;
    switch (status)
    {
    case QMediaPlayer::NoMedia:
        break;
    case QMediaPlayer::LoadingMedia:
        break;
    case QMediaPlayer::LoadedMedia:
        duration = player->duration();
        frameRate = (player->metaData().value(QMediaMetaData::VideoFrameRate)).toDouble();
        frameCount = duration * frameRate / 1000;
        ui->frameNum->setText(QString("帧:%1/").arg(frameCount));
        ui->videoFullTime->setText(Utils::Pos2Time(duration));
        ui->playCtrSlider->setRange(0, duration);
        videoStatus = VideoStatus::LOADED;
        if (!videoLoaded) {
            player->setPosition(0);
            player->pause();
            videoLoaded = true;
        }
        break;
    case QMediaPlayer::StalledMedia:
        break;
    case QMediaPlayer::BufferingMedia:
        break;
    case QMediaPlayer::BufferedMedia:
        videoStatus = VideoStatus::PLAYING;
        break;
    case QMediaPlayer::EndOfMedia:
        ui->playPauseButton->setIcon(Utils::iconPlay);
        videoStatus = VideoStatus::STOPED;
        buttonVisible(false, false, false, false, false);
        break;
    case QMediaPlayer::InvalidMedia:
        break;
    default:
        break;
    }
}
