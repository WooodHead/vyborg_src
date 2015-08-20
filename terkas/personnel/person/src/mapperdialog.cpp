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
    m_surnameLineEdit     = new QLineEdit;
    m_nameLineEdit        = new QLineEdit;
    m_middlenameLineEdit  = new QLineEdit;
    m_innernumLineEdit    = new QLineEdit;
    m_shiftNumLineEdit    = new QLineEdit;
    m_sectorsLineEdit     = new QLineEdit;
    m_phonemobileLineEdit = new QLineEdit;
    m_birthdayLineEdit    = new QLineEdit;

    QDataWidgetMapper* m_mapper = mapper();
    m_mapper->addMapping(m_surnameLineEdit,     person_surname);
    m_mapper->addMapping(m_nameLineEdit,        person_name);
    m_mapper->addMapping(m_middlenameLineEdit,  person_middlename);
    m_mapper->addMapping(m_innernumLineEdit,    person_innernum);
    m_mapper->addMapping(m_shiftNumLineEdit,    person_shiftnum);
    m_mapper->addMapping(m_sectorsLineEdit,     person_sectors);
    m_mapper->addMapping(m_phonemobileLineEdit, person_phonemobile);
    m_mapper->addMapping(m_birthdayLineEdit,    person_birthday);
}

void MapperDialog::layoutPrivateWidgets()
{
    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("Surname",      m_surnameLineEdit);
    formLayout->addRow("Name",         m_nameLineEdit);
    formLayout->addRow("Middle Name",  m_middlenameLineEdit);
    formLayout->addRow("Inner ID",     m_innernumLineEdit);
    formLayout->addRow("Номер смены:", m_shiftNumLineEdit);
    formLayout->addRow("Допуски на секторах:", m_sectorsLineEdit);
    formLayout->addRow("Mobile Phone", m_phonemobileLineEdit);
    formLayout->addRow("Дата рождения:", m_birthdayLineEdit);

    QVBoxLayout *privateWidgetsLayout = layout();
    privateWidgetsLayout->addLayout(formLayout);
}

void MapperDialog::updatePrivateWidgets()
{
    if (isDirty())
    {
        m_surnameLineEdit->setReadOnly(false);
        m_nameLineEdit->setReadOnly(false);
        m_middlenameLineEdit->setReadOnly(false);
        m_innernumLineEdit->setReadOnly(false);
        m_shiftNumLineEdit->setReadOnly(false);
        m_sectorsLineEdit->setReadOnly(false);
        m_phonemobileLineEdit->setReadOnly(false);
        m_birthdayLineEdit->setReadOnly(false);
    }
    else
    {
        m_surnameLineEdit->setReadOnly(true);
        m_nameLineEdit->setReadOnly(true);
        m_middlenameLineEdit->setReadOnly(true);
        m_innernumLineEdit->setReadOnly(true);
        m_shiftNumLineEdit->setReadOnly(true);
        m_sectorsLineEdit->setReadOnly(true);
        m_phonemobileLineEdit->setReadOnly(true);
        m_birthdayLineEdit->setReadOnly(true);
    }
}
