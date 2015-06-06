#include <QPainter>
#include <QGuiApplication>

#include "personmodeldelegate.h"
#include "declarations.h"


PersonModelDelegate::PersonModelDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

void PersonModelDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == person_innerID ||
        index.column() == person_mobilePhone) {

        painter->save();
        painter->setRenderHint(QPainter::Antialiasing, true);
        if (option.state & QStyle::State_Selected) {
            painter->fillRect(option.rect, option.palette.highlight());
            painter->setBrush(option.palette.highlightedText());
            painter->setPen(QColor("white"));
        }

        QString outputStr;
        if (index.column() == person_innerID) {
            int innerId = index.data().toInt();
            outputStr = QString("%1").arg(innerId, 6, 10, QChar('0'));
        } else if (index.column() == person_mobilePhone) {
            QString mobilePhoneStr = index.data().toString();
            QString firstLetters = mobilePhoneStr.mid(0, 3);
            QString secondLetters = mobilePhoneStr.mid(3, 3);
            QString thirdLetters = mobilePhoneStr.mid(5, 2);
            QString fourthLetters = mobilePhoneStr.mid(7, 2);
            outputStr = QString("(" + firstLetters + ") " + secondLetters +
                                "-" + thirdLetters +
                                "-" + fourthLetters);
        }

        painter->drawText(option.rect, Qt::AlignCenter, outputStr);
        painter->restore();
    } else {
        QStyledItemDelegate::paint(painter, option, index);
    }
}

QSize PersonModelDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == person_mobilePhone) {
        QFont defFont = QGuiApplication::font();
        QFontMetrics fm(defFont);
        QString str15(15, QChar('0'));
        int w = fm.width(str15);
        int h = fm.height();
        return QSize(w, h);
    }

    return QStyledItemDelegate::sizeHint(option, index);
}
