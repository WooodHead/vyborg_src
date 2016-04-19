#include <QtWidgets>
#include <QtSql>

#include "nodewidget.h"

NodeWidget::NodeWidget(QWidget *parent)
    : QWidget(parent),
      m_geog(QString())
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
            this, SLOT(showNode()));

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
    mainLayout->addWidget(m_groupBox);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    setLayout(mainLayout);

    setEnabled(false);
}

void NodeWidget::setGeog(const QString &geog)
{
    // Check here if geog is not null
    // ...

    if (geog.isEmpty()) {
        m_geog = QString();
    }

    if (geog != m_geog) {
        m_geog = geog;
        emit geogChanged();
    }

    showNode();
}

QString NodeWidget::geog() const
{
    QString lat;
    QString lon;

    if (m_radio1->isChecked())
    {
        lat = m_latLE->text().mid(0, 8);
        lon = m_lonLE->text().mid(0, 9);
    }
    else if (m_radio2->isChecked())
    {
        QString _lat = m_latLE->text();
        QString _lon = m_lonLE->text();

        QString lat_gg = _lat.mid(0, 2);
        QString lat_mm = _lat.mid(4, 2);
        QString lat_ss = _lat.mid(8, 6);

        QString lon_gg = _lon.mid(0, 3);
        QString lon_mm = _lon.mid(5, 2);
        QString lon_ss = _lon.mid(9, 6);

        QString tmp1 = lat_gg + "°" + lat_mm + "''" + lat_ss;
        QString tmp2 = lon_gg + "°" + lon_mm + "''" + lon_ss;

        QString queryString = QString("SELECT func.f_dms2dd('%1'),func.f_dms2dd('%2')").arg(tmp1).arg(tmp2);
        QSqlQuery query(queryString);
        while (query.next()) {
            lat = query.value(0).toString();
            lon = query.value(1).toString();
        }
    }

    QString queryString = QString("SELECT ST_NoderaphyFromText('SRID=4326;POINT(%1 %2)')")
            .arg(lon)
            .arg(lat);
    QSqlQuery query(queryString);
    while (query.next()) {
        m_geog = query.value(0).toString();
    }

    return m_geog;
}

void NodeWidget::setEnabled(bool state)
{
    if (state == true) {
        m_latLE->setReadOnly(false);
        m_lonLE->setReadOnly(false);
        m_sridLE->setReadOnly(false);
        m_latLE->setFocus();
    } else {
        m_latLE->setReadOnly(true);
        m_lonLE->setReadOnly(true);
        m_sridLE->setReadOnly(true);
    }
}

void NodeWidget::showNode()
{
    // if not running QPSQL driver start new one
    if (!QSqlDatabase::contains()) {
        QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
        db.setUserName("postgres");
        db.setPassword("monrepo");
        db.setDatabaseName("gis");
        db.open();
    }

    if (m_radio1->isChecked())
    {
        m_latLE->setInputMask(QString("99.9999999999°;_"));
        m_lonLE->setInputMask(QString("999.9999999999°;_"));

        if (m_geog.isEmpty()) {
            // input nothing into lineEdit's
            m_latLE->setText(QString());
            m_lonLE->setText(QString());
            m_sridLE->setText(QString());
        } else {
            QStringList coord;
            QString lat;
            QString lon;
            QString srid;

            QString queryString = QString("SELECT St_AsLatLonText('%1'::geometry,'D.DDDDDDDDDD'),St_SRID('%1'::geometry)")
                                          .arg(m_geog);
            QSqlQuery query(queryString);
            while (query.next()) {
                coord = query.value(0).toString().split(" ");
                lat = coord.at(0);
                lon = coord.at(1);
                if (lon.length() == 13)
                    lon.prepend("0");
                srid = query.value(1).toString();
            }

            m_latLE->setText(lat);
            m_lonLE->setText(lon);
            m_sridLE->setText(srid);
        }
    }
    else if (m_radio2->isChecked())
    {
        m_latLE->setInputMask(QString("99° 99\' 99.999\";_"));
        m_lonLE->setInputMask(QString("999° 99\' 99.999\";_"));

        if (m_geog.isEmpty())
        {
            // input nothing into lineEdit's
            m_latLE->setText(QString());
            m_lonLE->setText(QString());
            m_sridLE->setText(QString());
        }
        else
        {
            QStringList coord;
            QString lat;
            QString lon;
            QString srid;

            QString queryString = QString("SELECT St_AsLatLonText('%1'::geometry, 'D M S.SSS'),St_SRID('%1'::geometry)")
                                          .arg(m_geog);
            QSqlQuery query(queryString);
            while (query.next()) {
                coord = query.value(0).toString().split(" ");

                QString lat_gg = coord.at(0);
                if (lat_gg.length() == 1)
                    lat_gg.prepend("0");
                QString lat_mm = coord.at(1);
                if (lat_mm.length() == 1)
                    lat_mm.prepend("0");
                QString lat_ss = coord.at(2);
                if (lat_ss.length() == 5)
                    lat_ss.prepend("0");

                QString lon_gg = coord.at(3);
                if (lon_gg.length() == 1)
                    lon_gg.prepend("0");
                if (lon_gg.length() == 2)
                    lon_gg.prepend("0");
                QString lon_mm = coord.at(4);
                if (lon_mm.length() == 1)
                    lon_mm.prepend("0");
                QString lon_ss = coord.at(5);
                if (lon_ss.length() == 5)
                    lon_ss.prepend("0");

                lat = lat_gg + lat_mm + lat_ss;
                lon = lon_gg + lon_mm + lon_ss;

                srid = query.value(1).toString();
            }

            m_latLE->setText(lat);
            m_lonLE->setText(lon);
            m_sridLE->setText(srid);
        }
    }

//    qint32 srid;
//    QString queryString1 = QString("SELECT St_SRID('%1'::geometry)").arg(m_geog);
//    QSqlQuery query1(queryString1);
//    while (query1.next()) {
//        srid = query1.value(0).toInt();
//    }
//    m_sridLE->setText(QString::number(srid));

    m_latLE->setCursorPosition(0);
    m_latLE->setFocus();
}
