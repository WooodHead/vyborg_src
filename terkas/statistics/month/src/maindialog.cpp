#include <QtWidgets>
#include <QtSql>

#include "maindialog.h"
#include "declarations.h"
#include "tabledelegate.h"
#include "mapperdialog.h"

#include <QDebug>


MainDialog::MainDialog(QWidget *parent)
    : VyborgMainDialog(parent)
{
    setupModel();
    setupView();
    setupMapperDialog();
    setupFilterDialog();
    setupSortDialog();
}

void MainDialog::setupModel()
{
    model_->setTable(PGSQL_TABLENAME);
    bool ret = model_->select();
    if (ret == false) {
        QString msgText("SELECT returned FALSE: " + model_->lastError().text());
        QMessageBox::warning(this,
                             "ERROR",
                             msgText,
                             QMessageBox::Close);
        qApp->quit();
    }
}


void MainDialog::setupView()
{
    view_->setModel(model_);

    view_->setColumnHidden(statistics_note, true);

    view_->setItemDelegateForColumn(statistics_date, new DateDelegate(view_));

    view_->resizeRowsToContents();
    view_->resizeColumnsToContents();

    view_->selectRow(0);


    QHeaderView *header = view_->horizontalHeader();
    header->setSectionResizeMode(statistics_date, QHeaderView::Fixed);
}

void MainDialog::setupMapperDialog()
{
    MapperDialog *mapperDialog = new MapperDialog(model_);
    mapperDialog_ = static_cast<VyborgMapperDialog *>(mapperDialog);
}

void MainDialog::setupFilterDialog()
{
    filterDialog_->addColumn(trUtf8("Дата"), statistics_date);
}

void MainDialog::setupSortDialog()
{
    sortDialog_->addColumn(trUtf8("Дата"), statistics_date);
    sortDialog_->addColumn(trUtf8("Внутренние полеты"), statistics_internal);
    sortDialog_->addColumn(trUtf8("Международные полеты"), statistics_external);
    sortDialog_->addColumn(trUtf8("Транзитные полеты"), statistics_transit);
    sortDialog_->addColumn(trUtf8("Чартерные рейсы"), statistics_charter);
    sortDialog_->addColumn(trUtf8("Максимальное количество рейсов за сутки"), statistics_maxday);
    sortDialog_->addColumn(trUtf8("Международные перевозчики"), statistics_foreigner);
}
