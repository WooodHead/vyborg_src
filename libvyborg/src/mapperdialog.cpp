#include <QtWidgets>
#include <QtSql>

#include "mapperdialog.h"
#include "mappercontrolbuttonbox.h"
#include "navigationbuttonbox.h"

#include <QDebug>

VyborgMapperDialog::VyborgMapperDialog(QSqlTableModel *model, QWidget *parent)
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

//    m_navButtonBox->setCount(m_model->rowCount());
    updateOuterWidgets();
}

void VyborgMapperDialog::updateOuterWidgets()
{
    if (isDirty()) {
        m_controlButtonBox->setDirty(true);
        m_navButtonBox->setDirty(true);
    } else {
        m_controlButtonBox->setDirty(false);
        m_navButtonBox->setDirty(false);
    }

    int nRows = m_model->rowCount();
    int curRow = m_mapper->currentIndex();
    m_navButtonBox->setCount(nRows);
    m_navButtonBox->setCurrentIndex(curRow);
}

void VyborgMapperDialog::add()
{
//    int curRow = m_navButtonBox->currentIndex();
    int curRow = m_mapper->currentIndex();
    m_model->insertRow(curRow);
    m_mapper->setCurrentIndex(curRow);

    edit();

//    m_mapper->setCurrentIndex(curRow);
//    m_navButtonBox->setCount(m_model->rowCount());
//    m_navButtonBox->setCurrentIndex(curRow);


//    int modelRow = 0;
//    int val = m_model->insertRow(modelRow);
//    if (val == false) {
//        QMessageBox::warning(this,
//                             trUtf8("Insert New Row"),
//                             trUtf8("The database reported an error: %1")
//                             .arg(m_model->lastError().text()));
//        return;
//    } else {


//    QModelIndex modelIndex = m_model->index(modelRow, 0);

//    qDebug() << "START";
//    m_mapperDialog->setDirty(true);
//    showMapperDialog();
//    qDebug() << "END";

//    view_->selectRow(modelIndex.row());
//        view_->update();

}

void VyborgMapperDialog::remove()
{

}

void VyborgMapperDialog::edit()
{
    setDirty(true);

    updatePrivateWidgets();
    updateOuterWidgets();
}

void VyborgMapperDialog::submit()
{
    int curRow = m_mapper->currentIndex();

    m_mapper->submit();
    bool ret = m_model->submitAll();
    if (ret == false)
        qDebug() << "ERROR: " << m_model->lastError().text().toUtf8();


    m_mapper->setCurrentIndex(curRow);

    setDirty(false);

    updatePrivateWidgets();
    updateOuterWidgets();
}

void VyborgMapperDialog::revert()
{
    int curRow = m_mapper->currentIndex();

    m_mapper->revert();
    m_model->revert();

    m_mapper->setCurrentIndex(qMin(curRow, m_model->rowCount()));

    setDirty(false);

    updatePrivateWidgets();
    updateOuterWidgets();
}

void VyborgMapperDialog::close()
{
    if (isDirty()) {
        int ret = QMessageBox::warning(this,
                                 trUtf8("WARNING"),
                                 trUtf8("Unsaved data exists!\nDo you want to save data?"),
                                 QMessageBox::Save | QMessageBox::Discard);
        if (ret == QMessageBox::Save)
            submit();
        else if (ret == QMessageBox::Discard)
            revert();
        done(QDialog::Rejected);
    } else {
        done(QDialog::Accepted);
    }
}

void VyborgMapperDialog::setCurrentRow(int row)
{
    m_mapper->setCurrentIndex(row);
    m_navButtonBox->setCurrentIndex(row);

    updateOuterWidgets();
}

void VyborgMapperDialog::setDirty(bool dirty)
{
    if (dirty != m_dirty) {
        m_dirty = dirty;
    }

//    updateOuterWidgets();
//    updatePrivateWidgets();
}

bool VyborgMapperDialog::dirty() const
{
    return m_dirty;
}

bool VyborgMapperDialog::isDirty() const
{
    return dirty();
}

QDataWidgetMapper* VyborgMapperDialog::mapper()
{
    return m_mapper;
}

QVBoxLayout* VyborgMapperDialog::layout()
{
    return m_privateWidgetsLayout;
}
