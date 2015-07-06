#include <QtWidgets>
#include <QtSql>

#include "mapperdialog.h"
#include "mappercontrolbuttonbox.h"
#include "navigationbuttonbox.h"

#include <QDebug>

VyborgMapperDialog::VyborgMapperDialog(QSqlRelationalTableModel *model, QWidget *parent)
    : QDialog(parent),
      m_dirty(false)
{
    m_model = model;

    m_mapper = new QDataWidgetMapper(this);
    m_mapper->setModel(m_model);
    m_mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);


    m_controlButtonBox = new VyborgMapperControlButtonBox;
    m_controlButtonBox->setOrientation(Qt::Vertical);

    m_navButtonBox = new VyborgNavigationButtonBox;

    m_privateWidgetsLayout = new QVBoxLayout;

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addLayout(m_navButtonBox);
    vLayout->addLayout(m_privateWidgetsLayout);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(vLayout);
    mainLayout->addWidget(m_controlButtonBox);

    setLayout(mainLayout);


    connect(m_navButtonBox, SIGNAL(goFirst()),
            m_mapper, SLOT(toFirst()));
    connect(m_navButtonBox, SIGNAL(goPrevious()),
            m_mapper, SLOT(toPrevious()));
    connect(m_navButtonBox, SIGNAL(goNext()),
            m_mapper, SLOT(toNext()));
    connect(m_navButtonBox, SIGNAL(goLast()),
            m_mapper, SLOT(toLast()));

    connect(m_controlButtonBox, SIGNAL(add()),
            SLOT(add()));
    connect(m_controlButtonBox, SIGNAL(remove()),
            SLOT(remove()));
    connect(m_controlButtonBox, SIGNAL(edit()),
            SLOT(edit()));
    connect(m_controlButtonBox, SIGNAL(submit()),
            SLOT(submit()));
    connect(m_controlButtonBox, SIGNAL(revert()),
            SLOT(revert()));
    connect(m_controlButtonBox, SIGNAL(close()),
            SLOT(close()));

    m_navButtonBox->setCount(m_model->rowCount());
}

void VyborgMapperDialog::add()
{

}

void VyborgMapperDialog::remove()
{

}

void VyborgMapperDialog::edit()
{
    setDirty(true);
}

void VyborgMapperDialog::submit()
{
    int curRow = m_mapper->currentIndex();

    m_mapper->submit();
    m_model->submitAll();

    m_mapper->setCurrentIndex(curRow);

    setDirty(false);
}

void VyborgMapperDialog::revert()
{
    int curRow = m_mapper->currentIndex();

    m_mapper->revert();
    m_model->revert();

    m_mapper->setCurrentIndex(qMin(curRow, m_model->rowCount()));

    setDirty(false);
}

void VyborgMapperDialog::close()
{
    if (dirty() == true) {
        done(QDialog::Rejected);
    } else {
        done(QDialog::Accepted);
    }
}


void VyborgMapperDialog::setCurrentRow(int row)
{
    m_mapper->setCurrentIndex(row);
    m_navButtonBox->setCurrentIndex(row);
}

void VyborgMapperDialog::setDirty(bool dirty)
{
    if (dirty != m_dirty) {
        m_dirty = dirty;
    }

    updatePrivateWidgets();

    if (m_dirty) {
        m_controlButtonBox->setDirty(true);
        m_navButtonBox->setDirty(true);
    } else {
        m_controlButtonBox->setDirty(false);
        m_navButtonBox->setDirty(false);
    }
}

bool VyborgMapperDialog::dirty() const
{
    return m_dirty;
}

bool VyborgMapperDialog::isDirty()
{
    return dirty();
}

QDataWidgetMapper* VyborgMapperDialog::mapper()
{
    return m_mapper;
}

QVBoxLayout* VyborgMapperDialog::privateWidgetsLayout()
{
    return m_privateWidgetsLayout;
}
