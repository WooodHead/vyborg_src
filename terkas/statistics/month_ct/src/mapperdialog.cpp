#include <QtWidgets>

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
    m_yearLineEdit = new QLineEdit;
    m_janLineEdit  = new QLineEdit;
    m_febLineEdit  = new QLineEdit;
    m_marLineEdit  = new QLineEdit;
    m_aprLineEdit  = new QLineEdit;
    m_mayLineEdit  = new QLineEdit;
    m_junLineEdit  = new QLineEdit;
    m_julLineEdit  = new QLineEdit;
    m_augLineEdit  = new QLineEdit;
    m_sepLineEdit  = new QLineEdit;
    m_octLineEdit  = new QLineEdit;
    m_novLineEdit  = new QLineEdit;
    m_decLineEdit  = new QLineEdit;

    QDataWidgetMapper* m_mapper = mapper();
    m_mapper->addMapping(m_yearLineEdit, month_ct_year);
    m_mapper->addMapping(m_janLineEdit,  month_ct_jan);
    m_mapper->addMapping(m_febLineEdit,  month_ct_feb);
    m_mapper->addMapping(m_marLineEdit,  month_ct_mar);
    m_mapper->addMapping(m_aprLineEdit,  month_ct_apr);
    m_mapper->addMapping(m_mayLineEdit,  month_ct_may);
    m_mapper->addMapping(m_junLineEdit,  month_ct_jun);
    m_mapper->addMapping(m_julLineEdit,  month_ct_jul);
    m_mapper->addMapping(m_augLineEdit,  month_ct_aug);
    m_mapper->addMapping(m_sepLineEdit,  month_ct_sep);
    m_mapper->addMapping(m_octLineEdit,  month_ct_oct);
    m_mapper->addMapping(m_novLineEdit,  month_ct_nov);
    m_mapper->addMapping(m_decLineEdit,  month_ct_dec);
//    m_mapper->setItemDelegate(new MapperDelegate);
}

void MapperDialog::layoutPrivateWidgets()
{
    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(QString("Год"),      m_yearLineEdit);
    formLayout->addRow(QString("Январь"),   m_janLineEdit);
    formLayout->addRow(QString("Февраль"),  m_febLineEdit);
    formLayout->addRow(QString("Март"),     m_marLineEdit);
    formLayout->addRow(QString("Апрель"),   m_aprLineEdit);
    formLayout->addRow(QString("Май"),      m_mayLineEdit);
    formLayout->addRow(QString("Июнь"),     m_junLineEdit);
    formLayout->addRow(QString("Июль"),     m_julLineEdit);
    formLayout->addRow(QString("Август"),   m_augLineEdit);
    formLayout->addRow(QString("Сентябрь"), m_sepLineEdit);
    formLayout->addRow(QString("Октябрь"),  m_octLineEdit);
    formLayout->addRow(QString("Ноябрь"),   m_novLineEdit);
    formLayout->addRow(QString("Декабрь"),  m_decLineEdit);

    QVBoxLayout *privateWidgetsLayout = layout();
    privateWidgetsLayout->addLayout(formLayout);
}

void MapperDialog::updatePrivateWidgets()
{
    if (state() == Normal) {
//        m_dateEdit->setReadOnly(true);
////        m_shiftEdit->setReadOnly(true);
//        m_locationEdit->setReadOnly(true);
//        m_causeEdit->setReadOnly(true);
//        m_factorEdit->setReadOnly(true);
//        m_detailsEdit->setReadOnly(true);
////        m_sectorEdit->setReadOnly(true);
//        m_accCombo->setEditable(false);
//        m_classificationCombo->setEditable(false);
//        m_typeCombo->setEditable(false);
//        m_terkasCombo->setEditable(false);
//        m_alphaCombo->setEditable(false);
//        m_tcas1Combo->setEditable(false);
//        m_tcas2Combo->setEditable(false);
    } else {
//        m_dateEdit->setReadOnly(false);
////        m_shiftEdit->setReadOnly(false);
//        m_locationEdit->setReadOnly(false);
//        m_causeEdit->setReadOnly(false);
//        m_factorEdit->setReadOnly(false);
//        m_detailsEdit->setReadOnly(false);
////        m_sectorEdit->setReadOnly(false);
//        m_accCombo->setEditable(true);
//        m_classificationCombo->setEditable(true);
//        m_typeCombo->setEditable(true);
//        m_terkasCombo->setEditable(true);
//        m_alphaCombo->setEditable(true);
//        m_tcas1Combo->setEditable(true);
//        m_tcas2Combo->setEditable(true);

//        m_dateEdit->setFocus();
    }
}
