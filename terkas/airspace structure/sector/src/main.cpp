#include <QApplication>
#include <QtWidgets>

#include "declaration.h"
#include <vyborg_connection.h>

#include "maindialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    if (openConnection() == false)
        return -1;

    MainDialog dialog;
    dialog.setTitle("Сектора РДЦ МЦ АУВД");
    dialog.showMaximized();

    return app.exec();
}
