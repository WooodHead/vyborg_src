#include <QtWidgets>
#include <QtSql>

#include "geogwidget.h"

GeogWidget::GeogWidget(QWidget *parent)
    : QWidget(parent)
{
    m_latLE  = new QLineEdit;
    m_lonLE  = new QLineEdit;
    m_sridLE = new QLineEdit;


    QHBoxLayout *coordLayout = new QHBoxLayout;
    coordLayout->addWidget(m_latLE);
    coordLayout->addWidget(m_lonLE);
    coordLayout->addWidget(new QLabel(trUtf8("SRID")));
    coordLayout->addWidget(m_sridLE);


    m_radio1 = new QRadioButton(trUtf8("град (XXX.XXXXX°)"));
    m_radio2 = new QRadioButton(trUtf8("град/мин/сек (XXX° XX\' XX.XXX\")"));
    m_radio1->setChecked(true);

    QButtonGroup *buttonGroup = new QButtonGroup;
    buttonGroup->addButton(m_radio1);
    buttonGroup->addButton(m_radio2);

    QVBoxLayout *radioBox = new QVBoxLayout;
    radioBox->addWidget(m_radio1);
    radioBox->addWidget(m_radio2);


    QVBoxLayout *innerLayout = new QVBoxLayout;
    innerLayout->addLayout(coordLayout);
    innerLayout->addLayout(radioBox);

    QGroupBox *m_groupBox = new QGroupBox;
    m_groupBox->setTitle(trUtf8("Координаты"));
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
    if (geog.isEmpty()) {
        qDebug() << "DEBUG: geog is empty.";
        m_latLE->setText("");
        m_lonLE->setText("");
        m_sridLE->setText("4326");
        return;
    }


    if (geog != m_geog) {
        m_geog = geog;

        QString queryString = QString("SELECT St_Y(\'%1\'::geometry),St_X(\'%2\'::geometry),St_SRID(\'%3\'::geometry)")
                .arg(m_geog)
                .arg(m_geog)
                .arg(m_geog);
        QSqlQuery query(queryString);
        while (query.next()) {
            double lat = query.value(0).toDouble();
            double lon = query.value(1).toDouble();
            int srid = query.value(2).toInt();

            if (m_radio1->isChecked()) {
                m_latLE->setInputMask(QString("99.99999°"));
                m_latLE->setText(QString::number(lat, 'f', 5));
                m_lonLE->setText(QString::number(lon, 'f', 5));
            }

            m_sridLE->setText(QString::number(srid));
        }
    }
}

QString GeogWidget::geog() const
{
    double lat = m_latLE->text().toDouble();
    double lon = m_lonLE->text().toDouble();

    QString queryString = QString("SELECT ST_GeographyFromText('SRID=4326;POINT(%1 %2)')")
            .arg(lon, 0, 'f', 5)
            .arg(lat, 0, 'f', 5);
    QSqlQuery query(queryString);
    while (query.next()) {
        m_geog = query.value(0).toString();
    }

    return m_geog;
}

void GeogWidget::setEnabled(bool state)
{
    if (state == true) {
        m_latLE->setReadOnly(false);
        m_lonLE->setReadOnly(false);
        m_sridLE->setReadOnly(false);
    } else {
        m_latLE->setReadOnly(true);
        m_lonLE->setReadOnly(true);
        m_sridLE->setReadOnly(true);
    }
}
