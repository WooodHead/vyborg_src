#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QSqlRelationalTableModel>


class TableModel : public QSqlRelationalTableModel
{
    Q_OBJECT

public:
    explicit TableModel(QObject *parent = 0);

    QVariant data(const QModelIndex &item, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
//    bool setData(const QModelIndex &item, const QVariant &value, int role);
    int columnCount(const QModelIndex &parent) const;

//    void sort(int column, Qt::SortOrder order);
};

#endif // TABLEMODEL_H
