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
