#include <QtWidgets>
#include <QtSql>

#include "maindialog.h"
#include "mapperdialog.h"

MainDialog::MainDialog(QWidget *parent)
    : VyborgMainDialog(parent)
{
//    QSqlTableModel *model = new QSqlTableModel(this);
//    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//    model->setTable("structure_airspace.sector");
//    model->select();

//    QTableView *view = new QTableView;
//    view->setModel(model);

//    view->setColumnHidden(0, true);

//    QHBoxLayout *mainLayout = new QHBoxLayout;
//    mainLayout->addWidget(view);

//    setLayout(mainLayout);

//    mainLayout->layout();
    setupModel();
    setupView();
    setupMapperDialog();
}

void MainDialog::setupModel()
{
    model_->setTable("structure_airspace.sector");
    model_->select();
}

void MainDialog::setupView()
{
    view_->setModel(model_);
}

void MainDialog::setupMapperDialog()
{
    mapperDialog_ = new MapperDialog(model_);
}

void MainDialog::setupFilterDialog()
{

}

void MainDialog::setupSortDialog()
{

}
