#include <QtSql>

#include "tablemodel.h"

TableModel::TableModel(QObject *parent, QSqlDatabase db)
    : QSqlRelationalTableModel(parent, db)
{
}

QVariant TableModel::data(const QModelIndex &item, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (item.column() == 0) {
            int pid = QSqlRelationalTableModel::data(item).toInt();
            QSqlQuery query;
            query.prepare("SELECT * FROM person.vw_personwidget "
                          "WHERE pid=:id");
            query.bindValue(":id", pid);
            query.exec();
            query.next();
            QString fullname = query.value("fullname").toString();
            return fullname;
        }
    }

    return QSqlRelationalTableModel::data(item, role);
}
