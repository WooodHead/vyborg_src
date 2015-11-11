#ifndef MAPPERDELEGATE_H
#define MAPPERDELEGATE_H

#include <QStyledItemDelegate>

class MapperDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    MapperDelegate(QObject *parent = 0);
    
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
};

#endif // MAPPERDELEGATE_H
