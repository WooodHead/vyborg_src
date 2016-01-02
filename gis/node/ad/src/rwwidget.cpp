#include <QtWidgets>
#include <QtSql>

#include "rwwidget.h"

RWWidget::RWWidget(QWidget *parent)
    : QWidget(parent)
{
    m_tableView = new QTableView;

    QVBoxLayout *vbLayout = new QVBoxLayout;
    vbLayout->addWidget(m_tableView);

    setLayout(vbLayout);
}

int RWWidget::adid() const
{
    return m_adid;
}

void RWWidget::setAdid(const int &adid)
{
    // Check here if adid is exist
    // ...

    m_adid = adid;

    QString queryStr = QString("SELECT * FROM ad.vw_rw WHERE ad_pid=\'%1\'").arg(m_adid);
    QSqlQuery query(queryStr);
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(query);
    m_tableView->setModel(model);
    m_tableView->resizeColumnsToContents();
}
