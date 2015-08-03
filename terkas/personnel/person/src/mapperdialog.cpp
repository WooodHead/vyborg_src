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
    m_phonemobileLineEdit = new QLineEdit;

    QDataWidgetMapper* m_mapper = mapper();
    m_mapper->addMapping(m_surnameLineEdit,     person_surname);
    m_mapper->addMapping(m_nameLineEdit,        person_name);
    m_mapper->addMapping(m_middlenameLineEdit,  person_middlename);
    m_mapper->addMapping(m_innernumLineEdit,    person_innernum);
    m_mapper->addMapping(m_phonemobileLineEdit, person_phonemobile);
}

void MapperDialog::layoutPrivateWidgets()
{
    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("Surname",      m_surnameLineEdit);
    formLayout->addRow("Name",         m_nameLineEdit);
    formLayout->addRow("Middle Name",  m_middlenameLineEdit);
    formLayout->addRow("Inner ID",     m_innernumLineEdit);
    formLayout->addRow("Mobile Phone", m_phonemobileLineEdit);

    QVBoxLayout *privateWidgetsLayout = layout();
    privateWidgetsLayout->addLayout(formLayout);
}

void MapperDialog::updatePrivateWidgets()
{
    if (isDirty() == true)
    {
//        surnameLineEdit->setReadOnly(false);
//        nameLineEdit->setReadOnly(false);
//        middleNameLineEdit->setReadOnly(false);
//        innerIdLineEdit->setReadOnly(false);
//        mobilePhoneLineEdit->setReadOnly(false);
    }
    else
    {
//        surnameLineEdit->setReadOnly(true);
//        nameLineEdit->setReadOnly(true);
//        middleNameLineEdit->setReadOnly(true);
//        innerIdLineEdit->setReadOnly(true);
//        mobilePhoneLineEdit->setReadOnly(true);
    }
}
