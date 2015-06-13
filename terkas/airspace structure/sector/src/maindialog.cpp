#include <QtWidgets>
#include <QtSql>

#include "declaration.h"

#include "maindialog.h"
#include "mapperdialog.h"

MainDialog::MainDialog(QWidget *parent)
    : VyborgMainDialog(parent)
{
    setupModel();
    setupView();
    setupMapperDialog();
}

void MainDialog::setupModel()
{
    model_->setTable(PGSQL_TABLENAME);
    model_->select();
}

void MainDialog::setupView()
{
    view_->setModel(model_);
    view_->setColumnHidden(0, true);
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
