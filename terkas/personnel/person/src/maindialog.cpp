#include <QtWidgets>
#include <QtSql>

#include "maindialog.h"
#include "declarations.h"
#include "mapperdialog.h"
#include "personmodeldelegate.h"



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
    m_model->select();

    m_model->setHeaderData(person_surname, Qt::Horizontal, trUtf8("Фамилия"));
    m_model->setHeaderData(person_name, Qt::Horizontal, trUtf8("Имя"));
    m_model->setHeaderData(person_middlename, Qt::Horizontal, trUtf8("Отчество"));
    m_model->setHeaderData(person_birthday, Qt::Horizontal, trUtf8("Дата рождения"));
    m_model->setHeaderData(person_tabnum, Qt::Horizontal, trUtf8("Табельный номер"));
    m_model->setHeaderData(person_division, Qt::Horizontal, trUtf8("Служба"));
    m_model->setHeaderData(person_subdivision, Qt::Horizontal, trUtf8("Подразделение"));
    m_model->setHeaderData(person_shift, Qt::Horizontal, trUtf8("Номер смены"));
    m_model->setHeaderData(person_position, Qt::Horizontal, trUtf8("Должность"));
    m_model->setHeaderData(person_class, Qt::Horizontal, trUtf8("Класс"));
    m_model->setHeaderData(person_icaolevel, Qt::Horizontal, trUtf8("Уровень ICAO"));
    m_model->setHeaderData(person_sectorgroup, Qt::Horizontal, trUtf8("Рабочее направление"));
}

void MainDialog::setupView()
{
    m_view->setModel(m_model);
//    m_view->setItemDelegate(new PersonModelDelegate(m_view));

    m_view->resizeColumnsToContents();
    m_view->resizeRowsToContents();
    m_view->horizontalHeader()->setStretchLastSection(true);

    m_view->verticalHeader()->show();

    m_view->hideColumn(person_pid);
    m_view->hideColumn(person_icaolevelvalid);
    m_view->hideColumn(person_licencenum);
    m_view->hideColumn(person_licencevalid);
    m_view->hideColumn(person_mobilephone);
    m_view->hideColumn(person_postup);
    m_view->hideColumn(person_medicalvalid);
    m_view->hideColumn(person_sectoradmittance);
    m_view->hideColumn(person_positionadmittance);
    m_view->hideColumn(person_kpkrp);
    m_view->hideColumn(person_kpksd);
    m_view->hideColumn(person_kpkdi);
    m_view->hideColumn(person_kpkfact);
    m_view->hideColumn(person_kpkplan);
    m_view->hideColumn(person_kpkompfact);
    m_view->hideColumn(person_kpkompplan);
    m_view->hideColumn(person_vyssh);
    m_view->hideColumn(person_srednee);
    m_view->hideColumn(person_kursy);
    m_view->hideColumn(person_obrazov);
    m_view->hideColumn(person_gosnagrady);
    m_view->hideColumn(person_otraslnagrady);
    m_view->hideColumn(person_fgupnagrady);
    m_view->hideColumn(person_filialnagrady);

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
