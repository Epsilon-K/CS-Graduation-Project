/********************************************************************************
** Form generated from reading UI file 'mt_visionui.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MT_VISIONUI_H
#define UI_MT_VISIONUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MT_VisionUI
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *devIdSB;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *clientIdSB;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_9;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *roiLSB;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpinBox *roiRSB;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSpinBox *roiTSB;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSpinBox *roiBSB;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *serverUrlLineEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QSpinBox *serverUpdateSB;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *sendCB;
    QCheckBox *randomIdCB;
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_9;
    QSpinBox *randBeginSB;
    QLabel *label_10;
    QSpinBox *randEndSB;
    QHBoxLayout *horizontalLayout_14;
    QCheckBox *useVideoCB;
    QLineEdit *videoNameLineEdit;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *saveBtn;
    QPushButton *runBtn;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QMainWindow *MT_VisionUI)
    {
        if (MT_VisionUI->objectName().isEmpty())
            MT_VisionUI->setObjectName(QString::fromUtf8("MT_VisionUI"));
        MT_VisionUI->resize(707, 414);
        centralWidget = new QWidget(MT_VisionUI);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        devIdSB = new QSpinBox(centralWidget);
        devIdSB->setObjectName(QString::fromUtf8("devIdSB"));

        horizontalLayout->addWidget(devIdSB);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        clientIdSB = new QSpinBox(centralWidget);
        clientIdSB->setObjectName(QString::fromUtf8("clientIdSB"));

        horizontalLayout_2->addWidget(clientIdSB);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        roiLSB = new QSpinBox(groupBox);
        roiLSB->setObjectName(QString::fromUtf8("roiLSB"));
        roiLSB->setMaximum(65000);
        roiLSB->setValue(200);

        horizontalLayout_3->addWidget(roiLSB);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        roiRSB = new QSpinBox(groupBox);
        roiRSB->setObjectName(QString::fromUtf8("roiRSB"));
        roiRSB->setMaximum(65000);
        roiRSB->setValue(1280);

        horizontalLayout_4->addWidget(roiRSB);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        roiTSB = new QSpinBox(groupBox);
        roiTSB->setObjectName(QString::fromUtf8("roiTSB"));
        roiTSB->setMaximum(65000);
        roiTSB->setValue(400);

        horizontalLayout_5->addWidget(roiTSB);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        roiBSB = new QSpinBox(groupBox);
        roiBSB->setObjectName(QString::fromUtf8("roiBSB"));
        roiBSB->setMaximum(65000);
        roiBSB->setValue(500);

        horizontalLayout_6->addWidget(roiBSB);


        verticalLayout->addLayout(horizontalLayout_6);


        horizontalLayout_9->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        serverUrlLineEdit = new QLineEdit(groupBox_2);
        serverUrlLineEdit->setObjectName(QString::fromUtf8("serverUrlLineEdit"));

        horizontalLayout_7->addWidget(serverUrlLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        serverUpdateSB = new QSpinBox(groupBox_2);
        serverUpdateSB->setObjectName(QString::fromUtf8("serverUpdateSB"));
        serverUpdateSB->setMaximum(65000);
        serverUpdateSB->setValue(30);

        horizontalLayout_8->addWidget(serverUpdateSB);


        verticalLayout_2->addLayout(horizontalLayout_8);


        horizontalLayout_9->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(2, 2, 2, 2);
        sendCB = new QCheckBox(groupBox_3);
        sendCB->setObjectName(QString::fromUtf8("sendCB"));
        sendCB->setChecked(true);

        verticalLayout_4->addWidget(sendCB);

        randomIdCB = new QCheckBox(groupBox_3);
        randomIdCB->setObjectName(QString::fromUtf8("randomIdCB"));
        randomIdCB->setChecked(true);

        verticalLayout_4->addWidget(randomIdCB);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_11->addWidget(label_9);

        randBeginSB = new QSpinBox(groupBox_3);
        randBeginSB->setObjectName(QString::fromUtf8("randBeginSB"));
        randBeginSB->setMaximum(65000);
        randBeginSB->setValue(0);

        horizontalLayout_11->addWidget(randBeginSB);


        horizontalLayout_12->addLayout(horizontalLayout_11);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_12->addWidget(label_10);

        randEndSB = new QSpinBox(groupBox_3);
        randEndSB->setObjectName(QString::fromUtf8("randEndSB"));
        randEndSB->setMaximum(65000);
        randEndSB->setValue(3);

        horizontalLayout_12->addWidget(randEndSB);


        horizontalLayout_13->addLayout(horizontalLayout_12);


        verticalLayout_4->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        useVideoCB = new QCheckBox(groupBox_3);
        useVideoCB->setObjectName(QString::fromUtf8("useVideoCB"));
        useVideoCB->setChecked(true);

        horizontalLayout_14->addWidget(useVideoCB);

        videoNameLineEdit = new QLineEdit(groupBox_3);
        videoNameLineEdit->setObjectName(QString::fromUtf8("videoNameLineEdit"));

        horizontalLayout_14->addWidget(videoNameLineEdit);


        verticalLayout_4->addLayout(horizontalLayout_14);


        horizontalLayout_9->addWidget(groupBox_3);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);

        saveBtn = new QPushButton(centralWidget);
        saveBtn->setObjectName(QString::fromUtf8("saveBtn"));

        horizontalLayout_10->addWidget(saveBtn);

        runBtn = new QPushButton(centralWidget);
        runBtn->setObjectName(QString::fromUtf8("runBtn"));

        horizontalLayout_10->addWidget(runBtn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_10);

        MT_VisionUI->setCentralWidget(centralWidget);

        retranslateUi(MT_VisionUI);

        QMetaObject::connectSlotsByName(MT_VisionUI);
    } // setupUi

    void retranslateUi(QMainWindow *MT_VisionUI)
    {
        MT_VisionUI->setWindowTitle(QCoreApplication::translate("MT_VisionUI", "MT_VisionUI", nullptr));
        label->setText(QCoreApplication::translate("MT_VisionUI", "Camera Device Id :", nullptr));
        label_2->setText(QCoreApplication::translate("MT_VisionUI", "Computer Vision Client Id :", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MT_VisionUI", "Region Of Interest", nullptr));
        label_3->setText(QCoreApplication::translate("MT_VisionUI", "left side :", nullptr));
        label_4->setText(QCoreApplication::translate("MT_VisionUI", "right side :", nullptr));
        label_5->setText(QCoreApplication::translate("MT_VisionUI", "top side :", nullptr));
        label_6->setText(QCoreApplication::translate("MT_VisionUI", "bottom side :", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MT_VisionUI", "Network", nullptr));
        label_7->setText(QCoreApplication::translate("MT_VisionUI", "Server URL : ", nullptr));
        serverUrlLineEdit->setText(QCoreApplication::translate("MT_VisionUI", "http://192.168.43.234/mtApi/api/", nullptr));
        label_8->setText(QCoreApplication::translate("MT_VisionUI", "Update Period (seconds) :", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MT_VisionUI", "Testing", nullptr));
        sendCB->setText(QCoreApplication::translate("MT_VisionUI", "Send to server", nullptr));
        randomIdCB->setText(QCoreApplication::translate("MT_VisionUI", "use random range for id", nullptr));
        label_9->setText(QCoreApplication::translate("MT_VisionUI", "from :", nullptr));
        label_10->setText(QCoreApplication::translate("MT_VisionUI", "To :", nullptr));
        useVideoCB->setText(QCoreApplication::translate("MT_VisionUI", "use Video", nullptr));
        videoNameLineEdit->setText(QCoreApplication::translate("MT_VisionUI", "test 1.mp4", nullptr));
        saveBtn->setText(QCoreApplication::translate("MT_VisionUI", "Save Settings", nullptr));
        runBtn->setText(QCoreApplication::translate("MT_VisionUI", "Run Program", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MT_VisionUI: public Ui_MT_VisionUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MT_VISIONUI_H
