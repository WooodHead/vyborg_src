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
    m_yearSpinBox = new QSpinBox;
    m_yearSpinBox->setMaximum(2025);
    m_janSpinBox  = new QSpinBox;
    m_janSpinBox->setMaximum(1000000);
    m_febSpinBox  = new QSpinBox;
    m_febSpinBox->setMaximum(1000000);
    m_marSpinBox  = new QSpinBox;
    m_marSpinBox->setMaximum(1000000);
    m_aprSpinBox  = new QSpinBox;
    m_aprSpinBox->setMaximum(1000000);
    m_maySpinBox  = new QSpinBox;
    m_maySpinBox->setMaximum(1000000);
    m_junSpinBox  = new QSpinBox;
    m_junSpinBox->setMaximum(1000000);
    m_julSpinBox  = new QSpinBox;
    m_julSpinBox->setMaximum(1000000);
    m_augSpinBox  = new QSpinBox;
    m_augSpinBox->setMaximum(1000000);
    m_sepSpinBox  = new QSpinBox;
    m_sepSpinBox->setMaximum(1000000);
    m_octSpinBox  = new QSpinBox;
    m_octSpinBox->setMaximum(1000000);
    m_novSpinBox  = new QSpinBox;
    m_novSpinBox->setMaximum(1000000);
    m_decSpinBox  = new QSpinBox;
    m_decSpinBox->setMaximum(1000000);

    QDataWidgetMapper* m_mapper = mapper();
    m_mapper->addMapping(m_yearSpinBox, month_ct_year);
    m_mapper->addMapping(m_janSpinBox,  month_ct_jan);
    m_mapper->addMapping(m_febSpinBox,  month_ct_feb);
    m_mapper->addMapping(m_marSpinBox,  month_ct_mar);
    m_mapper->addMapping(m_aprSpinBox,  month_ct_apr);
    m_mapper->addMapping(m_maySpinBox,  month_ct_may);
    m_mapper->addMapping(m_junSpinBox,  month_ct_jun);
    m_mapper->addMapping(m_julSpinBox,  month_ct_jul);
    m_mapper->addMapping(m_augSpinBox,  month_ct_aug);
    m_mapper->addMapping(m_sepSpinBox,  month_ct_sep);
    m_mapper->addMapping(m_octSpinBox,  month_ct_oct);
    m_mapper->addMapping(m_novSpinBox,  month_ct_nov);
    m_mapper->addMapping(m_decSpinBox,  month_ct_dec);

//        m_mapper->setItemDelegate(new MapperDelegate);
}

void MapperDialog::layoutPrivateWidgets()
{
    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(QString("Год"),      m_yearSpinBox);
    formLayout->addRow(QString("Январь"),   m_janSpinBox);
    formLayout->addRow(QString("Февраль"),  m_febSpinBox);
    formLayout->addRow(QString("Март"),     m_marSpinBox);
    formLayout->addRow(QString("Апрель"),   m_aprSpinBox);
    formLayout->addRow(QString("Май"),      m_maySpinBox);
    formLayout->addRow(QString("Июнь"),     m_junSpinBox);
    formLayout->addRow(QString("Июль"),     m_julSpinBox);
    formLayout->addRow(QString("Август"),   m_augSpinBox);
    formLayout->addRow(QString("Сентябрь"), m_sepSpinBox);
    formLayout->addRow(QString("Октябрь"),  m_octSpinBox);
    formLayout->addRow(QString("Ноябрь"),   m_novSpinBox);
    formLayout->addRow(QString("Декабрь"),  m_decSpinBox);

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
