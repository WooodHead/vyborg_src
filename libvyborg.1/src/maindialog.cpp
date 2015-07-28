#include <QtWidgets>
#include <QtSql>

#include "maindialog.h"
#include "maindialogcontrolbuttonbox.h"
#include "mapperdialog.h"
#include "filterdialog.h"
#include "sortdialog.h"
#include "aboutdialog.h"

#include <QDebug>

VyborgMainDialog::VyborgMainDialog(QWidget *parent)
    : QDialog(parent)
{
    m_model = new QSqlRelationalTableModel(this);
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    m_view = new QTableView(this);
    m_view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_view->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_view->setSelectionMode(QAbstractItemView::SingleSelection);
    m_view->setShowGrid(true);
    m_view->setAlternatingRowColors(true);
    m_view->verticalHeader()->setVisible(false);
    m_view->setFocus();
    m_view->selectRow(0);

//    m_mapperDialog = new VyborgMapperDialog(m_model, this);
//    m_mapperDialog->setWindowTitle(trUtf8("Single Item Dialog"));

    filterDialog_ = new VyborgFilterDialog(m_model);
    filterDialog_->setWindowTitle(trUtf8("Filter Dialog"));

    sortDialog_ = new VyborgSortDialog(m_model);
    sortDialog_->setWindowTitle(trUtf8("Sort Dialog"));

    aboutDialog_ = new VyborgAboutDialog;
    aboutDialog_->setWindowTitle(trUtf8("About Dialog"));

    VyborgMainDialogControlButtonBox *controlButtonBox = new VyborgMainDialogControlButtonBox(this);
    controlButtonBox->setOrientation(Qt::Vertical);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(m_view);
    mainLayout->addWidget(controlButtonBox);

    setLayout(mainLayout);


    connect(controlButtonBox, SIGNAL(filter()),
            SLOT(showFilterDialog()));
    connect(controlButtonBox, SIGNAL(sort()),
            SLOT(showSortDialog()));
    connect(controlButtonBox, SIGNAL(update()),
            SLOT(update()));
    connect(controlButtonBox, SIGNAL(add()),
            SLOT(add()));
    connect(controlButtonBox, SIGNAL(remove()),
            SLOT(remove()));
    connect(controlButtonBox, SIGNAL(about()),
            SLOT(about()));
    connect(controlButtonBox, SIGNAL(close()),
            qApp, SLOT(quit()));

    connect(m_view, SIGNAL(doubleClicked(QModelIndex)),
            SLOT(showMapperDialog()));
}

void VyborgMainDialog::setTitle(const QString &title)
{
    setWindowTitle(title);
}

void VyborgMainDialog::add()
{
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

//    m_view->selectRow(modelIndex.row());
//        m_view->update();
//    }

//    m_model->database().transaction();
//    if (m_model->submitAll()) {
//        m_model->database().commit();
//    } else {
//        m_model->database().rollback();
//        QMessageBox::warning(this,
//                             trUtf8("Commit Changes"),
//                             trUtf8("The database reported an error: %1")
//                             .arg(m_model->lastError().text()));
//        return;
//    }
    showMapperDialog();
    m_mapperDialog->add();
}

void VyborgMainDialog::remove()
{
    QModelIndex viewIndex = m_view->currentIndex();  // index for sort/filter proxy (equal to view index)
//    QModelIndex identityProxyIndex = sortFilterProxy_->mapToSource(viewIndex); // index for identity proxy
//    QModelIndex modelIndex = identityProxy_->mapToSource(identityProxyIndex);  // index for model

//    int modelRow = modelIndex.row();  // row for model
    int modelRow = viewIndex.row();
    int viewRow = viewIndex.row();    // row for view




    QMessageBox msgBox;
    msgBox.setText(trUtf8("WARNING"));
    msgBox.setInformativeText(trUtf8("Are you sure you want to delete the row?"));
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();
    if (ret == QMessageBox::Yes) {
        m_model->removeRow(modelRow);
        m_model->submitAll();
        m_view->selectRow(qMin(viewRow, m_model->rowCount()));
    }
}

void VyborgMainDialog::showMapperDialog()
{
    QModelIndex indx = m_view->currentIndex();
    int curRow = indx.row();


//    m_mapperDialog->setCurrentRow(row);
//    m_mapperDialog->exec();

//    m_model->submitAll();



    m_mapperDialog->setCurrentRow(curRow);
    m_mapperDialog->show();
//    int res = m_mapperDialog->exec();
//    if (res == QDialog::Rejected) {
//        return;
//    }


//    m_model->database().transaction();
//    if (m_model->submitAll()) {
//        m_model->database().commit();
//    } else {
//        m_model->database().rollback();
//        QMessageBox::warning(this,
//                             trUtf8("Commit Changes"),
//                             trUtf8("The database reported an error: %1")
//                             .arg(m_model->lastError().text()));
//        return;
//    }


//    m_view->update();
//    m_view->updateGeometry();
//    m_view->selectRow(qMin(row, m_model->rowCount()));
}

void VyborgMainDialog::showFilterDialog()
{
    int ret = filterDialog_->exec();
    if (ret == QDialog::Accepted)
        m_model->select();
}

void VyborgMainDialog::showSortDialog()
{
    int ret = sortDialog_->exec();
    if (ret == QDialog::Accepted)
        m_model->select();
}

void VyborgMainDialog::update()
{
//    sortFilterProxy_->invalidate();
//    sortFilterProxy_->setFilterWildcard("*");

    m_model->setFilter("");
    m_model->setSort(0, Qt::AscendingOrder);
//    m_model->clear();
    m_model->select();
}

void VyborgMainDialog::about()
{
    aboutDialog_->exec();
}
