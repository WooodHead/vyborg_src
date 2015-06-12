#include <QtWidgets>
#include <QtSql>

#include "vyborg_mapperdialog.h"
#include "vyborg_mappercontrolbuttonbox.h"
#include "vyborg_navigationbuttonbox.h"


#include <QDebug>


VyborgMapperDialog::VyborgMapperDialog(QSqlRelationalTableModel *model, QWidget *parent)
    : QDialog(parent),
      dirty_(false)
{
    m_model = model;


    qDebug() << "Check point 1";


//    mapper_ = new QDataWidgetMapper(this);
//    mapper_->setModel(proxy_);
//    mapper_->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);


//    controlButtonBox = new VyborgMapperControlButtonBox;
//    controlButtonBox->setOrientation(Qt::Vertical);

//    navButtonBox = new VyborgNavigationButtonBox;

//    privateWidgetsLayout = new QVBoxLayout;


//    QVBoxLayout *vLayout = new QVBoxLayout;
//    vLayout->addLayout(navButtonBox);
//    vLayout->addLayout(privateWidgetsLayout);

//    QHBoxLayout *mainLayout = new QHBoxLayout;
//    mainLayout->addLayout(vLayout);
//    mainLayout->addWidget(controlButtonBox);

//    setLayout(mainLayout);


//    connect(navButtonBox, SIGNAL(goFirst()),
//            mapper_, SLOT(toFirst()));
//    connect(navButtonBox, SIGNAL(goPrevious()),
//            mapper_, SLOT(toPrevious()));
//    connect(navButtonBox, SIGNAL(goNext()),
//            mapper_, SLOT(toNext()));
//    connect(navButtonBox, SIGNAL(goLast()),
//            mapper_, SLOT(toLast()));

//    connect(controlButtonBox, SIGNAL(edit()),
//            SLOT(edit()));
//    connect(controlButtonBox, SIGNAL(submit()),
//            SLOT(submit()));
//    connect(controlButtonBox, SIGNAL(revert()),
//            SLOT(revert()));
//    connect(controlButtonBox, SIGNAL(close()),
//            SLOT(close()));


//    navButtonBox->setCount(proxy_->rowCount());
}

void VyborgMapperDialog::edit()
{
    setDirty(true);
}

void VyborgMapperDialog::submit()
{
    int curRow = mapper_->currentIndex();

    mapper_->submit();
//    proxy_->submit();

//    QSqlTableModel *model = static_cast<QSqlTableModel *>(proxy_->sourceModel());
//    model->submitAll();

    mapper_->setCurrentIndex(curRow);

    setDirty(false);
}

void VyborgMapperDialog::revert()
{
//    int curRow = mapper_->currentIndex();

//    mapper_->revert();
//    proxy_->revert();

//    mapper_->setCurrentIndex(qMin(curRow, proxy_->rowCount()));

//    setDirty(false);
}

void VyborgMapperDialog::close()
{
    if (isDirty()) {
        done(QDialog::Rejected);
    } else {
        done(QDialog::Accepted);
    }
}


void VyborgMapperDialog::setCurrentRow(int row)
{
    mapper_->setCurrentIndex(row);
    navButtonBox->setCurrentIndex(row);
}

void VyborgMapperDialog::setDirty(bool dirty)
{
    if (dirty != dirty_) {
        dirty_ = dirty;
    }

    updatePrivateWidgets();

    if (dirty_) {
        controlButtonBox->setDirty(true);
        navButtonBox->setDirty(true);
    } else {
        controlButtonBox->setDirty(false);
        navButtonBox->setDirty(false);
    }
}

bool VyborgMapperDialog::isDirty() const
{
    return dirty_;
}
