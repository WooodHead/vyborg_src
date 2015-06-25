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
    setupProxy();
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

void MainDialog::setupProxy()
{
    identityProxy_->setSourceModel(model_);
    identityProxy_->setHeaderData(statistics_id,              Qt::Horizontal, trUtf8("ID"));
    identityProxy_->setHeaderData(statistics_date,            Qt::Horizontal, trUtf8("Year\nand month"));
    identityProxy_->setHeaderData(statistics_innerFlights,    Qt::Horizontal, trUtf8("Внутренние\nрейсы"));
    identityProxy_->setHeaderData(statistics_foreignFlights,  Qt::Horizontal, trUtf8("Международные\nрейсы"));
    identityProxy_->setHeaderData(statistics_transitFlights,  Qt::Horizontal, trUtf8("Транзитные\nрейсы"));
    identityProxy_->setHeaderData(statistics_charterFlights,  Qt::Horizontal, trUtf8("Чартерные\nрейсы"));
    identityProxy_->setHeaderData(statistics_maxInDayFlights, Qt::Horizontal, trUtf8("Максимально\nв сутки"));
    identityProxy_->setHeaderData(statistics_foreignAC,       Qt::Horizontal, trUtf8("Иностранные\nавиакомпании"));
    identityProxy_->setHeaderData(statistics_note,            Qt::Horizontal, trUtf8("Note"));

    sortFilterProxy_->setSourceModel(identityProxy_);
    sortFilterProxy_->sort(statistics_date, Qt::AscendingOrder);
}

void MainDialog::setupView()
{
    view_->setModel(sortFilterProxy_);

    view_->setColumnHidden(statistics_id, true);
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
    MapperDialog *mapperDialog = new MapperDialog(sortFilterProxy_, this);
    mapperDialog_ = static_cast<VyborgMapperDialog *>(mapperDialog);
}

void MainDialog::setupFilterDialog()
{
    filterDialog_->addColumn(trUtf8("Дата"), statistics_date);
}

void MainDialog::setupSortDialog()
{
    sortDialog_->addColumn(trUtf8("Дата"), statistics_date);
    sortDialog_->addColumn(trUtf8("Внутренние полеты"), statistics_innerFlights);
    sortDialog_->addColumn(trUtf8("Международные полеты"), statistics_foreignFlights);
    sortDialog_->addColumn(trUtf8("Транзитные полеты"), statistics_transitFlights);
    sortDialog_->addColumn(trUtf8("Чартерные рейсы"), statistics_charterFlights);
    sortDialog_->addColumn(trUtf8("Максимальное количество рейсов за сутки"), statistics_maxInDayFlights);
    sortDialog_->addColumn(trUtf8("Международные перевозчики"), statistics_foreignAC);
}
