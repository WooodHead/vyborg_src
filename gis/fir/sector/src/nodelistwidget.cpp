#include <QtWidgets>
#include <QtSql>

#include "nodelistwidget.h"

NodeListWidget::NodeListWidget(QWidget *parent)
    : QWidget(parent)
{
    m_model = new QSqlTableModel;
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);

//    m_model = new QSqlQueryModel(this);

    m_view = new QTableView(this);
    m_view->setModel(m_model);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(m_view);

    setLayout(mainLayout);
}

void NodeListWidget::setSectorpid(int sectorpid)
{
    if (sectorpid != m_sectorpid) {
        m_sectorpid = sectorpid;
        emit sectorpidChanged();

//        m_model->setTable("data.vw_node");
//        m_model->setFilter();
//        m_model->select();

//        m_model->clear();

//        QStringList nodelist;
//        nodelist.clear();
//        QSqlQuery query("SELECT unnest(node_pid) "
//                        "FROM fir.vw_sector "
//                        "WHERE pid = " + QString::number(m_sectorpid));
//        while (query.next()) {
//            QString sector = query.value(0).toString();
//            nodelist << sector;
//        }
        
//        if (nodelist.size() > 1) {
//            QString wherestr;

//            wherestr.append(QString("WHERE pid="));
//            wherestr.append(nodelist.at(0));

//            for (int i = 1; i < nodelist.size(); ++i) {
//                wherestr.append(QString(" OR pid="));
//                wherestr.append(nodelist.at(i));
//            }

//            QSqlQuery query("SELECT pid,St_AsLatLonText(geog::geometry),noteru "
//                            "FROM data.vw_node " + wherestr);
//            m_model->setQuery(query);
//        }
    }
}

int NodeListWidget::sectorpid() const
{
    return m_sectorpid;
}
