#include <QtWidgets>
#include <QStyledItemDelegate>

#include "mapperdelegate.h"

MapperDelegate::MapperDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{

}

void MapperDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QLineEdit *w = qobject_cast<QLineEdit*>(editor);
    QString t = w->text();

    if (t.isEmpty()) {
        model->setData(index, QVariant());
    } else {
        model->setData(index, t);
    }
}
