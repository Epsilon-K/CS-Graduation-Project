#ifndef MT_VISIONUI_H
#define MT_VISIONUI_H

#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDir>

namespace Ui {
class MT_VisionUI;
}

class MT_VisionUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit MT_VisionUI(QWidget *parent = nullptr);
    ~MT_VisionUI();

private slots:
    void on_saveBtn_clicked();

    void on_runBtn_clicked();

private:
    Ui::MT_VisionUI *ui;
};

#endif // MT_VISIONUI_H
