#include <QDate>

#include "hourmodel.h"

HourModel::HourModel(QObject *parent)
    : QSqlTableModel(parent)
{

}

Qt::ItemFlags HourModel::flags(const QModelIndex &index) const
{
    int col = index.column();
    if (col == 3 || col == 4)
        return QSqlTableModel::flags(this->index(index.row(), index.column() - 2))
                | Qt::ItemIsSelectable
                | Qt::ItemIsEditable;

    return QSqlTableModel::flags(index);
}

int HourModel::rowCount(const QModelIndex &parent) const
{
    return QSqlTableModel::rowCount(parent);
}

int HourModel::columnCount(const QModelIndex &parent) const
{
    return QSqlTableModel::columnCount(parent) + 2; // one column for year, another column for date
}

QVariant HourModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole) {
        int col = index.column();
        switch (col) {
            case 0: {
                QDate date = QSqlTableModel::data(index, role).toDate();
                return date.toString("yyyy");
                break;
            }
            case 1: {
                QModelIndex indx = createIndex(index.row(), 0);
                QDate date = QSqlTableModel::data(indx, role).toDate();
                return date.toString("dd MMM");
                break;
            }
            case 2: {
                QModelIndex indx = createIndex(index.row(), 0);
                QTime time = QSqlTableModel::data(indx, role).toTime();
                return time.toString("hh:mm");
                break;
            }
            default: {
                QModelIndex indx = createIndex(index.row(), index.column() - 2);
                return QSqlTableModel::data(indx, role);
                break;
            }
        }
    }

    return QVariant();
}

QVariant HourModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QSqlTableModel::headerData(section, orientation, role);
    return QVariant();
}
