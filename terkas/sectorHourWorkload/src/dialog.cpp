#include <QtWidgets>
#include <QtSql>

#include "dialog.h"
#include "tableview.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable("statistics.\"sectorHourWorkload\"");
    model->select();

    TableView *view = new TableView;
    view->setModel(model);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(view);

    setLayout(mainLayout);
}
