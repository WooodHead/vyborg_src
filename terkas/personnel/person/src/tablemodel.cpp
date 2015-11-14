#include <QBrush>
#include <QDate>

#include "tablemodel.h"
#include "declarations.h"

#include <QDebug>

TableModel::TableModel(QObject *parent, QSqlDatabase db) :
    QSqlTableModel(parent, db)
{
}

QVariant TableModel::data(const QModelIndex &idx, int role) const
{
    if (!idx.isValid())
        return QVariant();

    int col = idx.column();
    if (col == person_birthday)
    {
        switch (role) {
        case Qt::ForegroundRole: return QBrush(Qt::blue);
        case Qt::DisplayRole: {
            QDate date = QSqlTableModel::data(idx, role).toDate();
            QString output = date.toString("dd MMMM yyyy");
            return output;
        }
        }
    }
    else if (col == person_icaolevel)
    {
        switch (role) {
        case Qt::ForegroundRole: {
            int level = QSqlTableModel::data(idx, Qt::DisplayRole).toInt();
            QBrush output;
            level == 5 ? output = QBrush(Qt::red)
                       : output = QBrush(Qt::blue);
            return output;
        }
        }
    }

    return QSqlTableModel::data(idx, role);
}

//bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
//{
//    QSqlTableModel::setData(index, value, role);
//}
