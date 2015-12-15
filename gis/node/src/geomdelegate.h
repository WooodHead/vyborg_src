#ifndef GEOMDELEGATE_H
#define GEOMDELEGATE_H

#include <QItemDelegate>


class GeomDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    explicit GeomDelegate(QObject *parent = 0);
};

#endif // GEOMDELEGATE_H
