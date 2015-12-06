#include <QtWidgets>
#include <QStyledItemDelegate>
#include <QtSql>

#include "mapperdelegate.h"
#include "declarations.h"

#include "calendarbutton.h"
#include "positionadmittancewidget.h"


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
        CalendarButton *button = qobject_cast<CalendarButton *>(editor);
        QString data = button->stringDate();

        model->setData(index, data);
    }
    else if (col == person_tabnum ||
             col == person_shift ||
             col == person_class ||
             col == person_icaolevel ||
             col == person_licencenum)
    {
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(editor);
        QString data = lineEdit->text();
        if (data.isEmpty())
            model->setData(index, QVariant());
        else
            model->setData(index, data.toInt());
    }
    else if (col == person_icaolevelvalid ||
             col == person_licencevalid ||
             col == person_stazh ||
             col == person_postup ||
             col == person_medicalvalid ||
             col == person_kpkrp ||
             col == person_kpksd ||
             col == person_kpkdi ||
             col == person_kpkfact ||
             col == person_kpkplan ||
             col == person_kpkompfact ||
             col == person_kpkompplan)
    {
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(editor);
        QString data = lineEdit->text();
        if (data.isEmpty())
            model->setData(index, QVariant());
        else
            model->setData(index, data);
    }
    else if (col == person_position)
    {
        QComboBox *combo = qobject_cast<QComboBox*>(editor);
        QString data = combo->currentText();

        QSqlQuery query("SELECT position,t_position FROM person.position");
        while (query.next()) {
            QString position = query.value(0).toString().toUtf8();
            QString t_position = query.value(1).toString().toUtf8();
            if (position == data) {
                model->setData(index, t_position);
                query.clear();
                return;
            }
        }

        model->setData(index, data);
        query.clear();
    }
    else if (col == person_sectorgroup)
    {
        QComboBox *combo = qobject_cast<QComboBox*>(editor);
        QString data = combo->currentText();
        model->setData(index, data);
    }
    else
    {
        qDebug() << "DDD: " << model->data(index, Qt::EditRole);
        QStyledItemDelegate::setModelData(editor, model, index);
    }
}

void MapperDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int col = index.column();
    if (col == person_birthday)
    {
        CalendarButton *button = static_cast<CalendarButton *>(editor);
        QDate data = index.model()->data(index, Qt::EditRole).toDate();
        button->setText(data.toString("dd MMMM yyyy"));
    }
    else if (col == person_icaolevelvalid ||
             col == person_licencevalid ||
             col == person_stazh ||
             col == person_postup ||
             col == person_medicalvalid ||
             col == person_kpkrp ||
             col == person_kpksd ||
             col == person_kpkdi ||
             col == person_kpkfact ||
             col == person_kpkplan ||
             col == person_kpkompfact ||
             col == person_kpkompplan)
    {
        QLineEdit *lineEdit = static_cast<QLineEdit *>(editor);
        QDate data = index.model()->data(index, Qt::EditRole).toDate();
        if (data.isValid())
            lineEdit->setText(data.toString("yyyy-MM-dd"));
        else
            lineEdit->setText(QString(""));
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
//    else if (col != person_positionadmittance &&
//             col != person_sectoradmittance)
//    {
//        qDebug() << "STEP 2";
//        QLineEdit *lineEdit = static_cast<QLineEdit *>(editor);
//        QString data = lineEdit->text();
//        qDebug() << data;
//        if (data.isEmpty())
//            lineEdit->setText(QString(""));
//        else
//            lineEdit->setText(data);
//    }
    else
        QStyledItemDelegate::setEditorData(editor, index);
}
