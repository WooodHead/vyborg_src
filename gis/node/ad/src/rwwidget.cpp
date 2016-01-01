#include <QtWidgets>
#include <QtSql>

#include "rwwidget.h"

RWWidget::RWWidget(QWidget *parent)
    : QWidget(parent)
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM ad.vw_rw");

    QTableView *tableView = new QTableView;
    tableView->setModel(model);
    tableView->resizeColumnsToContents();
    tableView->hideColumn(0);

    QVBoxLayout *vbLayout = new QVBoxLayout;
    vbLayout->addWidget(tableView);

    setLayout(vbLayout);
}
