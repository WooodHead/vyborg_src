#include <QtWidgets>
#include <QtSql>

#include <aviawidgets.h>

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
    m_geogWid = new GeogWidget;

    m_noteruLE = new QLineEdit;

    QDataWidgetMapper* m_mapper = mapper();
    m_mapper->addMapping(m_geogWid,  node_geog);
    m_mapper->addMapping(m_noteruLE, node_noteru);
}

void MapperDialog::layoutPrivateWidgets()
{
    QFormLayout *formLayout1 = new QFormLayout;
    formLayout1->addRow(trUtf8("Примечание"), m_noteruLE);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(m_geogWid);
    mainLayout->addLayout(formLayout1);

    QVBoxLayout *privateWidgetsLayout = layout();
    privateWidgetsLayout->addLayout(mainLayout);
}

void MapperDialog::updatePrivateWidgets()
{
    if (isDirty())
    {
        m_geogWid->setEnabled(true);
        m_noteruLE->setReadOnly(false);
    }
    else
    {
        m_geogWid->setEnabled(false);
        m_noteruLE->setReadOnly(true);
    }
}
