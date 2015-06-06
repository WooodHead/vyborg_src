#include <QApplication>

#include "declarations.h"
#include <vyborg_connection.h>

#include "maindialog.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    if (!openConnection())
        return -1;

    MainDialog dialog;
    dialog.setTitle(QObject::trUtf8("Количество обслуженных ВС филиалом \"МЦ АУВД\" ФГУП \"Госкорпорация по ОрВД\" в МЗ ЕС ОрВД"));
    dialog.showMaximized();
    
    app.exec();

    if (!closeConnection())
        return -1;

    return 0;
}
