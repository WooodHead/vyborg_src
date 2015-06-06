#ifndef MONTHHEADERVIEW_H
#define MONTHHEADERVIEW_H

#include <QHeaderView>


class MonthHeaderView : public QHeaderView
{
    Q_OBJECT

public:
    explicit MonthHeaderView(Qt::Orientation orientation, QWidget *parent = 0);

public slots:
    void mousePressEvent(QMouseEvent *event);
};

#endif // MONTHHEADERVIEW_H
