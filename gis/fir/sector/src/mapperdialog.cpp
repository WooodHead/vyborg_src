#include <QtWidgets>
#include <QtSql>

#include "mapperdialog.h"
#include "declarations.h"
#include "nodeslistwidget.h"

MapperDialog::MapperDialog(QSqlTableModel *model, QWidget *parent)
    : VyborgMapperDialog(model, parent)
{
    createPrivateWidgets();
    layoutPrivateWidgets();
    updatePrivateWidgets();
}

void MapperDialog::createPrivateWidgets()
{
    m_sectorLE   = new QLineEdit;
    m_fullnameLE = new QLineEdit;
    m_labelLE    = new QLineEdit;
    m_compoundLE = new QLineEdit;

    m_nodesListW = new NodesListWidget;

    QDataWidgetMapper* m_mapper = mapper();
    m_mapper->addMapping(m_sectorLE,   sector_sector);
    m_mapper->addMapping(m_fullnameLE, sector_fullname);
    m_mapper->addMapping(m_labelLE,    sector_label);
    m_mapper->addMapping(m_compoundLE, sector_compound);
    m_mapper->addMapping(m_nodesListW, sector_pid);
}

void MapperDialog::layoutPrivateWidgets()
{
    QFormLayout *formLayout1 = new QFormLayout;
    formLayout1->addRow(trUtf8("Сектор"), m_sectorLE);
    formLayout1->addRow(trUtf8("Полное\nнаименование"), m_fullnameLE);
    formLayout1->addRow(trUtf8("Метка"), m_labelLE);
    formLayout1->addRow(trUtf8("Составной"), m_compoundLE);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formLayout1);
    mainLayout->addWidget(m_nodesListW);

    QVBoxLayout *privateWidgetsLayout = layout();
    privateWidgetsLayout->addLayout(mainLayout);
}

void MapperDialog::updatePrivateWidgets()
{
    if (isDirty())
    {
//        m_countryLE->setReadOnly(false);
//        m_cityruLE->setReadOnly(false);
//        m_nameruLE->setReadOnly(false);
//        m_nameLE->setReadOnly(false);
//        m_indxLE->setReadOnly(false);
//        m_reglamentLE->setReadOnly(false);
//        m_emailLE->setReadOnly(false);
//        m_webLE->setReadOnly(false);

//        m_elevationSB->setEnabled(true);

//        m_magvarDSB->setEnabled(true);

//        m_notePTE->setReadOnly(false);

//        m_geogWid->setEnabled(true);

//        m_validCB->setEnabled(true);
//        m_typeCB->setEnabled(true);
//        m_intlCB->setEnabled(true);
//        m_staffCB->setEnabled(true);
    }
    else
    {
//        m_countryLE->setReadOnly(true);
//        m_cityruLE->setReadOnly(true);
//        m_nameruLE->setReadOnly(true);
//        m_nameLE->setReadOnly(true);
//        m_indxLE->setReadOnly(true);
//        m_reglamentLE->setReadOnly(true);
//        m_emailLE->setReadOnly(true);
//        m_webLE->setReadOnly(true);

//        m_elevationSB->setEnabled(false);

//        m_magvarDSB->setEnabled(false);

//        m_notePTE->setReadOnly(true);

//        m_geogWid->setEnabled(false);

//        m_validCB->setEnabled(false);
//        m_typeCB->setEnabled(false);
//        m_intlCB->setEnabled(false);
//        m_staffCB->setEnabled(false);
    }
}
