#include <QApplication>
#include <QtSql>

#include "dialog.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setUserName("postgres");
    db.setPassword("monrepo");
    db.setDatabaseName("terkas");
    db.open();

    MainWindow mainWindow;
    mainWindow.showMaximized();

    return app.exec();
}
