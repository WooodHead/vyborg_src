#include <QtWidgets>
#include <QtSql>

#include "geogwidget.h"

GeogWidget::GeogWidget(QWidget *parent)
    : QWidget(parent)
{
    m_latLineEdit = new QLineEdit;
    m_lonLineEdit = new QLineEdit;

    QFormLayout *formLayout1 = new QFormLayout;
    formLayout1->addRow(QObject::trUtf8("Широта"),  m_latLineEdit);
    formLayout1->addRow(QObject::trUtf8("Долгота"), m_lonLineEdit);

    QGroupBox *groupBox = new QGroupBox;
    groupBox->setTitle(trUtf8("Координаты КТА"));
    groupBox->setLayout(formLayout1);

    QVBoxLayout *vbLayout = new QVBoxLayout;
//    vbLayout->setContentsMargins(0, 0, 0, 0);
    vbLayout->addWidget(groupBox);

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

        QString queryString = QString("SELECT St_Y(\'%1\'::geometry),St_X(\'%2\'::geometry)")
                .arg(m_geog)
                .arg(m_geog);
        QSqlQuery query(queryString);
        while (query.next()) {
            qreal lat = query.value(0).toReal();
            qreal lon = query.value(1).toReal();

            m_latLineEdit->setText(QString::number(lat, 'f', 5));
            m_lonLineEdit->setText(QString::number(lon, 'f', 5));
        }
    }
}

QString GeogWidget::geog() const
{
    return m_geog;
}
