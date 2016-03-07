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


    m_radio1 = new QRadioButton(trUtf8("град° (ггг.ггггг°)"));
    m_radio1->setChecked(true);
    m_radio2 = new QRadioButton(trUtf8("град° мин\' сек\" (ггг° мм\' сс.ссс\")"));

    QButtonGroup *buttonGroup = new QButtonGroup;
    buttonGroup->addButton(m_radio1);
    buttonGroup->addButton(m_radio2);

    connect(buttonGroup, SIGNAL(buttonClicked(QAbstractButton*)),
            this, SLOT(showGeog()));

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
}

void GeogWidget::setGeog(const QString &geog)
{
    // Check here if geog is not null
    // ...
    if (geog.isEmpty()) {
        qDebug() << "DEBUG: geog is empty.";
        m_geog = QString();
        m_srid = 4326;
    }
    else if (geog != m_geog) {
        m_geog = geog;
        emit geogChanged();

//        QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
//        db.setUserName("postgres");
//        db.setPassword("monrepo");
//        db.setDatabaseName("gis");
//        db.open();

        QString queryString = QString("SELECT St_Y(\'%1\'::geometry),St_X(\'%2\'::geometry),St_SRID(\'%3\'::geometry)")
                .arg(m_geog)
                .arg(m_geog)
                .arg(m_geog);
        QSqlQuery query(queryString);
        while (query.next()) {
            m_lat  = query.value(0).toDouble();
            m_lon  = query.value(1).toDouble();
            m_srid = query.value(2).toInt();
        }
    }

    showGeog();
}

QString GeogWidget::geog() const
{
    double lat;
    double lon;

    if (m_radio1->isChecked())
    {
        lat = m_latLE->text().mid(0, 8).toDouble();
        lon = m_lonLE->text().mid(0, 9).toDouble();
    }
    else if (m_radio2->isChecked())
    {
        QString _lat = m_latLE->text();
        QString _lon = m_lonLE->text();

        lat = _lat.mid(0, 2).toDouble() +
              _lat.mid(4, 2).toDouble() / 60.0 +
              _lat.mid(8, 6).toDouble() / 60.0 / 60.0;
        lon = _lon.mid(0, 3).toDouble() +
              _lon.mid(5, 2).toDouble() / 60.0 +
              _lon.mid(9, 6).toDouble() / 60.0 / 60.0;
    }

    qDebug() << "GEOG:" << lat << lon;

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

void GeogWidget::showGeog()
{
    if (m_radio1->isChecked())
    {
        m_latLE->setInputMask(QString("99.99999°;_"));
        m_lonLE->setInputMask(QString("999.99999°;_"));

        if (m_geog.isEmpty())
        {
            // input nothing into lineEdit's
        }
        else
        {
            m_latLE->setText(QString::number(m_lat, 'f', 5));
            if (m_lon < 180.0)
                m_lonLE->setText(QString("0") + QString::number(m_lon, 'f', 5));
            else
                m_lonLE->setText(QString::number(m_lon, 'f', 5));
        }
    }
    else if (m_radio2->isChecked())
    {
        m_latLE->setInputMask(QString("99° 99\' 99.999\";_"));
        m_lonLE->setInputMask(QString("999° 99\' 99.999\";_"));

        if (m_geog.isEmpty())
        {
            // input nothing into lineEdit's
        }
        else
        {
            int gg_lat = (int)m_lat;
            int mm_lat = (int)((m_lat - gg_lat) * 60.0);
            double ss_lat = ((m_lat - gg_lat) * 60.0 - mm_lat) * 60.0;
            double lat = gg_lat * 100 * 100 + mm_lat * 100 + ss_lat;

            int gg_lon = (int)m_lon;
            int mm_lon = (int)((m_lon - gg_lon) * 60.0);
            double ss_lon = ((m_lon - gg_lon) * 60.0 - mm_lon) * 60.0;
            double lon = gg_lon * 100 * 100 + mm_lon * 100 + ss_lon;

            m_latLE->setText(QString::number(lat, 'f', 3));
            if (lon < 1800000.0)
                m_lonLE->setText(QString("0") + QString::number(lon, 'f', 3));
            else
                m_lonLE->setText(QString::number(lon, 'f', 3));
        }
    }

    m_sridLE->setText(QString::number(m_srid));

    m_latLE->setCursorPosition(0);
    m_latLE->setFocus();
}
