#include <QtWidgets>
#include <QtSql>

#include "mapperdialog.h"
#include "declarations.h"
#include "mapperdelegate.h"


MapperDialog::MapperDialog(QSqlTableModel *model, QWidget *parent)
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
    m_divisionLE = new QLineEdit;
    m_subdivisionLE = new QLineEdit;
    m_shiftLE = new QLineEdit;
    m_classLE = new QLineEdit;
    m_icaolevelLE = new QLineEdit;
    m_icaolevelvalidLE = new QLineEdit;
    m_licencenumLE = new QLineEdit;
    m_licencevalidLE = new QLineEdit;
    m_mobilephoneLE = new QLineEdit;
    m_stazhLE = new QLineEdit;
    m_postupLE = new QLineEdit;
    m_medicalvalidLE = new QLineEdit;
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

    m_positionCB = new QComboBox;
    m_sectorgroupCB = new QComboBox;


    QDataWidgetMapper* m_mapper = mapper();
    m_mapper->addMapping(m_surnameLE, person_surname);
    m_mapper->addMapping(m_nameLE, person_name);
    m_mapper->addMapping(m_middlenameLE, person_middlename);
    m_mapper->addMapping(m_tabnumLE, person_tabnum);
    m_mapper->addMapping(m_birthdayLE, person_birthday);
    m_mapper->addMapping(m_positionCB, person_position);
    m_mapper->addMapping(m_divisionLE, person_division);
    m_mapper->addMapping(m_subdivisionLE, person_subdivision);
    m_mapper->addMapping(m_shiftLE, person_shift);
    m_mapper->addMapping(m_classLE, person_class);
    m_mapper->addMapping(m_icaolevelLE, person_icaolevel);
    m_mapper->addMapping(m_icaolevelvalidLE, person_icaolevelvalid);
    m_mapper->addMapping(m_licencenumLE, person_licencenum);
    m_mapper->addMapping(m_licencevalidLE, person_licencevalid);
    m_mapper->addMapping(m_mobilephoneLE, person_mobilephone);
    m_mapper->addMapping(m_stazhLE, person_stazh);
    m_mapper->addMapping(m_postupLE, person_postup);
    m_mapper->addMapping(m_medicalvalidLE, person_medicalvalid);
    m_mapper->addMapping(m_sectorgroupCB, person_sectorgroup);
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
    m_mapper->setItemDelegate(new MapperDelegate);
}

void MapperDialog::layoutPrivateWidgets()
{
    // Основные данные

    QHBoxLayout *nameLayout = new QHBoxLayout;
    nameLayout->addWidget(m_surnameLE);
    nameLayout->addWidget(m_nameLE);
    nameLayout->addWidget(m_middlenameLE);

    QFormLayout *formLayout1 = new QFormLayout;
    formLayout1->addRow(trUtf8("Табельный номер"), m_tabnumLE);
    formLayout1->addRow(trUtf8("Дата рождения"), m_birthdayLE);
    formLayout1->addRow(trUtf8("Должность"), m_positionCB);
    formLayout1->addRow(trUtf8("Служба"), m_divisionLE);
    formLayout1->addRow(trUtf8("Подразделение"), m_subdivisionLE);
    formLayout1->addRow(trUtf8("Номер смены"), m_shiftLE);
    formLayout1->addRow(trUtf8("Класс"), m_classLE);
    formLayout1->addRow(trUtf8("Уровень ИКАО"), m_icaolevelLE);
    formLayout1->addRow(trUtf8("Свидетельство (номер)"), m_licencenumLE);
    formLayout1->addRow(trUtf8("Номер мобильного телефона"), m_mobilephoneLE);
    formLayout1->addRow(trUtf8("Стаж работы"), m_stazhLE);
    formLayout1->addRow(trUtf8("Дата поступления в МЦ"), m_postupLE);
    formLayout1->addRow(trUtf8("Рабочее направление"), m_sectorgroupCB);

    QWidget *page1 = new QWidget;
    page1->setLayout(formLayout1);


    // Допуски

    QFormLayout *formLayout6 = new QFormLayout;
    formLayout6->addRow(trUtf8("Допуска на секторы"), m_sectoradmittanceLE);
    formLayout6->addRow(trUtf8("Допуска к работе"), m_positionadmittanceLE);

    QWidget *page6 = new QWidget;
    page6->setLayout(formLayout6);


    // Сроки действия

    QFormLayout *formLayout5 = new QFormLayout;
    formLayout5->addRow(trUtf8("Уровень ИКАО (срок действия)"), m_icaolevelvalidLE);
    formLayout5->addRow(trUtf8("Свидетельство (срок действия)"), m_licencevalidLE);
    formLayout5->addRow(trUtf8("ВЛЭК (дата)"), m_medicalvalidLE);

    QWidget *page5 = new QWidget;
    page5->setLayout(formLayout5);


    // КПК

    QFormLayout *formLayout2 = new QFormLayout;
    formLayout2->addRow(trUtf8("КПК РП (дата прохождения)"), m_kpkrpLE);
    formLayout2->addRow(trUtf8("КПК СД (дата прохождения)"), m_kpksdLE);
    formLayout2->addRow(trUtf8("КПК ДИ (дата прохождения)"), m_kpkdiLE);
    formLayout2->addRow(trUtf8("КПК (дата прохождения)"), m_kpkfactLE);
    formLayout2->addRow(trUtf8("КПК (дата запланированная)"), m_kpkplanLE);
    formLayout2->addRow(trUtf8("КПК ОМП (дата прохождения)"), m_kpkompfactLE);
    formLayout2->addRow(trUtf8("КПК ОМП (дата запланированная)"), m_kpkompplanLE);

    QWidget *page2 = new QWidget;
    page2->setLayout(formLayout2);


    // Образование

    QFormLayout *formLayout4 = new QFormLayout;
    formLayout4->addRow(trUtf8("Образование (высшее)"), m_vysshLE);
    formLayout4->addRow(trUtf8("Образование (среднее)"), m_sredneeLE);
    formLayout4->addRow(trUtf8("Дополнительные курсы"), m_kursyLE);
    formLayout4->addRow(trUtf8("Образование"), m_obrazovLE);

    QWidget *page4 = new QWidget;
    page4->setLayout(formLayout4);


    // Награды

    QFormLayout *formLayout3 = new QFormLayout;
    formLayout3->addRow(trUtf8("Награды (государственные)"), m_gosnagradyLE);
    formLayout3->addRow(trUtf8("Награды (отраслевые)"), m_otraslnagradyLE);
    formLayout3->addRow(trUtf8("Награды (от Госкорпорации)"), m_fgupnagradyLE);
    formLayout3->addRow(trUtf8("Награды (от филиала)"), m_filialnagradyLE);

    QWidget *page3 = new QWidget;
    page3->setLayout(formLayout3);



    QTabWidget *tabWidget = new QTabWidget;
    tabWidget->addTab(page1, trUtf8("Основные данные"));
    tabWidget->addTab(page6, trUtf8("Допуски"));
    tabWidget->addTab(page5, trUtf8("Сроки действия"));
    tabWidget->addTab(page2, trUtf8("КПК"));
    tabWidget->addTab(page4, trUtf8("Образование"));
    tabWidget->addTab(page3, trUtf8("Награды"));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(nameLayout);
    mainLayout->addWidget(tabWidget);

    QVBoxLayout *privateWidgetsLayout = layout();
    privateWidgetsLayout->addLayout(mainLayout);
}

void MapperDialog::updatePrivateWidgets()
{
    if (isDirty())
    {
        m_surnameLE->setReadOnly(false);
        m_nameLE->setReadOnly(false);
        m_middlenameLE->setReadOnly(false);
        m_tabnumLE->setReadOnly(false);
        m_birthdayLE->setReadOnly(false);
        m_divisionLE->setReadOnly(false);
        m_subdivisionLE->setReadOnly(false);
        m_shiftLE->setReadOnly(false);
        m_classLE->setReadOnly(false);
        m_icaolevelLE->setReadOnly(false);
        m_icaolevelvalidLE->setReadOnly(false);
        m_licencenumLE->setReadOnly(false);
        m_licencevalidLE->setReadOnly(false);
        m_mobilephoneLE->setReadOnly(false);
        m_stazhLE->setReadOnly(false);
        m_postupLE->setReadOnly(false);
        m_medicalvalidLE->setReadOnly(false);
        m_sectoradmittanceLE->setReadOnly(false);
        m_positionadmittanceLE->setReadOnly(false);
        m_kpkrpLE->setReadOnly(false);
        m_kpksdLE->setReadOnly(false);
        m_kpkdiLE->setReadOnly(false);
        m_kpkfactLE->setReadOnly(false);
        m_kpkplanLE->setReadOnly(false);
        m_kpkompfactLE->setReadOnly(false);
        m_kpkompplanLE->setReadOnly(false);
        m_vysshLE->setReadOnly(false);
        m_sredneeLE->setReadOnly(false);
        m_kursyLE->setReadOnly(false);
        m_obrazovLE->setReadOnly(false);
        m_gosnagradyLE->setReadOnly(false);
        m_otraslnagradyLE->setReadOnly(false);
        m_fgupnagradyLE->setReadOnly(false);
        m_filialnagradyLE->setReadOnly(false);

        m_positionCB->setEditable(false);
        m_sectorgroupCB->setEditable(false);
    }
    else
    {
        m_surnameLE->setReadOnly(true);
        m_nameLE->setReadOnly(true);
        m_middlenameLE->setReadOnly(true);
        m_tabnumLE->setReadOnly(true);
        m_birthdayLE->setReadOnly(true);
        m_divisionLE->setReadOnly(true);
        m_subdivisionLE->setReadOnly(true);
        m_shiftLE->setReadOnly(true);
        m_classLE->setReadOnly(true);
        m_icaolevelLE->setReadOnly(true);
        m_icaolevelvalidLE->setReadOnly(true);
        m_licencenumLE->setReadOnly(true);
        m_licencevalidLE->setReadOnly(true);
        m_mobilephoneLE->setReadOnly(true);
        m_stazhLE->setReadOnly(true);
        m_postupLE->setReadOnly(true);
        m_medicalvalidLE->setReadOnly(true);
        m_sectoradmittanceLE->setReadOnly(true);
        m_positionadmittanceLE->setReadOnly(true);
        m_kpkrpLE->setReadOnly(true);
        m_kpksdLE->setReadOnly(true);
        m_kpkdiLE->setReadOnly(true);
        m_kpkfactLE->setReadOnly(true);
        m_kpkplanLE->setReadOnly(true);
        m_kpkompfactLE->setReadOnly(true);
        m_kpkompplanLE->setReadOnly(true);
        m_vysshLE->setReadOnly(true);
        m_sredneeLE->setReadOnly(true);
        m_kursyLE->setReadOnly(true);
        m_obrazovLE->setReadOnly(true);
        m_gosnagradyLE->setReadOnly(true);
        m_otraslnagradyLE->setReadOnly(true);
        m_fgupnagradyLE->setReadOnly(true);
        m_filialnagradyLE->setReadOnly(true);

        m_positionCB->setEditable(false);
        m_sectorgroupCB->setEditable(false);
    }
}
