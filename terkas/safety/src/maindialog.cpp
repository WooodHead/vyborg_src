#include <QtWidgets>
#include <QtSql>

#include "maindialog.h"
#include "declarations.h"
#include "mapperdialog.h"
#include "tableviewdelegate.h"


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
    model_->setRelation(safety_ACC_id,                  QSqlRelation("ACC", "id", "ACC"));
    model_->setRelation(safety_department_id,           QSqlRelation("department", "id", "department"));
    model_->setRelation(safety_sector_id,               QSqlRelation("sector", "id", "sector"));
    model_->setRelation(safety_safetyClassification_id, QSqlRelation("safetyClassification", "id", "classification"));
    model_->setRelation(safety_safetyType_id,           QSqlRelation("safetyType", "id", "type"));
    model_->setRelation(safety_sposTerkas_id,           QSqlRelation("ATCspos", "id", "ATCspos"));
    model_->setRelation(safety_sposAlpha_id,            QSqlRelation("ATCspos", "id", "ATCspos"));
    model_->setRelation(safety_TCAS1_id,                QSqlRelation("TCAS", "id", "TCAS"));
    model_->setRelation(safety_TCAS2_id,                QSqlRelation("TCAS", "id", "TCAS"));
    model_->select();
}

void MainDialog::setupProxy()
{
    identityProxy_->setSourceModel(model_);
    identityProxy_->setHeaderData(safety_id,                      Qt::Horizontal, trUtf8("ID"));
    identityProxy_->setHeaderData(safety_date,                    Qt::Horizontal, trUtf8("Дата на\nмомент события"));
    identityProxy_->setHeaderData(safety_ACC_id,                  Qt::Horizontal, trUtf8("Центр ОВД"));
    identityProxy_->setHeaderData(safety_department_id,           Qt::Horizontal, trUtf8("Подразделение"));
    identityProxy_->setHeaderData(safety_shiftNum,                Qt::Horizontal, trUtf8("№ Смены"));
    identityProxy_->setHeaderData(safety_sector_id,               Qt::Horizontal, trUtf8("Сектор"));
    identityProxy_->setHeaderData(safety_area,                    Qt::Horizontal, trUtf8("Место события"));
    identityProxy_->setHeaderData(safety_safetyClassification_id, Qt::Horizontal, trUtf8("Классификация\nсобытия"));
    identityProxy_->setHeaderData(safety_safetyType_id,           Qt::Horizontal, trUtf8("Вид\nсобытия"));
    identityProxy_->setHeaderData(safety_sposTerkas_id,           Qt::Horizontal, trUtf8("СПОС\n АС 'Теркас'"));
    identityProxy_->setHeaderData(safety_sposAlpha_id,            Qt::Horizontal, trUtf8("СПОС\n КСА 'Альфа'"));
    identityProxy_->setHeaderData(safety_TCAS1_id,                Qt::Horizontal, trUtf8("TCAS\n1 ВС"));
    identityProxy_->setHeaderData(safety_TCAS2_id,                Qt::Horizontal, trUtf8("TCAS\n2 ВС"));
    identityProxy_->setHeaderData(safety_cause,                   Qt::Horizontal, trUtf8("Причина"));
    identityProxy_->setHeaderData(safety_factor,                  Qt::Horizontal, trUtf8("Факторы"));
    identityProxy_->setHeaderData(safety_details,                 Qt::Horizontal, trUtf8("Прочее"));

    sortFilterProxy_->setSourceModel(identityProxy_);
    sortFilterProxy_->sort(safety_date, Qt::AscendingOrder);
}

void MainDialog::setupView()
{
    view_->setModel(sortFilterProxy_);

    view_->setColumnHidden(safety_id,          true);
//    view_->hideColumn(safety_id);
    view_->setColumnHidden(safety_shiftNum,    true);
    view_->setColumnHidden(safety_cause,       true);
    view_->setColumnHidden(safety_factor,      true);
    view_->setColumnHidden(safety_details,     true);


//    QHeaderView *vHeader = view_->horizontalHeader();
//    vHeader->swapSections(country_name, country_flag);
    QHeaderView *header = view_->horizontalHeader();
    header->setSectionResizeMode(safety_date, QHeaderView::Fixed);


    view_->setItemDelegateForColumn(safety_date, new DateDelegate(this));
//    view_->setItemDelegateForColumn(country_flag, new ImageTableDelegate);

    view_->resizeRowsToContents();
    view_->resizeColumnsToContents();

//    view_->sortByColumn(safety_date, Qt::AscendingOrder);

    view_->selectRow(0);
}

void MainDialog::setupMapperDialog()
{
    MapperDialog *mapperDialog = new MapperDialog(sortFilterProxy_, this);
    mapperDialog_ = static_cast<VyborgMapperDialog *>(mapperDialog);
}

void MainDialog::setupFilterDialog()
{
    filterDialog_->addColumn(trUtf8("Дата на момент события"), safety_date);
    filterDialog_->addColumn(trUtf8("Центр УВД"), safety_ACC_id);
    filterDialog_->addColumn(trUtf8("Структурное подразделегие"), safety_department_id);
    filterDialog_->addColumn(trUtf8("Номер смены"), safety_shiftNum);
    filterDialog_->addColumn(trUtf8("Сектор УВД"), safety_sector_id);
    filterDialog_->addColumn(trUtf8("Наименование пункта УВД"), safety_area);
    filterDialog_->addColumn(trUtf8("Классификация события"), safety_safetyClassification_id);
    filterDialog_->addColumn(trUtf8("Тип события"), safety_safetyType_id);
}

void MainDialog::setupSortDialog()
{
    sortDialog_->addColumn(trUtf8("Дата на момент события"), safety_date);
    sortDialog_->addColumn(trUtf8("Центр УВД"), safety_ACC_id);
    sortDialog_->addColumn(trUtf8("Структурное подразделегие"), safety_department_id);
    sortDialog_->addColumn(trUtf8("Номер смены"), safety_shiftNum);
    sortDialog_->addColumn(trUtf8("Сектор УВД"), safety_sector_id);
    sortDialog_->addColumn(trUtf8("Наименование пункта УВД"), safety_area);
    sortDialog_->addColumn(trUtf8("Классификация события"), safety_safetyClassification_id);
    sortDialog_->addColumn(trUtf8("Тип события"), safety_safetyType_id);
}
