#ifndef HOURMODEL_H
#define HOURMODEL_H

#include <QSqlTableModel>

class HourModel : public QSqlTableModel
{
    Q_OBJECT

public:
    HourModel(QObject *parent = 0);

    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;

    int rowCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;
};

#endif // HOURMODEL_H
