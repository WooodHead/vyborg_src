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

    if (role == Qt::DisplayRole)
    {
        switch (idx.column()) {
        case month_monthyear: {
            QString strData = QSqlTableModel::data(idx, Qt::DisplayRole).toString();
            QDate dateData = QDate::fromString(strData, "yyyy-MM-dd");
            return dateData.toString(QString("yyyy MMMM"));
            break;
        }
        }
    }

    return QSqlTableModel::data(idx, role);
}
