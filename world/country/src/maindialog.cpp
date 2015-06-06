#include <QtWidgets>
#include <QtSql>

#include "maindialog.h"
#include "declarations.h"
#include "tabledelegate.h"
#include "mapperdialog.h"



MainDialog::MainDialog(QWidget *parent)
    : VyborgMainDialog(parent)
{
    setupModel();
    setupProxy();
    setupView();
    setupMapperDialog();
    setupFilterDialog();
    setupSortDialog();
}

void MainDialog::setupModel()
{
    model_->setTable(MYSQL_TABLENAME);
    model_->select();
}

void MainDialog::setupProxy()
{
    identityProxy_->setSourceModel(model_);
//    identityProxy_->insertColumn(country_flag);
    identityProxy_->setHeaderData(country_name, Qt::Horizontal, trUtf8("Country Name"));
//    identityProxy_->setHeaderData(country_flag, Qt::Horizontal, trUtf8("Flag"));



    sortFilterProxy_->setSourceModel(identityProxy_);
    sortFilterProxy_->sort(country_name, Qt::AscendingOrder);
}

void MainDialog::setupView()
{
    view_->setModel(sortFilterProxy_);

    view_->setColumnHidden(country_id,              true);
    view_->setColumnHidden(country_nameAbridged,    true);
    view_->setColumnHidden(country_nameAbridgedRu, true);
    view_->setColumnHidden(country_iso3166_num,     true);
    view_->setColumnHidden(country_iso3166_2,       true);
    view_->setColumnHidden(country_iso3166_3,       true);
    view_->setColumnHidden(country_note,            true);
    view_->setColumnHidden(country_noteRu,         true);


//    QHeaderView *vHeader = view_->horizontalHeader();
//    vHeader->swapSections(country_name, country_flag);


//    view_->setItemDelegateForColumn(country_flag, new ImageTableDelegate);

    view_->resizeRowsToContents();
    view_->resizeColumnsToContents();

    view_->selectRow(0);
}

void MainDialog::setupMapperDialog()
{
    MapperDialog *mapperDialog = new MapperDialog(sortFilterProxy_, this);
    mapperDialog_ = static_cast<VyborgMapperDialog *>(mapperDialog);
}

void MainDialog::setupFilterDialog()
{
    filterDialog_->addColumn(trUtf8("Country Name"), country_name);
    filterDialog_->addColumn(trUtf8("Country Abridged Name"), country_nameAbridged);
    filterDialog_->addColumn(trUtf8("Название страны"), country_nameRu);
    filterDialog_->addColumn(trUtf8("Сокращенное название страны"), country_nameAbridgedRu);
    filterDialog_->addColumn(trUtf8("Код ISO3166 NUMERIC"), country_iso3166_num);
    filterDialog_->addColumn(trUtf8("Код ISO3166-2"), country_iso3166_2);
    filterDialog_->addColumn(trUtf8("Код ISO3166-3"), country_iso3166_3);
}

void MainDialog::setupSortDialog()
{
    sortDialog_->addColumn(trUtf8("Country Name"), country_name);
    sortDialog_->addColumn(trUtf8("Country Abridged Name"), country_nameAbridged);
    sortDialog_->addColumn(trUtf8("Название страны"), country_nameRu);
    sortDialog_->addColumn(trUtf8("Сокращенное название страны"), country_nameAbridgedRu);
    sortDialog_->addColumn(trUtf8("Код ISO3166 NUMERIC"), country_iso3166_num);
    sortDialog_->addColumn(trUtf8("Код ISO3166-2"), country_iso3166_2);
    sortDialog_->addColumn(trUtf8("Код ISO3166-3"), country_iso3166_3);
}
