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

        this->clear();

        QSqlQuery query("SELECT unnest(node_pid) FROM fir.sector WHERE pid = " + m_id + "");
        while (query.next()) {
            QString arr = query.value(0).toString();
            this->addItem(arr);
        }
    }
}
