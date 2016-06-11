#ifndef TABLEDELEGATE_H
#define TABLEDELEGATE_H

#include <QStyledItemDelegate>
#include <QItemDelegate>


/**********************************************************************************
 *
 * DateDelegate - show month and year
 *
 **********************************************************************************/

class VyborgYearMonth;

class DateDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    DateDelegate(QObject *parent = 0);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
//    void setEditorData(QWidget *editor, const QModelIndex &index) const;
//    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
//    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

private slots:
    void commitAndCloseEditor();

private:
    mutable VyborgYearMonth *yearmonth;
};


/**********************************************************************************
 *
 * ProgressDelegate - show progress bar in item
 *
 **********************************************************************************/

class ProgressDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    ProgressDelegate(QObject *parent = 0);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
};


#endif // TABLEDELEGATE_H
