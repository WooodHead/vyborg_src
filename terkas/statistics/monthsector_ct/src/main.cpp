#include <QApplication>

#include "declarations.h"
#include <vyborg/connection.h>

#include "dialog.h"

int main(int argc, char *argv[])
{
    if (!openConnection())
        return -1;

    QApplication app(argc, argv);

    Dialog dialog;
    dialog.showMaximized();

    app.exec();

    if (!closeConnection())
        return -1;

    return 0;
}
