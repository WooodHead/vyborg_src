#include <QtWidgets>

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
    m_labelLineEdit = new QLineEdit;
    m_fullnameLineEdit = new QLineEdit;
    m_sectorLineEdit = new QLineEdit;
    m_compoundLineEdit = new QLineEdit;

    QDataWidgetMapper* m_mapper = mapper();
    m_mapper->addMapping(m_labelLineEdit,  sector_label);
    m_mapper->addMapping(m_fullnameLineEdit,  sector_fullname);
    m_mapper->addMapping(m_sectorLineEdit,  sector_sector);
    m_mapper->addMapping(m_compoundLineEdit,  sector_compound);
}

void MapperDialog::layoutPrivateWidgets()
{
    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("label:", m_labelLineEdit);
    formLayout->addRow("fullname:", m_fullnameLineEdit);
    formLayout->addRow("sector:", m_sectorLineEdit);
    formLayout->addRow("compound:", m_compoundLineEdit);

    QVBoxLayout *privateWidgetsLayout = layout();
    privateWidgetsLayout->addLayout(formLayout);
}

void MapperDialog::updatePrivateWidgets()
{
    if (isDirty())
    {
//        m_activityLineEdit->setReadOnly(false);
//        m_sectorpidLineEdit->setReadOnly(false);
//        m_startDateEdit->setReadOnly(false);
//        m_stopDateEdit->setReadOnly(false);
    }
    else
    {
//        m_activityLineEdit->setReadOnly(true);
//        m_sectorpidLineEdit->setReadOnly(true);
//        m_startDateEdit->setReadOnly(true);
//        m_stopDateEdit->setReadOnly(true);
    }
}
