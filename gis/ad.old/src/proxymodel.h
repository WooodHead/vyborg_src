#ifndef PROXYMODEL_H
#define PROXYMODEL_H

#include <QSortFilterProxyModel>


class ProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    ProxyModel(QObject *parent = 0);

//    QVariant data(const QModelIndex &index, int role) const;
//    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

//    virtual bool submit();
//    void sort(int column, Qt::SortOrder order);


public slots:
//    bool submitChanges();
};

#endif // PROXYMODEL_H
