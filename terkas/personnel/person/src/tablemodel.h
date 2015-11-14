#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QSqlTableModel>

class TableModel : public QSqlTableModel
{
    Q_OBJECT

public:
    TableModel(QObject *parent = 0, QSqlDatabase db = QSqlDatabase());

    QVariant data(const QModelIndex &idx, int role) const;
//    bool setData(const QModelIndex &index, const QVariant &value, int role);
};

#endif // TABLEMODEL_H
