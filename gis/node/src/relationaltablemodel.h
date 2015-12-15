#ifndef MYRELATIONALTABLEMODEL_H
#define MYRELATIONALTABLEMODEL_H

#include <QSqlRelationalTableModel>


class RelationalTableModel : public QSqlRelationalTableModel
{
    Q_OBJECT

public:
    explicit RelationalTableModel(QObject *parent = 0);

    QVariant data(const QModelIndex &item, int role) const;
    bool setData(const QModelIndex &item, const QVariant &value, int role);
};

#endif // MYRELATIONALTABLEMODEL_H
