#ifndef TABLEVIEWDELEGATE_H
#define TABLEVIEWDELEGATE_H

#include <QStyledItemDelegate>

class TableViewDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    TableViewDelegate(QObject *parent = 0);
};

#endif // TABLEVIEWDELEGATE_H
