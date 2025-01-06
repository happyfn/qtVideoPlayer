#ifndef LANE_LANEBLING_TOOL_H
#define LANE_LANEBLING_TOOL_H

#include "ui_LaneLabelingTool.h"
#include "ui_getTimePos.h"
#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QTimer>
#include <QRect>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include "utils.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class LaneLabelingTool;
    class getTimePos;
}
QT_END_NAMESPACE

enum VideoStatus
{
    UNLOADED = -1,
    LOADED = 0,
    PLAYING = 1,
    STOPED = 2,
};

class LaneLabelingTool : public QWidget {
    Q_OBJECT

public:
    LaneLabelingTool(QWidget* parent = nullptr);
    ~LaneLabelingTool();

private slots:
    //button control
    void reSetButton(bool needOpen);
    void buttonVisible(bool editFrame, bool edit, bool deleteMsg, bool cancelEidt, bool save);
    void openFile();
    void playPause();
    void stopVideo();
    void changeFrame();
    void onNextFramePressed();
    void onPrevFramePressed();
    void onFrameReleased();
    void editFirstFrame();
    void editLastFrame();
    void saveInfo();
    void editModel();
    void cancelEdit();
    void deleteMsg();
    void getTimePos();
    void getTime();

    //Playing control
    void onSliderPressed();
    void onSliderReleased();
    void onSliderMoved(qint64 postion);
    void updateTime();
    void updatePosition(qint64 position);
    void mediaStatusChanged(QMediaPlayer::MediaStatus status);

private:
    Ui::LaneLabelingTool* ui;   //主界面实现，LaneLabelingTool.ui编译所得
    Ui::getTimePos* getTimeUi;  //获取时间区域界面实现.ui编译所得
    QWidget* getTimeWindow;     //获取时间区域窗口
    QImage frame0Image;         //保存首帧图片
    QTimer* timer;              //定时器，更新各项ui信息显示
    QTimer* skipFrameTimer;     //定时器，长按上一帧下一帧跳转触发

    int sliderUsed{0};                  //进度条状态，0:未使用;1:暂停时拖动;2:播放时拖动
    VideoStatus videoStatus{UNLOADED};  //视频状态
    double frameRate{0};                //视频帧率
    int frameCount{0};                  //视频帧数
    QVariant resolution{};              //视频分辨率
    QMediaPlayer* player;               //播放器

    bool videoLoaded{false};        //视频是否已加载
    bool firstFramePressed;         //是否点击设置首帧
    bool lastFramePressed;          //是否点击设置尾帧
    bool editPressed;               //是否点击编辑
    bool isNextFrame{false};        //是否下一帧
    QString csvFilePath{};          //标注信息文件路径
    QStringList data;               //一次标注的数据
    QVector<QStringList> csvData{}; //标注信息保存，减少io调用

    FFmpegDecoder decoder;      //ffmpeg实例， 获取视频frame并转成QImage
    OcrEngine tesseracter;      //tesseract实例，转QImage为QString
};

#endif // MAINWINDOW_H
