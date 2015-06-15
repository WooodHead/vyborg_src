#include "dialog.h"
#include <QApplication>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setUserName("postgres");
    db.setPassword("monrepo");
    db.setDatabaseName("terkas");
    db.open();

    Dialog dialog;
    dialog.showMaximized();

    return app.exec();
}
