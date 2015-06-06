#include <QGuiApplication>
#include <QPainter>
#include <QFont>
#include <QTableView>
#include <QHeaderView>

#include "monthdelegate.h"


MonthDelegate::MonthDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

void MonthDelegate::setView(QTableView *view)
{
    m_view = view;
}

void MonthDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing, true);

    int data = index.model()->data(index, Qt::EditRole).toInt();
    switch (data) {
    case 1:
        painter->setBrush(Qt::green);
        painter->setPen(Qt::red);
        painter->drawRect(option.rect);
        break;
    default:
        if (option.state & QStyle::State_Selected) {
            painter->fillRect(option.rect, option.palette.highlight());
            painter->setBrush(option.palette.highlightedText());
            painter->setPen(QColor("white"));
        }
        break;
    }

    QString outputStr = index.model()->data(index).toString();
    painter->drawText(option.rect, Qt::AlignCenter, outputStr);

    painter->restore();
}

QSize MonthDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option)

    QFont defFont = QGuiApplication::font();
    QFontMetrics fm(defFont);
    QString str1(4, QChar('A'));
    int w = fm.width(str1);
    int h = fm.height();

    m_view->horizontalHeader()->resizeSection(index.column(), w);
    return QSize(w, h);
}
