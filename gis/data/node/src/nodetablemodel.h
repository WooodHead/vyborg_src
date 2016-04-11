#ifndef NODETABLEMODEL_H
#define NODETABLEMODEL_H

#include <QSqlTableModel>

class NodeTableModel : public QSqlTableModel
{
    Q_OBJECT

public:
    NodeTableModel(QObject *parent = Q_NULLPTR, QSqlDatabase db = QSqlDatabase());

    QVariant data(const QModelIndex &idx, int role = Qt::DisplayRole) const;
};

#endif // NODETABLEMODEL_H
