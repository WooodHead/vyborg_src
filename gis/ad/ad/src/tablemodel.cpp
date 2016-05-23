#include "tablemodel.h"
#include "declarations.h"

#include <QDebug>

TableModel::TableModel(QObject *parent, QSqlDatabase db)
    : QSqlTableModel(parent, db)
{
    setEditStrategy(QSqlTableModel::OnManualSubmit);
}

QVariant TableModel::data(const QModelIndex &idx, int role) const
{
    if (!idx.isValid())
        return QVariant();

    int col = idx.column();
    if (col == ad_opr) {
        switch (role) {
        case Qt::DisplayRole:
            return QString();
            break;
        case Qt::CheckStateRole:
                bool check = QSqlTableModel::data(idx, Qt::DisplayRole).toBool();
                if (check == true)
                    return Qt::Checked;
                else
                    return Qt::Unchecked;
            break;
        }
    }

    return QSqlTableModel::data(idx, role);
}
