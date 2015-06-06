#include <QDate>
#include <vyborg/yearmonthday.h>

#include "tableviewdelegate.h"


/**********************************************************************************
 *
 * DateDelegate
 *
 **********************************************************************************/

DateDelegate::DateDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

void DateDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.isValid()) {
        QDate date = index.data().toDate();
        int day = date.day();
        int month = date.month();
        int year = date.year();

        QString dayString = QString::number(day);
        QString monthString = QDate::longMonthName(month);
        QString yearString = QString::number(year);

        painter->save();
        painter->setRenderHint(QPainter::Antialiasing);

        yearmonthday_ = new VyborgYearMonthDay(yearString, monthString, dayString);
        yearmonthday_->paint(painter, option.rect);

        painter->restore();
    } else
        QStyledItemDelegate::paint(painter, option, index);
}

QSize DateDelegate::sizeHint(const QStyleOptionViewItem &/*option*/, const QModelIndex &/*index*/) const
{
    return yearmonthday_->sizeHint();
}
