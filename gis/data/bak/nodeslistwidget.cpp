#include <QtWidgets>
#include <QtSql>

#include "nodeslistwidget.h"

NodesListWidget::NodesListWidget(QWidget *parent)
    : QListWidget(parent)
{
}

QString NodesListWidget::id() const
{
    return m_id;
}

void NodesListWidget::setId(const QString &id)
{
    if (id != m_id) {
        m_id = id;
        emit idChanged();

        QStringList nodeslist;
        nodeslist.clear();

        QSqlQuery query("SELECT unnest(node_pid) "
                        "FROM fir.sector "
                        "WHERE pid = " + m_id);
        while (query.next()) {
            QString sector = query.value(0).toString();
            nodeslist << sector;
        }

        this->clear();

        for (int i = 0; i < nodeslist.size(); ++i) {
            QSqlQuery query("SELECT pid,St_AsLatLonText(geog::geometry),noteru "
                            "FROM data.vw_node "
                            "WHERE pid = " + nodeslist.at(i));
            while (query.next()) {
                QString node;
                node.clear();
                node.append(query.value(1).toString());
                node.append("\t");
                node.append(query.value(2).toString());
                this->addItem(node);
            }
        }

//        this->addItems(nodeslist);
    }
}
