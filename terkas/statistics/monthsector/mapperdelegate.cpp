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
    if (index.column() == monthsector_sector) {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM ("
                        "SELECT sector FROM dblink('dbname=gis',"
                                                  "'SELECT sector FROM data.polygon_fir_sector') "
                                           "dblink(sector text)) tb ORDER BY sector");

        QComboBox *comboEditor = qobject_cast<QComboBox *>(editor);
        Q_ASSERT(comboEditor);
        comboEditor->setModel(model);

        QString ddd = index.data(Qt::DisplayRole).toString();
        comboEditor->setCurrentText(ddd);
    } else
        QStyledItemDelegate::setEditorData(editor, index);
}
