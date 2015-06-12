#include <QApplication>
#include <QtWidgets>

#include "declaration.h"
#include <vyborg_connection.h>

#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    if (openConnection() == false)
        return -1;

    Dialog dialog;
    dialog.showMaximized();

    return app.exec();
}
