#ifndef PERSONMODELDELEGATE_H
#define PERSONMODELDELEGATE_H

#include <QStyledItemDelegate>


class PersonModelDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit PersonModelDelegate(QObject *parent = 0);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // PERSONMODELDELEGATE_H
