#include <QApplication>

#include "declarations.h"
#include <vyborg/connection.h>
#include "maindialog.h"

int main(int argc, char *argv[])
{
    if (!openConnection())
        return -1;

    QApplication a(argc, argv);

    MainDialog dialog;
    dialog.setTitle(QObject::trUtf8("Нормативы пропускной способности"));
    dialog.showMaximized();

    a.exec();

    if (!closeConnection())
        return -1;

    return 0;
}
