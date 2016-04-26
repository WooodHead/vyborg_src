#include <QtWidgets>
#include <QtSql>

#include "mapperdialog.h"
#include "declarations.h"
#include "nodepidarraytablewidget.h"

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

    m_nodeArrayW = new NodePidArrayTableWidget;

    QDataWidgetMapper* m_mapper = mapper();
    m_mapper->addMapping(m_sectorLE,   sector_sector);
    m_mapper->addMapping(m_fullnameLE, sector_fullname);
    m_mapper->addMapping(m_labelLE,    sector_label);
    m_mapper->addMapping(m_compoundLE, sector_compound);
    m_mapper->addMapping(m_nodeArrayW, sector_node_pid);
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
    mainLayout->addWidget(m_nodeArrayW);

    QVBoxLayout *privateWidgetsLayout = layout();
    privateWidgetsLayout->addLayout(mainLayout);
}

void MapperDialog::updatePrivateWidgets()
{
    if (state() == Edit)
    {
        m_sectorLE->setReadOnly(false);
        m_fullnameLE->setReadOnly(false);
        m_labelLE->setReadOnly(false);
        m_compoundLE->setReadOnly(false);

        m_nodeArrayW->setEnabled(true);
    }
    else
    {
        m_sectorLE->setReadOnly(true);
        m_fullnameLE->setReadOnly(true);
        m_labelLE->setReadOnly(true);
        m_compoundLE->setReadOnly(true);

        m_nodeArrayW->setEnabled(false);
    }
}
