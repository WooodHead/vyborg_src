#include <QtWidgets>
#include <QtSql>
#include <QDebug>

#include "dialog.h"
#include "relationaltablemodel.h"
#include "declarations.h"
#include "mapperdialog.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setUserName("postgres");
    db.setPassword("monrepo");
    db.setDatabaseName("gis");

    if (!db.open()) {
        qDebug() << "ERROR: Database not opened: " << db.lastError().text();
        return;
    }

    m_model = new RelationalTableModel(this);
    m_model->setTable("data.node");
//    m_model->setRelation(col_type, QSqlRelation("terkas.point_type", "id", "type"));
//    m_model->setRelation(col_status, QSqlRelation("terkas.point_status", "id", "status"));
//    m_model->setRelation(col_source, QSqlRelation("terkas.source", "id", "doc"));
//    m_model->setRelation(col_srid, QSqlRelation("spatial_ref_sys", "srid", "srid"));
    m_model->select();

    m_view = new QTableView;
    m_view->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_view->setSelectionMode(QAbstractItemView::SingleSelection);
    m_view->setEditTriggers(QAbstractItemView::NoEditTriggers);

    m_view->setModel(m_model);
    m_view->hideColumn(col_id);
//    m_view->hideColumn(col_st_x);
//    m_view->hideColumn(col_st_y);
    m_view->hideColumn(col_geom);
    m_view->hideColumn(col_source);
    m_view->selectRow(0);

    m_view->horizontalHeader()->moveSection(col_name, col_label + 2);
    m_view->horizontalHeader()->moveSection(col_status, col_type + 4);
    m_view->horizontalHeader()->moveSection(col_note, 5);
    m_view->horizontalHeader()->setStretchLastSection(true);


    connect(m_view, SIGNAL(doubleClicked(QModelIndex)),
            this, SLOT(openMapperDialog(QModelIndex)));


    QPushButton *addButton = new QPushButton(trUtf8("Add"));
    QPushButton *removeButton = new QPushButton(trUtf8("Remove"));
    QPushButton *closeButton = new QPushButton(trUtf8("Close"));

    connect(addButton, SIGNAL(clicked()),
            this, SLOT(add()));
    connect(removeButton, SIGNAL(clicked()),
            this, SLOT(remove()));
    connect(closeButton, SIGNAL(clicked()),
            qApp, SLOT(quit()));

    QDialogButtonBox *bbox = new QDialogButtonBox(Qt::Vertical);
    bbox->addButton(addButton, QDialogButtonBox::ActionRole);
    bbox->addButton(removeButton, QDialogButtonBox::ActionRole);
    bbox->addButton(closeButton, QDialogButtonBox::ActionRole);


    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(m_view);
    mainLayout->addWidget(bbox);

    setLayout(mainLayout);
}

void Dialog::openMapperDialog(const QModelIndex &indx)
{
    MapperDialog *mapperDialog = new MapperDialog(m_model, indx.row());
    mapperDialog->exec();
}

void Dialog::add()
{
    QModelIndex indx = m_view->currentIndex();
    bool ret = m_model->insertRow(indx.row());
    if (ret == true) {
        m_view->setCurrentIndex(indx);
        openMapperDialog(indx);
    }

    m_view->setCurrentIndex(indx);
}

void Dialog::remove()
{
    QModelIndex indx = m_view->currentIndex();
    m_model->removeRow(indx.row());
    if (!m_model->submitAll())
        qDebug() << "ERROR: " << m_model->lastError().text();
}
