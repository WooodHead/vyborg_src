#include <QtWidgets>
#include <QtSql>

#include "maindialog.h"
#include "declarations.h"
#include "tablemodel.h"
#include "mapperdialog.h"

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
    m_model = new TableModel;
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

//    m_model->setHeaderData(statistics_date,      Qt::Horizontal,
//                           trUtf8("Дата\n(Месяц, Год)"), Qt::DisplayRole);
//    m_model->setHeaderData(statistics_internal,  Qt::Horizontal,
//                           trUtf8("Внутренние\nрейсы"), Qt::DisplayRole);
//    m_model->setHeaderData(statistics_external,  Qt::Horizontal,
//                           trUtf8("Международные\nрейсы"), Qt::DisplayRole);
//    m_model->setHeaderData(statistics_transit,   Qt::Horizontal,
//                           trUtf8("Транзитные\nрейсы"), Qt::DisplayRole);
//    m_model->setHeaderData(statistics_charter,   Qt::Horizontal,
//                           trUtf8("Рейсы вне расписания\n(чартерные)"), Qt::DisplayRole);
//    m_model->setHeaderData(statistics_maxday,    Qt::Horizontal,
//                           trUtf8("Максимальная суточная\nинтенсивность ВС\nсекторов РДЦ"), Qt::DisplayRole);
//    m_model->setHeaderData(statistics_foreigner, Qt::Horizontal,
//                           trUtf8("Рейсы иностранных\nавиакомпаний"), Qt::DisplayRole);
//    m_model->setHeaderData(statistics_note,      Qt::Horizontal,
//                           trUtf8("Примечание"), Qt::DisplayRole);
}


void MainDialog::setupView()
{
    m_view->setModel(m_model);
    m_view->resizeColumnsToContents();
    m_view->horizontalHeader()->setStretchLastSection(true);
    m_view->verticalHeader()->show();
    m_view->setColumnHidden(safety_pid,        true);
    m_view->setColumnHidden(safety_sector_pid, true);
    m_view->setColumnHidden(safety_cause,      true);
    m_view->setColumnHidden(safety_details,    true);
    m_view->setColumnHidden(safety_factor,     true);
    m_view->setColumnHidden(safety_terkas,     true);
    m_view->setColumnHidden(safety_alpha,      true);
    m_view->setColumnHidden(safety_tcas1,      true);
    m_view->setColumnHidden(safety_tcas2,      true);

//    m_view->resizeRowsToContents();
//    m_view->resizeColumnsToContents();
    m_view->selectRow(0);

//    QHeaderView *header = m_view->horizontalHeader();
    //    header->setSectionResizeMode(safe, QHeaderView::Fixed);
}

void MainDialog::setupMapperDialog()
{
    MapperDialog *mapperDialog = new MapperDialog(m_model);
    m_mapperDialog = static_cast<VyborgMapperDialog *>(mapperDialog);
}

void MainDialog::setupFilterDialog()
{
//    filterDialog_->addColumn(trUtf8("Дата"), trUtf8("date"));
//    filterDialog_->addColumn(trUtf8("Внутренние рейсы"), trUtf8("internal"));
//    filterDialog_->addColumn(trUtf8("Международные рейсы"), trUtf8("external"));
//    filterDialog_->addColumn(trUtf8("Транзитные рейсы"), trUtf8("transit"));
//    filterDialog_->addColumn(trUtf8("Рейсы вне расписания (чартерные) рейсы"), trUtf8("charter"));
//    filterDialog_->addColumn(trUtf8("Максимальная суточная интенсивность ВС секторов РДЦ рейсы"), trUtf8("maxday"));
//    filterDialog_->addColumn(trUtf8("Рейсы иностранных авиакомпаний"), trUtf8("foreigner"));
}

void MainDialog::setupSortDialog()
{
//    sortDialog_->addColumn(trUtf8("Дата"), statistics_date);
//    sortDialog_->addColumn(trUtf8("Внутренние рейсы"), statistics_internal);
//    sortDialog_->addColumn(trUtf8("Международные рейсы"), statistics_external);
//    sortDialog_->addColumn(trUtf8("Транзитные рейсы"), statistics_transit);
//    sortDialog_->addColumn(trUtf8("Рейсы вне расписания (чартерные) рейсы"), statistics_charter);
//    sortDialog_->addColumn(trUtf8("Максимальная суточная интенсивность ВС секторов РДЦ рейсы"), statistics_maxday);
//    sortDialog_->addColumn(trUtf8("Рейсы иностранных авиакомпаний"), statistics_foreigner);
}
