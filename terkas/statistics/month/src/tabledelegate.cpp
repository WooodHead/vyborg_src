#include <QtWidgets>
#include <vyborg/yearmonth.h>

#include "tabledelegate.h"


/**********************************************************************************
 * DateDelegate - show month and year
 **********************************************************************************/

DateDelegate::DateDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

void DateDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.isValid()) {
        QDate date = index.data().toDate();
        int month = date.month();
        int year  = date.year();
        QString monthString = QDate::longMonthName(month);
        QString yearString = QString::number(year);

        painter->save();
        painter->setRenderHint(QPainter::Antialiasing);

        yearmonth = new VyborgYearMonth(yearString, monthString);
        yearmonth->paint(painter, option.rect);

        painter->restore();
    } else
        QStyledItemDelegate::paint(painter, option, index);  // should be modified
}

QSize DateDelegate::sizeHint(const QStyleOptionViewItem &/*option*/, const QModelIndex & /* index */) const
{
    return yearmonth->sizeHint();
}

QWidget* DateDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.isValid()) {
        QDateEdit *dateEdit = new QDateEdit(parent);
        dateEdit->setDisplayFormat("yyyy MMMM");
        connect(dateEdit, SIGNAL(editingFinished()),
                SLOT(commitAndCloseEditor()));
        return dateEdit;
    } else
        return QStyledItemDelegate::createEditor(parent, option, index);
}

void DateDelegate::commitAndCloseEditor()
{
    QDateEdit *editor = static_cast<QDateEdit *>(sender());
    emit commitData(editor);
    emit closeEditor(editor, QItemDelegate::EditNextItem);
}

//void DateDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
//{
//    QItemDelegate::setEditorData(editor, index);
//}

//void DateDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
//{
//    QItemDelegate::setModelData(editor, model, index);
//}

//void DateDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
//{
//    QItemDelegate::updateEditorGeometry(editor, option, index);
//}


/**********************************************************************************
 * ProgressDelegate - show progress bar in item
 **********************************************************************************/

ProgressDelegate::ProgressDelegate(QObject *parent) :
    QItemDelegate(parent)
{
}

void ProgressDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int progress = index.data().toInt();

    QStyleOptionProgressBar progressBar;
    progressBar.rect = option.rect;
    progressBar.minimum = 0;
    progressBar.maximum = 25000;
    progressBar.progress = progress;
    progressBar.text = QString::number(progress);
    progressBar.textVisible = true;

    QApplication::style()->drawControl(QStyle::CE_ProgressBar,
                                       &progressBar,
                                       painter);
}

QSize ProgressDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &/*index*/) const
{
    QSize size = option.rect.size();
    return size;
}
