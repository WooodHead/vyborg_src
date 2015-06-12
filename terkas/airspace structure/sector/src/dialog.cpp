#include <QtWidgets>
#include <QtSql>

#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setTable("structure_airspace.sector");
    model->select();

    QTableView *view = new QTableView;
    view->setModel(model);

    view->setColumnHidden(0, true);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(view);

    setLayout(mainLayout);

    mainLayout->layout();
}
