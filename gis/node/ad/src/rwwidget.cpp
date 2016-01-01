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

void RWWidget::setADId(const int &indx)
{
    QString queryString = QString("SELECT * FROM ad.vw_rw WHERE ad_pid=\'%1\'").arg(indx);
    qDebug() << "INDX:" << queryString;



    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(queryString);
    m_tableView->setModel(model);
    m_tableView->resizeColumnsToContents();
    m_tableView->hideColumn(0);
}
