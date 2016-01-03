#include <QtWidgets>
#include <QtSql>

#include "geogwidget.h"

GeogWidget::GeogWidget(QWidget *parent)
    : QWidget(parent)
{
    m_latLineEdit = new QLineEdit;
    m_lonLineEdit = new QLineEdit;

    QFormLayout *formLayout1 = new QFormLayout;
    formLayout1->addRow(QObject::trUtf8("Широта "),  m_latLineEdit);
    formLayout1->addRow(QObject::trUtf8("Долгота "), m_lonLineEdit);


    m_radio1 = new QRadioButton(trUtf8("Показывать целое число"));
    m_radio2 = new QRadioButton(trUtf8("Показывать град/мин/сек"));
    m_radio1->setChecked(true);

    QButtonGroup *buttonGroup = new QButtonGroup;
    buttonGroup->addButton(m_radio1);
    buttonGroup->addButton(m_radio2);

    QVBoxLayout *radioBox = new QVBoxLayout;
    radioBox->addWidget(m_radio1);
    radioBox->addWidget(m_radio2);


    QVBoxLayout *innerLayout = new QVBoxLayout;
    innerLayout->addLayout(formLayout1);
    innerLayout->addLayout(radioBox);

    QGroupBox *m_groupBox = new QGroupBox;
    m_groupBox->setTitle(trUtf8("Координаты КТА"));
    m_groupBox->setLayout(innerLayout);


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->addWidget(m_groupBox);

    setLayout(mainLayout);

    setEnabled(false);
    m_geog = "";
}

void GeogWidget::setGeog(const QString &geog)
{
    // Check here if geog is not null
    // ...


    if (geog != m_geog) {
        m_geog = geog;
        emit geogChanged();

        QString queryString = QString("SELECT St_Y(\'%1\'::geometry),St_X(\'%2\'::geometry)")
                .arg(m_geog)
                .arg(m_geog);
        QSqlQuery query(queryString);
        while (query.next()) {
            qreal lat = query.value(0).toReal();
            qreal lon = query.value(1).toReal();

            m_latLineEdit->setText(QString::number(lat, 'f', 6));
            m_lonLineEdit->setText(QString::number(lon, 'f', 6));
        }
    }
}

QString GeogWidget::geog() const
{
    qreal lat = m_latLineEdit->text().toDouble();
    qreal lon = m_lonLineEdit->text().toDouble();

    QString queryString = QString("SELECT ST_GeographyFromText('SRID=4326;POINT(%1 %2)')")
            .arg(lon)
            .arg(lat);
    QSqlQuery query(queryString);
    while (query.next()) {
        m_geog = query.value(0).toString();
    }

    return m_geog;
}

void GeogWidget::setEnabled(bool state)
{
    if (state == true) {
        m_latLineEdit->setReadOnly(false);
        m_lonLineEdit->setReadOnly(false);
    } else {
        m_latLineEdit->setReadOnly(true);
        m_lonLineEdit->setReadOnly(true);
    }
}
