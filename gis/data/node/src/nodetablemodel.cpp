#include <QSqlQuery>
#include <vyborg.h>

#include "declarations.h"
#include "nodetablemodel.h"

#include <QDebug>

NodeTableModel::NodeTableModel(QObject *parent, QSqlDatabase db)
    : QSqlTableModel(parent, db)
{

}

QVariant NodeTableModel::data(const QModelIndex &idx, int role) const
{
    if (!idx.isValid())
        return QVariant();

    int col = idx.column();

    if (col == node_geog && role == Qt::DisplayRole)
    {
        QString geog = QSqlTableModel::data(idx, role).toString();
        QString queryString = QString("SELECT St_AsLatLonText('%1'::geometry, 'D M S.SSS')").arg(geog);
        QString coord;
        QSqlQuery query(queryString);
        while (query.next()) { coord = query.value(0).toString(); }
        return coordRaw2readable(coord);
    }

    return QSqlTableModel::data(idx, role);
}
