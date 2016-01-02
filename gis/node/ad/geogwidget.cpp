#include <QtWidgets>
#include <QtSql>

#include "geogwidget.h"

GeogWidget::GeogWidget(QWidget *parent)
    : QWidget(parent)
{
    m_tableView = new QTableView;

    QVBoxLayout *vbLayout = new QVBoxLayout;
    vbLayout->addWidget(m_tableView);

    setLayout(vbLayout);

    m_geog = "";
}

void GeogWidget::setGeog(const QString &geog)
{
    // Check here if geog is not null
    // ...


    if (geog != m_geog) {
        m_geog = geog;
//        emit geogChanged();

        QString queryString = QString("SELECT St_Y(\'%1\'::geometry),St_X(\'%2\'::geometry)").arg(m_geog).arg(m_geog);
        QSqlQuery query(queryString);
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery(query);
        m_tableView->setModel(model);
        m_tableView->resizeColumnsToContents();
    }
}

QString GeogWidget::geog() const
{
    return m_geog;
}
