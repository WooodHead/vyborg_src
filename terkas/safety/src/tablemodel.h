#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QSqlRelationalTableModel>
#include <QRegExp>

class TableModel : public QSqlRelationalTableModel
{
    Q_OBJECT

public:
    TableModel(QObject *parent = 0);

    QVariant data(const QModelIndex &index, int role) const;

public slots:
    void search(int column, QRegExp rx, Qt::CaseSensitivity cs = Qt::CaseInsensitive);
    void sort(int column, Qt::SortOrder order, Qt::CaseSensitivity cs = Qt::CaseInsensitive);
};

#endif // TABLEMODEL_H
