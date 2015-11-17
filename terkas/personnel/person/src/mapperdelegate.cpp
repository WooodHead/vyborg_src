#include <QtWidgets>
#include <QStyledItemDelegate>
#include <QtSql>

#include "mapperdelegate.h"
#include "declarations.h"

#include <QDebug>

MapperDelegate::MapperDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

void MapperDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    int col = index.column();
    if (col == person_sectorgroup)
    {
        QComboBox *combo = qobject_cast<QComboBox*>(editor);
        QString data = combo->currentText();

        if (data.isEmpty())
            model->setData(index, QVariant());
        else
            model->setData(index, data);
    }
    else
    {
        QLineEdit *w = qobject_cast<QLineEdit*>(editor);
        QString t = w->text();

        if (t.isEmpty())
            model->setData(index, QVariant());
        else
            model->setData(index, t);
    }
}

void MapperDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int col = index.column();
    if (col == person_sectorgroup) {
        QComboBox *combo = static_cast<QComboBox *>(editor);
        combo->clear();

        QSqlQuery query("SELECT unnest(enum_range(NULL::gis.t_sectorgroup))");
        while (query.next()) {
            QString sectorgroup = query.value(0).toString().toUtf8();
            combo->addItem(sectorgroup);
        }
        combo->addItem(QString(""));

        QString data = index.model()->data(index, Qt::EditRole).toString();
        combo->setCurrentText(data);
    } else
        QStyledItemDelegate::setEditorData(editor, index);
}
