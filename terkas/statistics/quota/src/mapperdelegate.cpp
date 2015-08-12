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
    if (index.column() == quota_abbr) {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM ("
                        "SELECT abbr FROM dblink('dbname=gis', 'SELECT abbr FROM polygon.fir') "
                                         "dblink(abbr text)) tb ORDER BY abbr");

        QComboBox *comboEditor = qobject_cast<QComboBox *>(editor);
        Q_ASSERT(comboEditor);
        comboEditor->setModel(model);

        QString ddd = index.data(Qt::DisplayRole).toString();
        comboEditor->setCurrentText(ddd);
    } else
        QStyledItemDelegate::setEditorData(editor, index);
}
