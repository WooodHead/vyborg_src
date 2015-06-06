#ifndef TABLEVIEWDELEGATE_H
#define TABLEVIEWDELEGATE_H

#include <QStyledItemDelegate>


/**********************************************************************************
 *
 * DateDelegate - show month and year
 *
 **********************************************************************************/

class VyborgYearMonthDay;

class DateDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    DateDelegate(QObject *parent = 0);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    mutable VyborgYearMonthDay *yearmonthday_;
};

#endif // TABLEVIEWDELEGATE_H
