#include <QtWidgets>
#include <QStyledItemDelegate>

#include "mapperdelegate.h"

#include <QDebug>

MapperDelegate::MapperDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

void MapperDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QLineEdit *w = qobject_cast<QLineEdit*>(editor);
    QString t = w->text();

    qDebug() << "DATA: " << t;

    if (t.isEmpty()) {
        model->setData(index, QVariant());
    } else {
        qDebug() << "DATA: " << t;
        model->setData(index, t);
    }
}
