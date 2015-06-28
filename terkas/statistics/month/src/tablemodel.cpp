#include "tablemodel.h"

TableModel::TableModel(QObject * parent, QSqlDatabase db)
    : QSqlTableModel(parent, db)
{

}

