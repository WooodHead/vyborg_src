#include <QtWidgets>
#include <QtSql>

#include "vyborg_maindialog.h"
#include "vyborg_maindialogcontrolbuttonbox.h"
#include "vyborg_mapperdialog.h"
#include "vyborg_filterdialog.h"
#include "vyborg_sortdialog.h"
#include "vyborg_aboutdialog.h"

#include <QDebug>


VyborgMainDialog::VyborgMainDialog(QWidget *parent)
    : QDialog(parent)
{
    model_ = new QSqlRelationalTableModel(this);
    model_->setEditStrategy(QSqlTableModel::OnManualSubmit);


    identityProxy_ = new QIdentityProxyModel(this);

    sortFilterProxy_ = new QSortFilterProxyModel(this);
    sortFilterProxy_->setSortCaseSensitivity(Qt::CaseInsensitive);


    view_ = new QTableView(this);
    view_->setEditTriggers(QAbstractItemView::NoEditTriggers);
    view_->setSelectionBehavior(QAbstractItemView::SelectRows);
    view_->setSelectionMode(QAbstractItemView::SingleSelection);
    view_->setShowGrid(true);
    view_->setAlternatingRowColors(true);
    view_->verticalHeader()->setVisible(false);

    view_->setFocus();



    filterDialog_ = new VyborgFilterDialog(sortFilterProxy_, this);
    filterDialog_->setWindowTitle("Filter Dialog");

    sortDialog_ = new VyborgSortDialog(sortFilterProxy_, this);
    sortDialog_->setWindowTitle("Sort Dialog");

    aboutDialog_ = new VyborgAboutDialog(this);
    aboutDialog_->setWindowTitle("About Dialog");


    VyborgMainDialogControlButtonBox *controlButtonBox = new VyborgMainDialogControlButtonBox;
    controlButtonBox->setOrientation(Qt::Vertical);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(view_);
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

    connect(view_, SIGNAL(doubleClicked(QModelIndex)),
            SLOT(showMapperDialog()));
}

void VyborgMainDialog::setTitle(const QString &title)
{
    setWindowTitle(title);
}

void VyborgMainDialog::add()
{
    int modelRow = 0;
    if (model_->insertRow(modelRow) == false) {
        QMessageBox::warning(this,
                             trUtf8("Insert New Row"),
                             trUtf8("The database reported an error: %1")
                             .arg(model_->lastError().text()));
        return;
    } else {
        view_->update();
    }


    QModelIndex modelIndex = model_->index(modelRow, 0);                                     // index for model
    QModelIndex identityProxyIndex = identityProxy_->mapFromSource(modelIndex);              // index for identity proxy
    QModelIndex sortFilterProxyIndex = sortFilterProxy_->mapFromSource(identityProxyIndex);  // index for sort/filter proxy (equal to view index)

    int viewRow = sortFilterProxyIndex.row();  // row for view
    view_->selectRow(viewRow);

    mapperDialog_->setDirty(true);
    showMapperDialog();



//    model_->database().transaction();
//    if (model_->submitAll()) {
//        model_->database().commit();
//    } else {
//        model_->database().rollback();
//        QMessageBox::warning(this,
//                             trUtf8("Commit Changes"),
//                             trUtf8("The database reported an error: %1")
//                             .arg(model_->lastError().text()));
//        return;
//    }
}

void VyborgMainDialog::remove()
{
    QModelIndex viewIndex = view_->currentIndex();                             // index for sort/filter proxy (equal to view index)
    QModelIndex identityProxyIndex = sortFilterProxy_->mapToSource(viewIndex); // index for identity proxy
    QModelIndex modelIndex = identityProxy_->mapToSource(identityProxyIndex);  // index for model

    int modelRow = modelIndex.row();  // row for model
    int viewRow = viewIndex.row();    // row for view


    model_->removeRow(modelRow);
    model_->submitAll();

    view_->selectRow(qMin(viewRow, model_->rowCount()));
}

void VyborgMainDialog::showMapperDialog()
{
    QModelIndex indx = view_->currentIndex();
    int row = indx.row();


//    mapperDialog_->setCurrentRow(row);
//    mapperDialog_->exec();

//    model_->submitAll();



    mapperDialog_->setCurrentRow(row);
    int res = mapperDialog_->exec();
    if (res == QDialog::Rejected) {
        return;
    }


    model_->database().transaction();
    if (model_->submitAll()) {
        model_->database().commit();
    } else {
        model_->database().rollback();
        QMessageBox::warning(this,
                             trUtf8("Commit Changes"),
                             trUtf8("The database reported an error: %1")
                             .arg(model_->lastError().text()));
        return;
    }


    view_->update();
    view_->updateGeometry();
    view_->selectRow(qMin(row, model_->rowCount()));
}

void VyborgMainDialog::showFilterDialog()
{
    filterDialog_->exec();
}

void VyborgMainDialog::showSortDialog()
{
    sortDialog_->exec();
}

void VyborgMainDialog::update()
{
    sortFilterProxy_->invalidate();
    sortFilterProxy_->setFilterWildcard("*");
}

void VyborgMainDialog::about()
{
    aboutDialog_->exec();
}
