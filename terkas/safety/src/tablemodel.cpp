#include <QtSql>
#include <QGuiApplication>

#include "declarations.h"
#include "tablemodel.h"
#include "md_shiftnum.h"


TableModel::TableModel(QObject *parent) :
    QSqlRelationalTableModel(parent)
{
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (index.column() == safety_date) {
        switch (role) {
//        case Qt::DisplayRole: {
//            QDate value = QSqlTableModel::data(index, role).toDate();
//            if (value.isValid())
////                return value.toString("dd MMMM yyyy");
//                return value;
//            else
//                return QVariant();
//            break;
//        }
        case Qt::EditRole: {
            QDate value = QSqlTableModel::data(index, role).toDate();
            if (value.isValid())
                return value;
            else
                return QVariant();
            break;
        }
        case Qt::TextAlignmentRole: {
            int value = Qt::AlignHCenter | Qt::AlignVCenter;
            return value;
            break;
        }
//        default:
//            return QVariant();
        }
    } else if (index.column() == safety_shiftNum) {
        switch (role) {
        case Qt::DisplayRole: {
            int shiftNum = QSqlTableModel::data(index, role).toInt();
            if (shiftNum > 0)
                return shiftNum;
            else
                return QVariant();
        }
        }
    } else if (index.column() == safety_safetyClassification_id) {
        switch (role) {
        case Qt::ForegroundRole: {
                QString safetyClassification = QSqlTableModel::data(index, Qt::DisplayRole).toString();
                if (safetyClassification == "Авиационный инцидент")
                   return QBrush(QColor("red"));
                else
                    return QBrush(QColor("blue"));
        }
        case Qt::FontRole: {
                QString safetyClassification = QSqlTableModel::data(index, Qt::DisplayRole).toString();
                if (safetyClassification == "Авиационный инцидент") {
                    QFont font = QGuiApplication::font();
                    font.setWeight(QFont::Bold);
                    return font;
                }
        }
        }
    } else if (index.column() == safety_sector_id) {
        switch (role) {
        case Qt::DisplayRole: {
            QString sector = QSqlRelationalTableModel::data(index, Qt::DisplayRole).toString();
            if (sector == "Unknown")
                return QVariant();
            else
                return sector;
        }
        }
    } else if (index.column() == safety_sposTerkas_id ||
               index.column() == safety_sposAlpha_id ||
               index.column() == safety_TCAS1_id ||
               index.column() == safety_TCAS2_id) {
        switch (role) {
        case Qt::DisplayRole: {
            QString s = QSqlRelationalTableModel::data(index).toString();
            if (s == "Unknown")
                return QVariant();
            else
                return s;
        }
        case Qt::ForegroundRole: {
            if (index.column() == safety_sposTerkas_id ||
                index.column() == safety_sposAlpha_id) {
                QString s = QSqlRelationalTableModel::data(index).toString();
                if (s == "Жесткий СПОС")
                    return QBrush(QColor("red"));
            }
        }
        }

    }

    return QSqlRelationalTableModel::data(index, role);
}

void TableModel::search(int column, QRegExp rx, Qt::CaseSensitivity /*cs*/)
{
    QSqlRecord rec = record();
    QString name = rec.fieldName(column);
    QString filterStatement = name + " LIKE '%" + rx.pattern() + "%'";

    setFilter(filterStatement);
    select();
}

void TableModel::sort(int column, Qt::SortOrder order, Qt::CaseSensitivity /*cs*/)
{
    setSort(column, order);
    select();
}
