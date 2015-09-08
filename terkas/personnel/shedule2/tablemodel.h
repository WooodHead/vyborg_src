#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QSqlRelationalTableModel>

class TableModel : public QSqlRelationalTableModel
{
    Q_OBJECT

public:
    TableModel(QObject *parent = 0, QSqlDatabase db = QSqlDatabase());

    QVariant data(const QModelIndex &item, int role) const;
};

#endif // TABLEMODEL_H
