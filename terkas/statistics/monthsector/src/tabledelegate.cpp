#include <QtWidgets>

#include "tabledelegate.h"

TableDelegate::TableDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

void TableDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.isValid()) {
        QDate date = index.data().toDate();
        int month = date.month();
        int year  = date.year();
        QString monthString = QDate::longMonthName(month);
        QString yearString = QString::number(year);
        QString dateString = yearString + " : " + monthString;

        painter->save();
        painter->setRenderHint(QPainter::Antialiasing);

//        yearmonth = new VyborgYearMonth(yearString, monthString);
//        yearmonth->paint(painter, option.rect);

        painter->drawText(option.rect, dateString);

        painter->restore();
    } else
        QStyledItemDelegate::paint(painter, option, index);  // should be modified
}

QSize TableDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
//    QFont font("Verdana");
////    int fontPixelSize_ = 12;
////    font.setPixelSize(fontPixelSize_);
//    QFontMetrics fm(font);
//    painter->setFont(font);

//    QRectF rectMonth(QPointF(2, 2), QSize(56, 26));
//    painter->drawText(rectMonth, Qt::AlignCenter, QString(day_ + " " + month_));

//    QRectF rectYear(QPointF(2, 32), QSize(56, 26));
//    painter->drawText(rectYear, Qt::AlignCenter, year_);
    return QSize(300, 30);
}
