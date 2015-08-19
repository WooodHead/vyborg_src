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
    int col = index.column();

    if (col == safety_acc)
    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT acc FROM safety.acc");

        QComboBox *comboEditor = qobject_cast<QComboBox *>(editor);
        Q_ASSERT(comboEditor);
        comboEditor->setModel(model);

        QString ddd = index.data(Qt::DisplayRole).toString();
        comboEditor->setCurrentText(ddd);
    }
    else if (col == safety_classification)
    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT classification FROM safety.classification");

        QComboBox *comboEditor = qobject_cast<QComboBox *>(editor);
        Q_ASSERT(comboEditor);
        comboEditor->setModel(model);

        QString ddd = index.data(Qt::DisplayRole).toString();
        comboEditor->setCurrentText(ddd);
    }
    else if (col == safety_type)
    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT type FROM safety.type");

        QComboBox *comboEditor = qobject_cast<QComboBox *>(editor);
        Q_ASSERT(comboEditor);
        comboEditor->setModel(model);

        QString ddd = index.data(Qt::DisplayRole).toString();
        comboEditor->setCurrentText(ddd);
    }
    else if (col == safety_terkas)
    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT description FROM safety.sposatc");

        QComboBox *comboEditor = qobject_cast<QComboBox *>(editor);
        Q_ASSERT(comboEditor);
        comboEditor->setModel(model);

        QString ddd = index.data(Qt::DisplayRole).toString();
        comboEditor->setCurrentText(ddd);
    }
    else if (col == safety_alpha)
    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT description FROM safety.sposatc");

        QComboBox *comboEditor = qobject_cast<QComboBox *>(editor);
        Q_ASSERT(comboEditor);
        comboEditor->setModel(model);

        QString ddd = index.data(Qt::DisplayRole).toString();
        comboEditor->setCurrentText(ddd);
    }
    else if (col == safety_tcas1)
    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT description FROM safety.spostcas");

        QComboBox *comboEditor = qobject_cast<QComboBox *>(editor);
        Q_ASSERT(comboEditor);
        comboEditor->setModel(model);

        QString ddd = index.data(Qt::DisplayRole).toString();
        comboEditor->setCurrentText(ddd);
    }
    else if (col == safety_tcas2)
    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT description FROM safety.spostcas");

        QComboBox *comboEditor = qobject_cast<QComboBox *>(editor);
        Q_ASSERT(comboEditor);
        comboEditor->setModel(model);

        QString ddd = index.data(Qt::DisplayRole).toString();
        comboEditor->setCurrentText(ddd);
    }
    else
        QStyledItemDelegate::setEditorData(editor, index);
}
