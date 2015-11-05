#include <QtWidgets>
#include <QtSql>

#include "mapperdialog.h"
#include "declarations.h"


MapperDialog::MapperDialog(QSqlRelationalTableModel *model, QWidget *parent)
    : VyborgMapperDialog(model, parent)
{
    createPrivateWidgets();
    layoutPrivateWidgets();
    updatePrivateWidgets();
}

void MapperDialog::createPrivateWidgets()
{
    m_surnameLE = new QLineEdit;
    m_nameLE = new QLineEdit;
    m_middlenameLE = new QLineEdit;
    m_tabnumLE = new QLineEdit;
    m_birthdayLE = new QLineEdit;
    m_positionLE = new QLineEdit;
    m_divisionLE = new QLineEdit;
    m_subdivisionLE = new QLineEdit;
    m_shiftLE = new QLineEdit;
    m_classLE = new QLineEdit;
    m_icaolevelLE = new QLineEdit;
    m_icaoleveldateLE = new QLineEdit;
    m_licencenumLE = new QLineEdit;
    m_licencevalidLE = new QLineEdit;
    m_mobilephoneLE = new QLineEdit;
    m_stazhLE = new QLineEdit;
    m_postupLE = new QLineEdit;
    m_medicalvalidLE = new QLineEdit;
    m_sectorgroupLE = new QLineEdit;
    m_sectoradmittanceLE = new QLineEdit;
    m_positionadmittanceLE = new QLineEdit;
    m_kpkrpLE = new QLineEdit;
    m_kpksdLE = new QLineEdit;
    m_kpkdiLE = new QLineEdit;
    m_kpkfactLE = new QLineEdit;
    m_kpkplanLE = new QLineEdit;
    m_kpkompfactLE = new QLineEdit;
    m_kpkompplanLE = new QLineEdit;
    m_vysshLE = new QLineEdit;
    m_sredneeLE = new QLineEdit;
    m_kursyLE = new QLineEdit;
    m_obrazovLE = new QLineEdit;
    m_gosnagradyLE = new QLineEdit;
    m_otraslnagradyLE = new QLineEdit;
    m_fgupnagradyLE = new QLineEdit;
    m_filialnagradyLE = new QLineEdit;


    QDataWidgetMapper* m_mapper = mapper();
    m_mapper->addMapping(m_surnameLE, person_surname);
    m_mapper->addMapping(m_nameLE, person_name);
    m_mapper->addMapping(m_middlenameLE, person_middlename);
    m_mapper->addMapping(m_tabnumLE, person_tabnum);
    m_mapper->addMapping(m_birthdayLE, person_birthday);
    m_mapper->addMapping(m_positionLE, person_position);
    m_mapper->addMapping(m_divisionLE, person_division);
    m_mapper->addMapping(m_subdivisionLE, person_subdivision);
    m_mapper->addMapping(m_shiftLE, person_shift);
    m_mapper->addMapping(m_classLE, person_class);
    m_mapper->addMapping(m_icaolevelLE, person_icaolevel);
    m_mapper->addMapping(m_icaoleveldateLE, person_icaoleveldate);
    m_mapper->addMapping(m_licencenumLE, person_licencenum);
    m_mapper->addMapping(m_licencevalidLE, person_licencevalid);
    m_mapper->addMapping(m_mobilephoneLE, person_mobilephone);
    m_mapper->addMapping(m_stazhLE, person_stazh);
    m_mapper->addMapping(m_postupLE, person_postup);
    m_mapper->addMapping(m_medicalvalidLE, person_medicalvalid);
    m_mapper->addMapping(m_sectorgroupLE, person_sectorgroup);
    m_mapper->addMapping(m_sectoradmittanceLE, person_sectoradmittance);
    m_mapper->addMapping(m_positionadmittanceLE, person_positionadmittance);
    m_mapper->addMapping(m_kpkrpLE, person_kpkrp);
    m_mapper->addMapping(m_kpksdLE, person_kpksd);
    m_mapper->addMapping(m_kpkdiLE, person_kpkdi);
    m_mapper->addMapping(m_kpkfactLE, person_kpkfact);
    m_mapper->addMapping(m_kpkplanLE, person_kpkplan);
    m_mapper->addMapping(m_kpkompfactLE, person_kpkompfact);
    m_mapper->addMapping(m_kpkompplanLE, person_kpkompplan);
    m_mapper->addMapping(m_vysshLE, person_vyssh);
    m_mapper->addMapping(m_sredneeLE, person_srednee);
    m_mapper->addMapping(m_kursyLE, person_kursy);
    m_mapper->addMapping(m_obrazovLE, person_obrazov);
    m_mapper->addMapping(m_gosnagradyLE, person_gosnagrady);
    m_mapper->addMapping(m_otraslnagradyLE, person_otraslnagrady);
    m_mapper->addMapping(m_fgupnagradyLE, person_fgupnagrady);
    m_mapper->addMapping(m_filialnagradyLE, person_filialnagrady);
}

void MapperDialog::layoutPrivateWidgets()
{
    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(trUtf8("Фамилия"), m_surnameLE);
    formLayout->addRow(trUtf8("Имя"), m_nameLE);
    formLayout->addRow(trUtf8("Отчество"), m_middlenameLE);
    formLayout->addRow(trUtf8("Табельный номер"), m_tabnumLE);
    formLayout->addRow(trUtf8("Дата рождения"), m_birthdayLE);
    formLayout->addRow(trUtf8("Должность"), m_positionLE);
    formLayout->addRow(trUtf8("Служба"), m_divisionLE);
    formLayout->addRow(trUtf8("Подразделение"), m_subdivisionLE);
    formLayout->addRow(trUtf8("Номер смены"), m_shiftLE);
    formLayout->addRow(trUtf8("Класс"), m_classLE);
    formLayout->addRow(trUtf8("Уровень ИКАО"), m_icaolevelLE);
    formLayout->addRow(trUtf8("Уровень ИКАО (срок действия)"), m_icaoleveldateLE);
    formLayout->addRow(trUtf8("Свидетельство (номер)"), m_licencenumLE);
    formLayout->addRow(trUtf8("Свидетельство (срок действия)"), m_licencevalidLE);
    formLayout->addRow(trUtf8("Номер мобильного телефона"), m_mobilephoneLE);
    formLayout->addRow(trUtf8("Стаж работы"), m_stazhLE);
    formLayout->addRow(trUtf8("Дата поступления в МЦ"), m_postupLE);
    formLayout->addRow(trUtf8("ВЛЭК (дата)"), m_medicalvalidLE);
    formLayout->addRow(trUtf8("Рабочее направление"), m_sectorgroupLE);
    formLayout->addRow(trUtf8("Допуска на секторы"), m_sectoradmittanceLE);
    formLayout->addRow(trUtf8("Допуска к работе"), m_positionadmittanceLE);
    formLayout->addRow(trUtf8("КПК РП (дата прохождения)"), m_kpkrpLE);
    formLayout->addRow(trUtf8("КПК СД (дата прохождения)"), m_kpksdLE);
    formLayout->addRow(trUtf8("КПК ДИ (дата прохождения)"), m_kpkdiLE);
    formLayout->addRow(trUtf8("КПК (дата прохождения)"), m_kpkfactLE);
    formLayout->addRow(trUtf8("КПК (дата запланированная)"), m_kpkplanLE);
    formLayout->addRow(trUtf8("КПК ОМП (дата прохождения)"), m_kpkompfactLE);
    formLayout->addRow(trUtf8("КПК ОМП (дата запланированная)"), m_kpkompplanLE);
    formLayout->addRow(trUtf8("Образование (высшее)"), m_vysshLE);
    formLayout->addRow(trUtf8("Образование (среднее)"), m_sredneeLE);
    formLayout->addRow(trUtf8("Дополнительные курсы"), m_kursyLE);
    formLayout->addRow(trUtf8("Образование"), m_obrazovLE);
    formLayout->addRow(trUtf8("Награды (государственные)"), m_gosnagradyLE);
    formLayout->addRow(trUtf8("Награды (отраслевые)"), m_otraslnagradyLE);
    formLayout->addRow(trUtf8("Награды (от Госкорпорации)"), m_fgupnagradyLE);
    formLayout->addRow(trUtf8("Награды (от филиала)"), m_filialnagradyLE);

    QVBoxLayout *privateWidgetsLayout = layout();
    privateWidgetsLayout->addLayout(formLayout);
}

void MapperDialog::updatePrivateWidgets()
{
    if (isDirty())
    {
        m_surnameLE->setReadOnly(false);
//        m_nameLineEdit->setReadOnly(false);
//        m_middlenameLineEdit->setReadOnly(false);
//        m_innernumLineEdit->setReadOnly(false);
//        m_shiftNumLineEdit->setReadOnly(false);
//        m_sectorsLineEdit->setReadOnly(false);
//        m_phonemobileLineEdit->setReadOnly(false);
//        m_birthdayLineEdit->setReadOnly(false);
    }
    else
    {
        m_surnameLE->setReadOnly(true);
//        m_nameLineEdit->setReadOnly(true);
//        m_middlenameLineEdit->setReadOnly(true);
//        m_innernumLineEdit->setReadOnly(true);
//        m_shiftNumLineEdit->setReadOnly(true);
//        m_sectorsLineEdit->setReadOnly(true);
//        m_phonemobileLineEdit->setReadOnly(true);
//        m_birthdayLineEdit->setReadOnly(true);
    }
}
