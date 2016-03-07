#include <QtWidgets>
#include <QtSql>

#include "maindialog.h"
#include "declarations.h"
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

    m_model->setHeaderData(sector_pid,      Qt::Horizontal, trUtf8("PID"));
    m_model->setHeaderData(sector_sector,   Qt::Horizontal, trUtf8("Сектор"));
    m_model->setHeaderData(sector_fullname, Qt::Horizontal, trUtf8("Расширенное\nнаименование"));
    m_model->setHeaderData(sector_label,    Qt::Horizontal, trUtf8("Метка"));
    m_model->setHeaderData(sector_compound, Qt::Horizontal, trUtf8("Составной"));
    m_model->setHeaderData(sector_geog,     Qt::Horizontal, trUtf8("Граница сектора"));
    m_model->setHeaderData(sector_points,   Qt::Horizontal, trUtf8("Координаты\nточек границы"));
}

void MainDialog::setupView()
{
    m_view->setModel(m_model);
//    m_view->setItemDelegate(new PersonModelDelegate(m_view));

    m_view->resizeColumnsToContents();
//    m_view->resizeRowsToContents();
    m_view->horizontalHeader()->setStretchLastSection(true);

    m_view->verticalHeader()->show();

    m_view->hideColumn(sector_pid);
    m_view->hideColumn(sector_sector);
    m_view->hideColumn(sector_geog);
    m_view->hideColumn(sector_points);

    m_view->selectRow(0);
}

void MainDialog::setupMapperDialog()
{
    MapperDialog *mapperDialog = new MapperDialog(m_model, this);
    m_mapperDialog = static_cast<VyborgMapperDialog *>(mapperDialog);
    m_mapperDialog->resize(800, 480);
}

void MainDialog::setupFilterDialog()
{
//    filterDialog_->addColumn(trUtf8("ICAO code"), AC_ICAO);
//    filterDialog_->addColumn(trUtf8("IATA code"), AC_IATA);
//    filterDialog_->addColumn(trUtf8("Российский код"), AC_codeRu);
//    filterDialog_->addColumn(trUtf8("Callsign"), AC_CS);
//    filterDialog_->addColumn(trUtf8("Позывной а/к"), AC_CSru);
//    filterDialog_->addColumn(trUtf8("Company name"), AC_AC);
//    filterDialog_->addColumn(trUtf8("Название а/к"), AC_ACru);
//    filterDialog_->addColumn(trUtf8("Страна"), AC_country_id);
}

void MainDialog::setupSortDialog()
{
//    sortDialog_->addColumn(trUtf8("ICAO code"), AC_ICAO);
//    sortDialog_->addColumn(trUtf8("IATA code"), AC_IATA);
//    sortDialog_->addColumn(trUtf8("Российский код"), AC_codeRu);
//    sortDialog_->addColumn(trUtf8("Callsign"), AC_CS);
//    sortDialog_->addColumn(trUtf8("Позывной а/к"), AC_CSru);
//    sortDialog_->addColumn(trUtf8("Company name"), AC_AC);
//    sortDialog_->addColumn(trUtf8("Название а/к"), AC_ACru);
//    sortDialog_->addColumn(trUtf8("Страна"), AC_country_id);
}
