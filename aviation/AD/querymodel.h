#ifndef QUERYMODEL_H
#define QUERYMODEL_H

#include <QSqlQueryModel>


class QueryModel : public QSqlQueryModel
{
    Q_OBJECT

public:
    explicit QueryModel(QObject *parent = 0);

//    bool select();

    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant data(const QModelIndex &item, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &item, const QVariant &value, int role);
    int columnCount(const QModelIndex &parent) const;

//    void setSort(int column, Qt::SortOrder order);
    void sort(int column, Qt::SortOrder order);

private:
    void refresh(const QString &query);

    QString m_query;
};

#endif // QUERYMODEL_H
