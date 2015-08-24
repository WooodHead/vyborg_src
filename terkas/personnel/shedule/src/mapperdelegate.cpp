#include <QtWidgets>
#include <QtSql>

#include "mapperdelegate.h"
#include "declarations.h"

MapperDelegate::MapperDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

void MapperDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int col = index.column();

//    if (col == safety_acc)
//    {
//        QSqlQueryModel *model = new QSqlQueryModel;
//        model->setQuery("SELECT acc FROM safety.acc");

//        QComboBox *comboEditor = qobject_cast<QComboBox *>(editor);
//        Q_ASSERT(comboEditor);
//        comboEditor->setModel(model);

//        QString ddd = index.data(Qt::DisplayRole).toString();
//        comboEditor->setCurrentText(ddd);
//    }

    if (col == shedule_fullname)
    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT concat(surname || ' ' || name || ' ' || middlename) "
                        "FROM person.person "
                        "ORDER BY person.surname");

        QComboBox *comboEditor = static_cast<QComboBox *>(editor);
        Q_ASSERT(comboEditor);
        comboEditor->setModel(model);

        QString fullname = index.data(Qt::DisplayRole).toString();
        comboEditor->setCurrentText(fullname);
    }
    else
        QStyledItemDelegate::setEditorData(editor, index);
}
