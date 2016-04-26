#include <QtWidgets>
#include <QtSql>

#include <vyborg.h>

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
    m_nodeWid = new NodeWidget;
    m_nodeWid->setFocus();

    m_noteruTE = new QPlainTextEdit;

    QDataWidgetMapper* m_mapper = mapper();
    m_mapper->addMapping(m_nodeWid,  node_geog);
    m_mapper->addMapping(m_noteruTE, node_noteru);

    connect(m_nodeWid, SIGNAL(geogFound(QString)),
            this, SLOT(geogFound(QString)));
}

void MapperDialog::layoutPrivateWidgets()
{
    QHBoxLayout *layout1 = new QHBoxLayout;
    layout1->addWidget(m_nodeWid);

    QFormLayout *formLayout1 = new QFormLayout;
    formLayout1->addRow(trUtf8("Примечание"), m_noteruTE);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layout1);
    mainLayout->addLayout(formLayout1);

    QVBoxLayout *privateWidgetsLayout = layout();
    privateWidgetsLayout->addLayout(mainLayout);
}

void MapperDialog::updatePrivateWidgets()
{
    if (state() == VyborgMapperDialog::Normal)
    {
        m_nodeWid->setEnabled(false);
        m_noteruTE->setReadOnly(true);
    }
    else
    {
        m_nodeWid->setEnabled(true);
        m_noteruTE->setReadOnly(false);
    }
}

void MapperDialog::geogFound(const QString &geog)
{
    qDebug() << geog;
}
