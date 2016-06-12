#include <QDate>

#include <vyborg.h>

#include "declarations.h"
#include "tablemodel.h"

TableModel::TableModel(QObject *parent, QSqlDatabase db)
    : QSqlTableModel(parent, db)
{
    setEditStrategy(QSqlTableModel::OnManualSubmit);
}

QVariant TableModel::data(const QModelIndex &idx, int role) const
{
    if (!idx.isValid())
        return QVariant();

//    if (role == Qt::DisplayRole)
//    {
//        switch (idx.column()) {
//        case month_monthyear: {
//            QString strData = QSqlTableModel::data(idx, Qt::DisplayRole).toString();
//            QDate dateData = QDate::fromString(strData, "yyyy-MM-dd");
//            return dateData.toString(QString("yyyy MMMM"));
//            break;
//        }
//        }
//    }

    return QSqlTableModel::data(idx, role);
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal)
    {
        if (section >= columnCount())
            return QVariant();

        if (role == Qt::DisplayRole) {
            switch (section) {
            case month_ct_year:
                return QString("Год");
                break;
            case month_ct_jan:
                return QString("Январь");
                break;
            case month_ct_feb:
                return QString("Февраль");
                break;
            case month_ct_mar:
                return QString("Март");
                break;
            case month_ct_apr:
                return QString("Апрель");
                break;
            case month_ct_may:
                return QString("Май");
                break;
            case month_ct_jun:
                return QString("Июнь");
                break;
            case month_ct_jul:
                return QString("Июль");
                break;
            case month_ct_aug:
                return QString("Август");
                break;
            case month_ct_sep:
                return QString("Сентябрь");
                break;
            case month_ct_oct:
                return QString("Октябрь");
                break;
            case month_ct_nov:
                return QString("Ноябрь");
                break;
            case month_ct_dec:
                return QString("Декабрь");
                break;
            }
        }
    }
    else if (orientation == Qt::Vertical)
    {
        return QVariant();
    }

    return QSqlTableModel::headerData(section, orientation, role);
}
