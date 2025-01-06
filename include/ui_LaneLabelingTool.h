/********************************************************************************
** Form generated from reading UI file 'LaneLabelingTool.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LANELABELINGTOOL_H
#define UI_LANELABELINGTOOL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <myButton.h>

QT_BEGIN_NAMESPACE

class Ui_LaneLabelingTool
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *videoMuneLayout;
    myButton *openButton;
    QSpacerItem *spacer1_1;
    QLabel *fileNameLabel;
    QLabel *editStatusKey;
    QLabel *editStatusValue;
    QSpacerItem *horizontalSpacer_2;
    myButton *getTimePosButton;
    QVideoWidget *videoWidget;
    QHBoxLayout *videoMsgLayout;
    QLabel *time;
    QSlider *playCtrSlider;
    QLabel *videoFullTime;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *frameNum;
    QLabel *frame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *firstTureTimeKey;
    QLineEdit *firstFrameValue;
    QLineEdit *trueStartTimeValue;
    QLabel *lastTrueTimeKey;
    QLineEdit *lastFrameValue;
    QLineEdit *trueEndTimeValue;
    QLabel *laneCountKey;
    QLineEdit *laneCountValue;
    QLabel *laneNumKey;
    QLineEdit *laneNumValue;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    myButton *prevFrameButton;
    myButton *playPauseButton;
    myButton *nextFrameButton;
    myButton *stopButton;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    myButton *frameBegineButton;
    QSpacerItem *horizontalSpacer;
    myButton *frameEndButton;
    QSpacerItem *horizontalSpacer_4;
    myButton *eidtButton;
    QSpacerItem *horizontalSpacer_5;
    myButton *deleteButton;
    QSpacerItem *horizontalSpacer_6;
    myButton *cancelButton;
    QSpacerItem *horizontalSpacer_7;
    myButton *saveButton;

    void setupUi(QWidget *LaneLabelingTool)
    {
        if (LaneLabelingTool->objectName().isEmpty())
            LaneLabelingTool->setObjectName("LaneLabelingTool");
        LaneLabelingTool->resize(912, 636);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LaneLabelingTool->sizePolicy().hasHeightForWidth());
        LaneLabelingTool->setSizePolicy(sizePolicy);
        LaneLabelingTool->setMinimumSize(QSize(0, 0));
        LaneLabelingTool->setTabletTracking(false);
        LaneLabelingTool->setStyleSheet(QString::fromUtf8("background-color: rgb(40, 40, 40);\n"
"color: rgb(210, 210, 210);\n"
"font: 700 9pt \"Microsoft YaHei\";"));
        verticalLayout_2 = new QVBoxLayout(LaneLabelingTool);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName("verticalLayout");
        videoMuneLayout = new QHBoxLayout();
        videoMuneLayout->setSpacing(0);
        videoMuneLayout->setObjectName("videoMuneLayout");
        videoMuneLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        openButton = new myButton(LaneLabelingTool);
        openButton->setObjectName("openButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(openButton->sizePolicy().hasHeightForWidth());
        openButton->setSizePolicy(sizePolicy1);
        openButton->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        openButton->setStyleSheet(QString::fromUtf8("border-top:2px solid  #6B6B6B;\n"
"background-color: rgb(51, 51, 51);\n"
"border-radius:5px;"));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::FolderNew));
        openButton->setIcon(icon);

        videoMuneLayout->addWidget(openButton);

        spacer1_1 = new QSpacerItem(24, 24, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        videoMuneLayout->addItem(spacer1_1);

        fileNameLabel = new QLabel(LaneLabelingTool);
        fileNameLabel->setObjectName("fileNameLabel");
        sizePolicy1.setHeightForWidth(fileNameLabel->sizePolicy().hasHeightForWidth());
        fileNameLabel->setSizePolicy(sizePolicy1);
        fileNameLabel->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        fileNameLabel->setStyleSheet(QString::fromUtf8(""));

        videoMuneLayout->addWidget(fileNameLabel);

        editStatusKey = new QLabel(LaneLabelingTool);
        editStatusKey->setObjectName("editStatusKey");
        editStatusKey->setStyleSheet(QString::fromUtf8(""));

        videoMuneLayout->addWidget(editStatusKey);

        editStatusValue = new QLabel(LaneLabelingTool);
        editStatusValue->setObjectName("editStatusValue");
        editStatusValue->setStyleSheet(QString::fromUtf8(""));

        videoMuneLayout->addWidget(editStatusValue);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        videoMuneLayout->addItem(horizontalSpacer_2);

        getTimePosButton = new myButton(LaneLabelingTool);
        getTimePosButton->setObjectName("getTimePosButton");
        getTimePosButton->setStyleSheet(QString::fromUtf8("border-top:2px solid  #6B6B6B;\n"
"background-color: rgb(51, 51, 51);\n"
"border-radius:5px;"));

        videoMuneLayout->addWidget(getTimePosButton);

        videoMuneLayout->setStretch(2, 40);

        verticalLayout->addLayout(videoMuneLayout);

        videoWidget = new QVideoWidget(LaneLabelingTool);
        videoWidget->setObjectName("videoWidget");
        videoWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(videoWidget);

        videoMsgLayout = new QHBoxLayout();
        videoMsgLayout->setSpacing(0);
        videoMsgLayout->setObjectName("videoMsgLayout");
        time = new QLabel(LaneLabelingTool);
        time->setObjectName("time");
        sizePolicy1.setHeightForWidth(time->sizePolicy().hasHeightForWidth());
        time->setSizePolicy(sizePolicy1);
        time->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        time->setStyleSheet(QString::fromUtf8(""));

        videoMsgLayout->addWidget(time);

        playCtrSlider = new QSlider(LaneLabelingTool);
        playCtrSlider->setObjectName("playCtrSlider");
        sizePolicy1.setHeightForWidth(playCtrSlider->sizePolicy().hasHeightForWidth());
        playCtrSlider->setSizePolicy(sizePolicy1);
        playCtrSlider->setMaximumSize(QSize(16777215, 20));
        playCtrSlider->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        playCtrSlider->setOrientation(Qt::Orientation::Horizontal);

        videoMsgLayout->addWidget(playCtrSlider);

        videoFullTime = new QLabel(LaneLabelingTool);
        videoFullTime->setObjectName("videoFullTime");
        videoFullTime->setStyleSheet(QString::fromUtf8(""));

        videoMsgLayout->addWidget(videoFullTime);

        videoMsgLayout->setStretch(1, 20);

        verticalLayout->addLayout(videoMsgLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName("horizontalLayout");
        frameNum = new QLabel(LaneLabelingTool);
        frameNum->setObjectName("frameNum");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frameNum->sizePolicy().hasHeightForWidth());
        frameNum->setSizePolicy(sizePolicy2);
        frameNum->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(frameNum);

        frame = new QLabel(LaneLabelingTool);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy3);
        frame->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        frame->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(frame);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(-1, -1, 0, -1);
        firstTureTimeKey = new QLabel(LaneLabelingTool);
        firstTureTimeKey->setObjectName("firstTureTimeKey");
        sizePolicy.setHeightForWidth(firstTureTimeKey->sizePolicy().hasHeightForWidth());
        firstTureTimeKey->setSizePolicy(sizePolicy);
        firstTureTimeKey->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(firstTureTimeKey);

        firstFrameValue = new QLineEdit(LaneLabelingTool);
        firstFrameValue->setObjectName("firstFrameValue");
        sizePolicy.setHeightForWidth(firstFrameValue->sizePolicy().hasHeightForWidth());
        firstFrameValue->setSizePolicy(sizePolicy);
        firstFrameValue->setStyleSheet(QString::fromUtf8("	border: 1px solid #A0A0A0;\n"
"	border-radius: 3px; \n"
"	padding-left: 5px; \n"
"	background-color: #F2F2F2; \n"
"	color: #A0A0A0; \n"
"	selection-background-color: #A0A0A0;\n"
"	selection-color: #F2F2F2; \n"
"	font-size: 10pt; "));
        firstFrameValue->setReadOnly(true);

        horizontalLayout_2->addWidget(firstFrameValue);

        trueStartTimeValue = new QLineEdit(LaneLabelingTool);
        trueStartTimeValue->setObjectName("trueStartTimeValue");
        trueStartTimeValue->setStyleSheet(QString::fromUtf8("	border: 1px solid #A0A0A0;\n"
"	border-radius: 3px; \n"
"	padding-left: 5px; \n"
"	background-color: #F2F2F2; \n"
"	color: #A0A0A0; \n"
"	selection-background-color: #A0A0A0;\n"
"	selection-color: #F2F2F2; \n"
"	font-size: 10pt; "));

        horizontalLayout_2->addWidget(trueStartTimeValue);

        lastTrueTimeKey = new QLabel(LaneLabelingTool);
        lastTrueTimeKey->setObjectName("lastTrueTimeKey");
        sizePolicy.setHeightForWidth(lastTrueTimeKey->sizePolicy().hasHeightForWidth());
        lastTrueTimeKey->setSizePolicy(sizePolicy);
        lastTrueTimeKey->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(lastTrueTimeKey);

        lastFrameValue = new QLineEdit(LaneLabelingTool);
        lastFrameValue->setObjectName("lastFrameValue");
        sizePolicy.setHeightForWidth(lastFrameValue->sizePolicy().hasHeightForWidth());
        lastFrameValue->setSizePolicy(sizePolicy);
        lastFrameValue->setStyleSheet(QString::fromUtf8("	border: 1px solid #A0A0A0;\n"
"	border-radius: 3px; \n"
"	padding-left: 5px; \n"
"	background-color: #F2F2F2; \n"
"	color: #A0A0A0; \n"
"	selection-background-color: #A0A0A0;\n"
"	selection-color: #F2F2F2; \n"
"	font-size: 10pt; "));
        lastFrameValue->setReadOnly(true);

        horizontalLayout_2->addWidget(lastFrameValue);

        trueEndTimeValue = new QLineEdit(LaneLabelingTool);
        trueEndTimeValue->setObjectName("trueEndTimeValue");
        trueEndTimeValue->setStyleSheet(QString::fromUtf8("	border: 1px solid #A0A0A0;\n"
"	border-radius: 3px; \n"
"	padding-left: 5px; \n"
"	background-color: #F2F2F2; \n"
"	color: #A0A0A0; \n"
"	selection-background-color: #A0A0A0;\n"
"	selection-color: #F2F2F2; \n"
"	font-size: 10pt; "));

        horizontalLayout_2->addWidget(trueEndTimeValue);

        laneCountKey = new QLabel(LaneLabelingTool);
        laneCountKey->setObjectName("laneCountKey");
        sizePolicy.setHeightForWidth(laneCountKey->sizePolicy().hasHeightForWidth());
        laneCountKey->setSizePolicy(sizePolicy);
        laneCountKey->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(laneCountKey);

        laneCountValue = new QLineEdit(LaneLabelingTool);
        laneCountValue->setObjectName("laneCountValue");
        sizePolicy.setHeightForWidth(laneCountValue->sizePolicy().hasHeightForWidth());
        laneCountValue->setSizePolicy(sizePolicy);
        laneCountValue->setStyleSheet(QString::fromUtf8("	border: 1px solid #A0A0A0;\n"
"	border-radius: 3px; \n"
"	padding-left: 5px; \n"
"	background-color: #F2F2F2; \n"
"	color: #A0A0A0; \n"
"	selection-background-color: #A0A0A0;\n"
"	selection-color: #F2F2F2; \n"
"	font-size: 10pt; "));
        laneCountValue->setReadOnly(true);

        horizontalLayout_2->addWidget(laneCountValue);

        laneNumKey = new QLabel(LaneLabelingTool);
        laneNumKey->setObjectName("laneNumKey");
        sizePolicy.setHeightForWidth(laneNumKey->sizePolicy().hasHeightForWidth());
        laneNumKey->setSizePolicy(sizePolicy);
        laneNumKey->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(laneNumKey);

        laneNumValue = new QLineEdit(LaneLabelingTool);
        laneNumValue->setObjectName("laneNumValue");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(laneNumValue->sizePolicy().hasHeightForWidth());
        laneNumValue->setSizePolicy(sizePolicy4);
        laneNumValue->setStyleSheet(QString::fromUtf8("	border: 1px solid #A0A0A0;\n"
"	border-radius: 3px; \n"
"	padding-left: 5px; \n"
"	background-color: #F2F2F2; \n"
"	color: #A0A0A0; \n"
"	selection-background-color: #A0A0A0;\n"
"	selection-color: #F2F2F2; \n"
"	font-size: 10pt; "));
        laneNumValue->setReadOnly(true);

        horizontalLayout_2->addWidget(laneNumValue);

        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(4, 1);
        horizontalLayout_2->setStretch(7, 1);
        horizontalLayout_2->setStretch(9, 1);

        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 12);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        prevFrameButton = new myButton(LaneLabelingTool);
        prevFrameButton->setObjectName("prevFrameButton");
        sizePolicy3.setHeightForWidth(prevFrameButton->sizePolicy().hasHeightForWidth());
        prevFrameButton->setSizePolicy(sizePolicy3);
        prevFrameButton->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        prevFrameButton->setStyleSheet(QString::fromUtf8("border-top:2px solid  #6B6B6B;\n"
"background-color: rgb(51, 51, 51);\n"
"border-radius:5px;"));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::GoPrevious));
        prevFrameButton->setIcon(icon1);

        horizontalLayout_4->addWidget(prevFrameButton);

        playPauseButton = new myButton(LaneLabelingTool);
        playPauseButton->setObjectName("playPauseButton");
        sizePolicy3.setHeightForWidth(playPauseButton->sizePolicy().hasHeightForWidth());
        playPauseButton->setSizePolicy(sizePolicy3);
        playPauseButton->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        playPauseButton->setStyleSheet(QString::fromUtf8("border-top:2px solid  #6B6B6B;\n"
"background-color: rgb(51, 51, 51);\n"
"border-radius:5px;"));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackStart));
        playPauseButton->setIcon(icon2);

        horizontalLayout_4->addWidget(playPauseButton);

        nextFrameButton = new myButton(LaneLabelingTool);
        nextFrameButton->setObjectName("nextFrameButton");
        sizePolicy3.setHeightForWidth(nextFrameButton->sizePolicy().hasHeightForWidth());
        nextFrameButton->setSizePolicy(sizePolicy3);
        nextFrameButton->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        nextFrameButton->setStyleSheet(QString::fromUtf8("border-top:2px solid  #6B6B6B;\n"
"background-color: rgb(51, 51, 51);\n"
"border-radius:5px;"));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::GoNext));
        nextFrameButton->setIcon(icon3);

        horizontalLayout_4->addWidget(nextFrameButton);

        stopButton = new myButton(LaneLabelingTool);
        stopButton->setObjectName("stopButton");
        sizePolicy3.setHeightForWidth(stopButton->sizePolicy().hasHeightForWidth());
        stopButton->setSizePolicy(sizePolicy3);
        stopButton->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        stopButton->setStyleSheet(QString::fromUtf8("border-top:2px solid  #6B6B6B;\n"
"background-color: rgb(51, 51, 51);\n"
"border-radius:5px;"));
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackStop));
        stopButton->setIcon(icon4);

        horizontalLayout_4->addWidget(stopButton);


        horizontalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(12);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        frameBegineButton = new myButton(LaneLabelingTool);
        frameBegineButton->setObjectName("frameBegineButton");
        sizePolicy.setHeightForWidth(frameBegineButton->sizePolicy().hasHeightForWidth());
        frameBegineButton->setSizePolicy(sizePolicy);
        frameBegineButton->setStyleSheet(QString::fromUtf8("border-top:2px solid  #6B6B6B;\n"
"background-color: rgb(51, 51, 51);\n"
"border-radius:5px;"));

        horizontalLayout_5->addWidget(frameBegineButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        frameEndButton = new myButton(LaneLabelingTool);
        frameEndButton->setObjectName("frameEndButton");
        sizePolicy.setHeightForWidth(frameEndButton->sizePolicy().hasHeightForWidth());
        frameEndButton->setSizePolicy(sizePolicy);
        frameEndButton->setStyleSheet(QString::fromUtf8("border-top:2px solid  #6B6B6B;\n"
"background-color: rgb(51, 51, 51);\n"
"border-radius:5px;"));

        horizontalLayout_5->addWidget(frameEndButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        eidtButton = new myButton(LaneLabelingTool);
        eidtButton->setObjectName("eidtButton");
        sizePolicy.setHeightForWidth(eidtButton->sizePolicy().hasHeightForWidth());
        eidtButton->setSizePolicy(sizePolicy);
        eidtButton->setStyleSheet(QString::fromUtf8("border-top:2px solid  #6B6B6B;\n"
"background-color: rgb(51, 51, 51);\n"
"border-radius:5px;"));

        horizontalLayout_5->addWidget(eidtButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        deleteButton = new myButton(LaneLabelingTool);
        deleteButton->setObjectName("deleteButton");
        sizePolicy.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy);
        deleteButton->setStyleSheet(QString::fromUtf8("border-top:2px solid  #6B6B6B;\n"
"background-color: rgb(51, 51, 51);\n"
"border-radius:5px;"));

        horizontalLayout_5->addWidget(deleteButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        cancelButton = new myButton(LaneLabelingTool);
        cancelButton->setObjectName("cancelButton");
        sizePolicy.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy);
        cancelButton->setStyleSheet(QString::fromUtf8("border-top:2px solid  #6B6B6B;\n"
"background-color: rgb(51, 51, 51);\n"
"border-radius:5px;"));

        horizontalLayout_5->addWidget(cancelButton);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        saveButton = new myButton(LaneLabelingTool);
        saveButton->setObjectName("saveButton");
        sizePolicy.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy);
        saveButton->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        saveButton->setStyleSheet(QString::fromUtf8("border-top:2px solid  #6B6B6B;\n"
"background-color: rgb(51, 51, 51);\n"
"border-radius:5px;"));

        horizontalLayout_5->addWidget(saveButton);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 8);

        verticalLayout->addLayout(horizontalLayout_6);

        verticalLayout->setStretch(1, 50);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(LaneLabelingTool);

        QMetaObject::connectSlotsByName(LaneLabelingTool);
    } // setupUi

    void retranslateUi(QWidget *LaneLabelingTool)
    {
        LaneLabelingTool->setWindowTitle(QCoreApplication::translate("LaneLabelingTool", "LaneLabelingTool", nullptr));
        openButton->setText(QString());
        fileNameLabel->setText(QCoreApplication::translate("LaneLabelingTool", "\346\226\207\344\273\266\345\220\215: \346\227\240", nullptr));
        editStatusKey->setText(QCoreApplication::translate("LaneLabelingTool", "\347\274\226\350\276\221\347\212\266\346\200\201:", nullptr));
        editStatusValue->setText(QCoreApplication::translate("LaneLabelingTool", "\346\227\240", nullptr));
        getTimePosButton->setText(QCoreApplication::translate("LaneLabelingTool", "\346\210\252\345\217\226\346\227\266\351\227\264", nullptr));
        time->setText(QCoreApplication::translate("LaneLabelingTool", "00:00:00.000", nullptr));
        videoFullTime->setText(QCoreApplication::translate("LaneLabelingTool", "00:00:00.000", nullptr));
        frameNum->setText(QCoreApplication::translate("LaneLabelingTool", "\345\270\247:0/", nullptr));
        frame->setText(QCoreApplication::translate("LaneLabelingTool", "0", nullptr));
        firstTureTimeKey->setText(QCoreApplication::translate("LaneLabelingTool", "\351\246\226\345\270\247/\346\227\266\351\227\264:", nullptr));
        firstFrameValue->setText(QString());
        lastTrueTimeKey->setText(QCoreApplication::translate("LaneLabelingTool", "\345\260\276\345\270\247/\346\227\266\351\227\264:", nullptr));
        lastFrameValue->setText(QString());
        laneCountKey->setText(QCoreApplication::translate("LaneLabelingTool", "\350\275\246\351\201\223\346\225\260:", nullptr));
        laneCountValue->setText(QString());
        laneNumKey->setText(QCoreApplication::translate("LaneLabelingTool", "\346\211\200\345\234\250\350\275\246\351\201\223:", nullptr));
        laneNumValue->setText(QString());
        prevFrameButton->setText(QString());
        playPauseButton->setText(QString());
        nextFrameButton->setText(QString());
        stopButton->setText(QString());
        frameBegineButton->setText(QCoreApplication::translate("LaneLabelingTool", "\350\256\276\347\275\256\351\246\226\345\270\247", nullptr));
        frameEndButton->setText(QCoreApplication::translate("LaneLabelingTool", "\350\256\276\347\275\256\345\260\276\345\270\247", nullptr));
        eidtButton->setText(QCoreApplication::translate("LaneLabelingTool", "\344\277\256  \346\224\271", nullptr));
        deleteButton->setText(QCoreApplication::translate("LaneLabelingTool", "\345\210\240  \351\231\244", nullptr));
        cancelButton->setText(QCoreApplication::translate("LaneLabelingTool", "\345\217\226  \346\266\210", nullptr));
        saveButton->setText(QCoreApplication::translate("LaneLabelingTool", "\344\277\235  \345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LaneLabelingTool: public Ui_LaneLabelingTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LANELABELINGTOOL_H
