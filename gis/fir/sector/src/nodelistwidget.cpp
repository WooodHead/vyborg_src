#include <QtWidgets>
#include <QtSql>

#include "nodelistwidget.h"

NodeListWidget::NodeListWidget(QWidget *parent)
    : QWidget(parent)
{
    m_model = new QSqlTableModel;
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    m_view = new QTableView;
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

        m_model->setTable("data.vw_node");
        m_model->select();
    }
}

int NodeListWidget::sectorpid() const
{
    return m_sectorpid;
}
