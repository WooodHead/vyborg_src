#include <QtWidgets>
#include <QtSql>

#include "widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setUserName("postgres");
    db.setPassword("monrepo");
    db.setDatabaseName("terkas");

    if (!db.open()) {
        qDebug() << "ERROR: Database not opened: " << db.lastError().text();
        return;
    }

    QSqlRelationalTableModel *m_model = new QSqlRelationalTableModel(this);
    m_model->setTable("terkas.polygon");
//    m_model->setRelation(col_type, QSqlRelation("terkas.point_type", "id", "type"));
//    m_model->setRelation(col_status, QSqlRelation("terkas.point_status", "id", "status"));
//    m_model->setRelation(col_source, QSqlRelation("terkas.source", "id", "doc"));
    m_model->select();

    QTableView *m_view = new QTableView;
    m_view->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_view->setSelectionMode(QAbstractItemView::SingleSelection);
    m_view->setEditTriggers(QAbstractItemView::NoEditTriggers);

    m_view->setModel(m_model);
//    m_view->hideColumn(col_id);
//    m_view->hideColumn(col_st_x);
//    m_view->hideColumn(col_st_y);
//    m_view->hideColumn(col_geom);
    m_view->selectRow(0);


    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(m_view);

    setLayout(vLayout);
}
