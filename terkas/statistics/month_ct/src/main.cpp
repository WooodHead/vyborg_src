#include <QApplication>

// The order of the include for following files is IMPORTANT
#include "declarations.h"
#include <vyborg/connection.h>

#include "maindialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    if (!openConnection())
        return -1;

    MainDialog mainDialog;
    mainDialog.setTitle("Общее количество обслуженных ВС всеми секторами РДЦ \"МЦ АУВД\" "
                        "ФГУП \"Госкорпорация по ОрВД\" в МЗ ЕС ОрВД");
    mainDialog.showMaximized();

    app.exec();

    if (!closeConnection())
        return -1;

    return 0;
}
