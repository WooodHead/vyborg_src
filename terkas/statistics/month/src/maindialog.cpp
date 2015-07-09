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
    m_model->setTable(PGSQL_TABLENAME);
    bool ret = m_model->select();
    if (ret == false) {
        QString msgText("SELECT returned FALSE: " + m_model->lastError().text());
        QMessageBox::warning(this,
                             "ERROR",
                             msgText,
                             QMessageBox::Close);
        qApp->quit();
    }
}


void MainDialog::setupView()
{
    m_view->setModel(m_model);

    m_view->setColumnHidden(statistics_note, true);

    m_view->setItemDelegateForColumn(statistics_date, new DateDelegate(m_view));

    m_view->resizeRowsToContents();
    m_view->resizeColumnsToContents();

    m_view->selectRow(0);


    QHeaderView *header = m_view->horizontalHeader();
    header->setSectionResizeMode(statistics_date, QHeaderView::Fixed);
}

void MainDialog::setupMapperDialog()
{
    MapperDialog *mapperDialog = new MapperDialog(m_model);
    m_mapperDialog = static_cast<VyborgMapperDialog *>(mapperDialog);
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
