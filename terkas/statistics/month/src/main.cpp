#include <QApplication>

#include "declarations.h"
#include <vyborg/connection.h>

#include "maindialog.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    if (!openConnection())
        return -1;

    QStringList columnNames;
    columnNames << QObject::trUtf8("Дата")
                << QObject::trUtf8("Внутренние рейсы")
                << QObject::trUtf8("Международные рейсы")
                << QObject::trUtf8("Транзитные рейсы")
                << QObject::trUtf8("Рейсы вне расписания (чартерные) рейсы")
                << QObject::trUtf8("Максимальная суточная интенсивность ВС секторов РДЦ рейсы")
                << QObject::trUtf8("Рейсы иностранных авиакомпаний");


    MainDialog dialog;
    dialog.setTitle(QObject::trUtf8("Количество ВС обслуженных филиалом \"МЦ АУВД\" ФГУП \"Госкорпорация по ОрВД\" в МЗ ЕС ОрВД"));
    dialog.showMaximized();

    
    app.exec();

    if (!closeConnection())
        return -1;

    return 0;
}
