#ifndef PERSONTABLEDELEGATE_H
#define PERSONTABLEDELEGATE_H

#include <QStyledItemDelegate>

class PersonTableDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    PersonTableDelegate(QObject *parent = 0);


};

#endif // PERSONTABLEDELEGATE_H
