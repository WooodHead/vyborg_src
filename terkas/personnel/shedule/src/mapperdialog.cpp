#include <QtWidgets>

#include "mapperdialog.h"
#include "declarations.h"
//#include "mapperdelegate.h"

MapperDialog::MapperDialog(QSqlRelationalTableModel *model, QWidget *parent)
    : VyborgMapperDialog(model, parent)
{
    createPrivateWidgets();
    layoutPrivateWidgets();
    updatePrivateWidgets();
}

void MapperDialog::createPrivateWidgets()
{
//    m_dateEdit            = new QDateEdit;
//    m_dateEdit->setDisplayFormat("yyyy MMMM dd");

    m_nameLineEdit = new QLineEdit;
    m_middlenameLineEdit = new QLineEdit;
    m_surnameLineEdit = new QLineEdit;
    m_activityLineEdit = new QLineEdit;
    m_sectorpidLineEdit = new QLineEdit;

    m_startDateEdit = new QDateEdit;
    m_stopDateEdit = new QDateEdit;


    QDataWidgetMapper* m_mapper = mapper();
    m_mapper->addMapping(m_nameLineEdit,       shedule_name);
    m_mapper->addMapping(m_middlenameLineEdit, shedule_middlename);
    m_mapper->addMapping(m_surnameLineEdit,    shedule_surname);
    m_mapper->addMapping(m_activityLineEdit,   shedule_activity);
    m_mapper->addMapping(m_sectorpidLineEdit,  shedule_sector_pid);
    m_mapper->addMapping(m_startDateEdit,      shedule_start);
    m_mapper->addMapping(m_stopDateEdit,       shedule_stop);
}

void MapperDialog::layoutPrivateWidgets()
{
//    QGridLayout *gridLayout = new QGridLayout;
//    gridLayout->addLayout(dateLocationLayout,   0, 0, 1, 2);
//    gridLayout->addLayout(accSectorShiftLayout, 1, 0, 1, 2);
//    gridLayout->addWidget(classificationLabel,  2, 0, 1, 1);    gridLayout->addWidget(m_classificationCombo,  2, 1, 1, 1);
//    gridLayout->addWidget(typeLabel,            3, 0, 1, 1);    gridLayout->addWidget(m_typeCombo,            3, 1, 1, 1);
//    gridLayout->addLayout(atcSposLayout,        4, 0, 1, 2);
//    gridLayout->addLayout(tcasLayout,           5, 0, 1, 2);
//    gridLayout->addWidget(causeLabel,           6, 0, 1, 1);    gridLayout->addWidget(m_causeEdit,            6, 1, 1, 1);
//    gridLayout->addWidget(factorLabel,          7, 0, 1, 1);    gridLayout->addWidget(m_factorEdit,           7, 1, 1, 1);
//    gridLayout->addWidget(detailsLabel,         8, 0, 1, 1);    gridLayout->addWidget(m_detailsEdit,          8, 1, 1, 1);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("Имя:", m_nameLineEdit);
    formLayout->addRow("Отчество:", m_middlenameLineEdit);
    formLayout->addRow("Фамилия:", m_surnameLineEdit);
    formLayout->addRow("Сектор:", m_sectorpidLineEdit);
    formLayout->addRow("Вид деятельности:", m_activityLineEdit);
    formLayout->addRow("Дата начала:", m_startDateEdit);
    formLayout->addRow("Дата окончания:", m_stopDateEdit);

    QVBoxLayout *privateWidgetsLayout = layout();
    privateWidgetsLayout->addLayout(formLayout);
}

void MapperDialog::updatePrivateWidgets()
{
    if (isDirty()) {
//        m_dateEdit->setReadOnly(false);
//        m_shiftEdit->setReadOnly(false);
//        m_locationEdit->setReadOnly(false);
//        m_causeEdit->setReadOnly(false);
//        m_factorEdit->setReadOnly(false);
//        m_detailsEdit->setReadOnly(false);
//        m_sectorEdit->setReadOnly(false);
//        m_accCombo->setEditable(true);
//        m_classificationCombo->setEditable(true);
//        m_typeCombo->setEditable(true);
//        m_terkasCombo->setEditable(true);
//        m_alphaCombo->setEditable(true);
//        m_tcas1Combo->setEditable(true);
//        m_tcas2Combo->setEditable(true);

//        m_dateEdit->setFocus();
    } else {
//        m_dateEdit->setReadOnly(true);
//        m_shiftEdit->setReadOnly(true);
//        m_locationEdit->setReadOnly(true);
//        m_causeEdit->setReadOnly(true);
//        m_factorEdit->setReadOnly(true);
//        m_detailsEdit->setReadOnly(true);
//        m_sectorEdit->setReadOnly(true);
//        m_accCombo->setEditable(false);
//        m_classificationCombo->setEditable(false);
//        m_typeCombo->setEditable(false);
//        m_terkasCombo->setEditable(false);
//        m_alphaCombo->setEditable(false);
//        m_tcas1Combo->setEditable(false);
//        m_tcas2Combo->setEditable(false);
    }
}
