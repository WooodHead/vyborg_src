#include <QtWidgets>
#include <QtSql>

#include "rwwidget.h"
#include "declarations.h"

RWWidget::RWWidget(QWidget *parent)
    : QWidget(parent)
{
    m_tableView = new QTableView;

    QVBoxLayout *vbLayout = new QVBoxLayout;
    vbLayout->addWidget(m_tableView);

    QPushButton *saveButton = new QPushButton(trUtf8("Save"));

    QVBoxLayout *vbCntlLayout = new QVBoxLayout;
    vbCntlLayout->addWidget(saveButton);
    vbCntlLayout->addStretch();


    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(vbLayout);
    mainLayout->addLayout(vbCntlLayout);

    setLayout(mainLayout);
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

    RWTableModel *model = new RWTableModel;
    QString filterString = QString("ad_pid=%1")
            .arg(m_adid);
    model->setFilter(filterString);
    model->select();

    m_tableView->setModel(model);
    m_tableView->resizeColumnsToContents();
    m_tableView->hideColumn(0);
    m_tableView->hideColumn(11);
}

// RWTableModel implementation
//

RWTableModel::RWTableModel(QObject *parent, QSqlDatabase db)
    : QSqlTableModel(parent, db)
{
    setTable("rw.vw_rw");
}

QVariant RWTableModel::data(const QModelIndex &idx, int role) const
{
    if (!idx.isValid())
        return QVariant();

    int col = idx.column();
    if (col == 5 || col == 6) {
        if (role == Qt::DisplayRole) {
            double ddd = QSqlTableModel::data(idx, role).toDouble();
            QString output = QString::number(ddd, 'f', 5);
            return output;
        }
    }

    return QSqlTableModel::data(idx, role);
}
