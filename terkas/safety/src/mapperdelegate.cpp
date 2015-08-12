#include <QtWidgets>
#include <QtSql>

#include "mapperdelegate.h"
#include "declarations.h"

#include <QDebug>

MapperDelegate::MapperDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

void MapperDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if (index.column() == safety_acc) {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT acc FROM safety.acc");

        QComboBox *comboEditor = qobject_cast<QComboBox *>(editor);
        Q_ASSERT(comboEditor);
        comboEditor->setModel(model);

        QString ddd = index.data(Qt::DisplayRole).toString();
        comboEditor->setCurrentText(ddd);
    } else if (index.column() == safety_classification) {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT classification FROM safety.classification");

        QComboBox *comboEditor = qobject_cast<QComboBox *>(editor);
        Q_ASSERT(comboEditor);
        comboEditor->setModel(model);

        QString ddd = index.data(Qt::DisplayRole).toString();
        comboEditor->setCurrentText(ddd);
    } else if (index.column() == safety_type) {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT type FROM safety.type");

        QComboBox *comboEditor = qobject_cast<QComboBox *>(editor);
        Q_ASSERT(comboEditor);
        comboEditor->setModel(model);

        QString ddd = index.data(Qt::DisplayRole).toString();
        comboEditor->setCurrentText(ddd);
    } else
        QStyledItemDelegate::setEditorData(editor, index);
}
