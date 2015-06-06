#include <QApplication>

#include "ADwidget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ADwidget ADwid;
    ADwid.showMaximized();

    return a.exec();
}
