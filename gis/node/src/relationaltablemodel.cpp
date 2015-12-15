#include <QtWidgets>

#include "relationaltablemodel.h"
#include "declarations.h"


RelationalTableModel::RelationalTableModel(QObject *parent) :
    QSqlRelationalTableModel(parent)
{
    setEditStrategy(QSqlTableModel::OnManualSubmit);
}

QVariant RelationalTableModel::data(const QModelIndex &item, int role) const
{
    if (item.column() == col_label) {
        switch (role) {
        case Qt::ForegroundRole: {
            int len = item.data().toString().length();
            if (len == 2)
                return QBrush(Qt::blue);
            else
                return QBrush(Qt::black);
            break;
        }
        case Qt::EditRole:
        case Qt::DisplayRole: {
            QString label = QSqlRelationalTableModel::data(item, role).toString();
            if (label == "")
                return QString(trUtf8("г.т."));
            else
                return label;
        }
        case Qt::FontRole: {
            int len = item.data().toString().length();
            if (len == 2) {
                QFont font;
                font.setBold(true);
                return font;
            }
        }
        }
    } else if (item.column() == col_name) {
        switch (role) {
        case Qt::ForegroundRole:
            return QBrush(Qt::blue);
            break;
        }
    }

    return QSqlRelationalTableModel::data(item, role);
}

#include <QDebug>
bool RelationalTableModel::setData(const QModelIndex &item, const QVariant &value, int role)
{
    if (!item.isValid())
        return false;

    if (item.column() == col_label)
        if (QVariant(value).toString() == "г.т.")
            return QSqlRelationalTableModel::setData(item, QVariant(), role);

    return QSqlRelationalTableModel::setData(item, value, role);
}
