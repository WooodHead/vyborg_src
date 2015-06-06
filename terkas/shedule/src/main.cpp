#include <QApplication>

#include "declarations.h"
#include <vyborg/connection.h>

#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    if (!openConnection()) {
        return -1;
    }

    MainWindow w;
    w.showMaximized();
    w.show();

    if (!closeConnection()) {
        return -1;
    }


    return a.exec();
}
