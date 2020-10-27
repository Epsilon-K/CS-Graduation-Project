#include "mt_visionui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MT_VisionUI w;
    w.show();

    return a.exec();
}
