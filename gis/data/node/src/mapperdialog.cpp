#include <QtWidgets>
#include <QtSql>

#include "mapperdialog.h"
#include "declarations.h"

MapperDialog::MapperDialog(QSqlTableModel *model, QWidget *parent)
    : VyborgMapperDialog(model, parent)
{
    createPrivateWidgets();
    layoutPrivateWidgets();
    updatePrivateWidgets();
}

void MapperDialog::createPrivateWidgets()
{
    m_latLE = new QLineEdit;
    m_lonLE = new QLineEdit;

    QDataWidgetMapper* m_mapper = mapper();
    m_mapper->addMapping(m_latLE, node_lat);
    m_mapper->addMapping(m_lonLE, node_lon);
}

void MapperDialog::layoutPrivateWidgets()
{
    QFormLayout *formLayout1 = new QFormLayout;
    formLayout1->addRow(trUtf8("Широта"), m_latLE);
    formLayout1->addRow(trUtf8("Долгота"), m_lonLE);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formLayout1);

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
