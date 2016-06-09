#include <QtWidgets>
#include <QtSql>
#include <QSqlError>

#include "mapperdelegate.h"
#include "declarations.h"

#include <QDebug>

MapperDelegate::MapperDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

void MapperDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    switch (index.column()) {
    case safety_department: {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT department FROM structure.department");

        QComboBox *combo = qobject_cast<QComboBox *>(editor);
        Q_ASSERT(combo);
        combo->setModel(model);

        QString data = index.data(Qt::DisplayRole).toString();
        combo->setCurrentText(data);
        break;
    }
    case safety_shift: {
        QComboBox *combo = qobject_cast<QComboBox *>(editor);
        combo->addItem(QString(""));
        for (int i = 1; i <= 6; i++)
            combo->addItem(QString::number(i));

        QString data = index.data(Qt::DisplayRole).toString();
        combo->setCurrentText(data);
        break;
    }
    case safety_sector_fullname: {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT sector.* FROM dblink('dbname=gis','SELECT pid,fullname FROM fir.sector') "
                        "AS sector(pid INTEGER, fullname VARCHAR)");

        QComboBox *combo = qobject_cast<QComboBox *>(editor);
        Q_ASSERT(combo);
        combo->setModel(model);
        combo->setModelColumn(1);

        QString data = index.data(Qt::DisplayRole).toString();
        combo->setCurrentText(data);
        break;
    }
    }

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

void MapperDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    switch (index.column()) {
    case safety_date: {
        QDateEdit *dateEdit = qobject_cast<QDateEdit *>(editor);
        QDate date = dateEdit->date();
        qDebug() << "DATE" << date.toString("yyyy-MM-dd");
        if (model->setData(index, date.toString("yyyy-MM-dd"), Qt::EditRole) == false)
            qDebug() << "NO";
        break;
    }
    case safety_department: {
        QComboBox *combo = qobject_cast<QComboBox *>(editor);
        QString data = combo->currentText();
        if (data.isEmpty())
            model->setData(index, QVariant());
        else
            model->setData(index, data);
        break;
    }
    case safety_shift: {
        QComboBox *combo = qobject_cast<QComboBox*>(editor);
        QString data = combo->currentText();
        if (data.isEmpty())
            model->setData(index, QVariant());
        else
            model->setData(index, data.toInt());
        break;
    }
    default:
        QStyledItemDelegate::setModelData(editor, model, index);
    }
}
