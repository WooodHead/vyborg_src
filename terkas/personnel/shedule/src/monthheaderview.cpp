#include <QInputEvent>
#include <QMenu>

#include "monthheaderview.h"
#include "personpopupmenu.h"


MonthHeaderView::MonthHeaderView(Qt::Orientation orientation, QWidget *parent)
    : QHeaderView(orientation, parent)
{
}

void MonthHeaderView::mousePressEvent(QMouseEvent *event)
{
    if (!event) {
        return;
    }

    if (event->button() == Qt::RightButton) {
        PersonPopupMenu *personPopupMenu = new PersonPopupMenu(this);
        int index = logicalIndexAt(event->pos());
        int personId = model()->headerData(index, Qt::Vertical, Qt::EditRole).toInt();
        personPopupMenu->setPersonId(personId);
        personPopupMenu->popup(event->globalPos());
    } else {
        QHeaderView::mousePressEvent(event);
    }
}
