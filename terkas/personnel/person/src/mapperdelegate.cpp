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
    if (col == person_birthday)
    {

    }
    else if (col == person_position)
    {
        QComboBox *combo = qobject_cast<QComboBox*>(editor);
        QString data = combo->currentText();
        model->setData(index, data);
    }
    else if (col == person_sectorgroup)
    {
        QComboBox *combo = qobject_cast<QComboBox*>(editor);
        QString data = combo->currentText();
        model->setData(index, data);
    }
    else
    {
        QLineEdit *w = qobject_cast<QLineEdit*>(editor);
        QString data = w->text();
        if (data.isEmpty())
            model->setData(index, QVariant());
        else
            model->setData(index, data);
    }
}

void MapperDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int col = index.column();
    if (col == person_birthday)
    {
        QPushButton *button = static_cast<QPushButton*>(editor);
        QDate data = index.model()->data(index, Qt::EditRole).toDate();
        button->setText(data.toString("dd MMMM yyyy"));
    }
    else if (col == person_position)
    {
        QComboBox *combo = static_cast<QComboBox *>(editor);
        combo->clear();
        combo->addItem(QString::null);

//        QSqlQuery query("SELECT unnest(enum_range(NULL::person.t_position))");
        QSqlQuery query("SELECT position,t_position FROM person.position");
        while (query.next()) {
            QString position = query.value(0).toString().toUtf8();
            QString t_position = query.value(1).toString().toUtf8();
            combo->addItem(position, t_position);
        }
        query.clear();

        QString data = index.model()->data(index, Qt::EditRole).toString().toUtf8();
        QSqlQuery query1("SELECT position,t_position FROM person.position");
        while (query1.next()) {
            QString position = query1.value(0).toString().toUtf8();
            QString t_position = query1.value(1).toString().toUtf8();
            if (t_position == data) {
                    combo->setCurrentText(position);
                    query1.clear();
                    break;
            }
        }
    }
    else if (col == person_sectorgroup)
    {
        QComboBox *combo = static_cast<QComboBox *>(editor);
        combo->clear();
        combo->addItem(QString::null);

        QSqlQuery query("SELECT unnest(enum_range(NULL::gis.t_sectorgroup))");
        while (query.next()) {
            QString sectorgroup = query.value(0).toString().toUtf8();
            combo->addItem(sectorgroup);
        }

        QString data = index.model()->data(index, Qt::EditRole).toString().toUtf8();
        combo->setCurrentText(data);
    }
    else
        QStyledItemDelegate::setEditorData(editor, index);
}
