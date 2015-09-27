#include <QApplication>

#include "declarations.h"
#include <vyborg/connection.h>

//#include "mainwindow.h"
#include "maindialog.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    if (!openConnection()) {
        return -1;
    }

//    MainWindow win;
//    win.showMaximized();
//    win.show();

    MainDialog dlg;
    dlg.showMaximized();

    app.exec();

    if (!closeConnection()) {
        return -1;
    }

    return 0;
}

