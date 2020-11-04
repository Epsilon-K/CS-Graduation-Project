#include "mt_visionui.h"
#include "ui_mt_visionui.h"

MT_VisionUI::MT_VisionUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MT_VisionUI)
{
    ui->setupUi(this);
}

MT_VisionUI::~MT_VisionUI()
{
    delete ui;
}

void MT_VisionUI::on_saveBtn_clicked()
{
    QFile file("settings.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "Error, Can't Open File!";
        return;
    }

    QTextStream out(&file);
    out << "camera device id: " << ui->devIdSB->value() << "\n";
    out << "client id: " << ui->clientIdSB->value() << "\n";
    out << "roi left: " << ui->roiLSB->value() << "\n";
    out << "roi right: " << ui->roiRSB->value() << "\n";
    out << "roi top: " << ui->roiTSB->value() << "\n";
    out << "roi bottom: " << ui->roiBSB->value() << "\n";
    out << "server url: " << ui->serverUrlLineEdit->text() << "\n";
    out << "server update: " << ui->serverUpdateSB->value() << "\n";
    out << "send to server: " << (ui->sendCB->isChecked() ? "true" : "false") << "\n";
    out << "random id: " << (ui->randomIdCB->isChecked() ? "true" : "false") << "\n";
    out << "random start: " << ui->randBeginSB->value() << "\n";
    out << "random end: " << ui->randEndSB->value() << "\n";
    out << "use video: " << (ui->useVideoCB->isChecked() ? "true" : "false") << "\n";
    out << "video path: " << ui->videoNameLineEdit->text() << "\n";
}

void MT_VisionUI::on_runBtn_clicked()
{
    QString cmd = "\"" + QDir::currentPath() + "/Traffic Counter.exe\"";
    qDebug() << cmd;
    system(cmd.toStdString().c_str());
}







