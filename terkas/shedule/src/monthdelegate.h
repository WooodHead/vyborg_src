#ifndef MONTHDELEGATE_H
#define MONTHDELEGATE_H

#include <QStyledItemDelegate>
#include <QTableView>


class MonthDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit MonthDelegate(QObject *parent = 0);

    void setView(QTableView *view);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    QTableView *m_view;
};

#endif // MONTHDELEGATE_H
