/********************************************************************************
** Form generated from reading UI file 'getTimePos.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETTIMEPOS_H
#define UI_GETTIMEPOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <myButton.h>
#include "QDrawGraphicsView.h"

QT_BEGIN_NAMESPACE

class Ui_getTimePos
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QDrawGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout;
    myButton *getTimeButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *videoTimeKey;
    QLabel *videoTimeValue;

    void setupUi(QWidget *getTimePos)
    {
        if (getTimePos->objectName().isEmpty())
            getTimePos->setObjectName("getTimePos");
        getTimePos->resize(912, 573);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(getTimePos->sizePolicy().hasHeightForWidth());
        getTimePos->setSizePolicy(sizePolicy);
        getTimePos->setMinimumSize(QSize(0, 0));
        getTimePos->setTabletTracking(false);
        getTimePos->setStyleSheet(QString::fromUtf8("background-color: rgb(40, 40, 40);\n"
"font: 700 9pt \"Microsoft YaHei\";\n"
"color: rgb(210, 210, 210);"));
        verticalLayout_2 = new QVBoxLayout(getTimePos);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(getTimePos);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        verticalLayout->addWidget(label);

        graphicsView = new QDrawGraphicsView(getTimePos);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(graphicsView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        getTimeButton = new myButton(getTimePos);
        getTimeButton->setObjectName("getTimeButton");
        getTimeButton->setStyleSheet(QString::fromUtf8("border-top:2px solid  #6B6B6B;\n"
"background-color: rgb(51, 51, 51);\n"
"border-radius:5px;"));

        horizontalLayout->addWidget(getTimeButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        videoTimeKey = new QLabel(getTimePos);
        videoTimeKey->setObjectName("videoTimeKey");
        videoTimeKey->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(videoTimeKey);

        videoTimeValue = new QLabel(getTimePos);
        videoTimeValue->setObjectName("videoTimeValue");
        videoTimeValue->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(videoTimeValue);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(getTimePos);

        QMetaObject::connectSlotsByName(getTimePos);
    } // setupUi

    void retranslateUi(QWidget *getTimePos)
    {
        getTimePos->setWindowTitle(QCoreApplication::translate("getTimePos", "LaneLabelingTool", nullptr));
        label->setText(QCoreApplication::translate("getTimePos", "\350\257\267\345\234\250\345\261\217\345\271\225\344\270\212\347\233\264\346\216\245\351\274\240\346\240\207\347\202\271\345\207\273\346\210\252\345\217\226\346\227\266\351\227\264\345\214\272\345\237\237\357\274\214\347\202\271\345\207\273\345\267\246\344\270\213\350\247\222\346\214\211\351\222\256\351\252\214\350\257\201\346\230\257\345\220\246ocr\350\257\206\345\210\253\346\210\220\345\212\237\357\274\214\350\257\206\345\210\253\347\273\223\346\236\234\350\247\201\345\217\263\344\270\213\350\247\222", nullptr));
        getTimeButton->setText(QCoreApplication::translate("getTimePos", "\344\277\235\345\255\230\345\271\266\350\257\206\345\210\253", nullptr));
        videoTimeKey->setText(QCoreApplication::translate("getTimePos", "\350\247\206\351\242\221\346\227\266\351\227\264:", nullptr));
        videoTimeValue->setText(QCoreApplication::translate("getTimePos", "00:00:00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class getTimePos: public Ui_getTimePos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETTIMEPOS_H
