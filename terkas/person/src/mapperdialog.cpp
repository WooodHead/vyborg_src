#include <QtWidgets>
#include <QtSql>

#include "mapperdialog.h"
#include "declarations.h"


MapperDialog::MapperDialog(QSortFilterProxyModel *proxy, QWidget *parent)
    : VyborgMapperDialog(proxy, parent)
{
    createPrivateWidgets();
    layoutPrivateWidgets();
    updatePrivateWidgets();
}

void MapperDialog::createPrivateWidgets()
{
    surnameLineEdit     = new QLineEdit;
    nameLineEdit        = new QLineEdit;
    middleNameLineEdit  = new QLineEdit;
    innerIdLineEdit     = new QLineEdit;
    mobilePhoneLineEdit = new QLineEdit;

    mapper_->addMapping(surnameLineEdit,     person_surname);
    mapper_->addMapping(nameLineEdit,        person_name);
    mapper_->addMapping(middleNameLineEdit,  person_middleName);
    mapper_->addMapping(innerIdLineEdit,     person_innerID);
    mapper_->addMapping(mobilePhoneLineEdit, person_mobilePhone);
}

void MapperDialog::layoutPrivateWidgets()
{
    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("Surname",      surnameLineEdit);
    formLayout->addRow("Name",         nameLineEdit);
    formLayout->addRow("Middle Name",  middleNameLineEdit);
    formLayout->addRow("Inner ID",     innerIdLineEdit);
    formLayout->addRow("Mobile Phone", mobilePhoneLineEdit);

    privateWidgetsLayout->addLayout(formLayout);
}

void MapperDialog::updatePrivateWidgets()
{
    if (dirty_ == true)
    {
        surnameLineEdit->setReadOnly(false);
        nameLineEdit->setReadOnly(false);
        middleNameLineEdit->setReadOnly(false);
        innerIdLineEdit->setReadOnly(false);
        mobilePhoneLineEdit->setReadOnly(false);
    }
    else
    {
        surnameLineEdit->setReadOnly(true);
        nameLineEdit->setReadOnly(true);
        middleNameLineEdit->setReadOnly(true);
        innerIdLineEdit->setReadOnly(true);
        mobilePhoneLineEdit->setReadOnly(true);
    }
}
