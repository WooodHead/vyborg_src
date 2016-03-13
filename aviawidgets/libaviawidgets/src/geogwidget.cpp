#include <QtWidgets>
#include <QtSql>

#include "geogwidget.h"

//qint32 convertRealToInt(qreal r)
//{
//    return r < 0.0 ? (qint32)qCeil(r) :
//                     (qint32)qFloor(r);
//}

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
    }

    if (geog != m_geog) {
        m_geog = geog;
        emit geogChanged();

    }

    // if not running QPSQL driver start new one
    if (!QSqlDatabase::contains()) {
        QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
        db.setUserName("postgres");
        db.setPassword("monrepo");
        db.setDatabaseName("gis");
        db.open();
    }

    showGeog();
}

QString GeogWidget::geog() const
{
//    qreal lat;
//    qreal lon;

//    if (m_radio1->isChecked())
//    {
//        lat = m_latLE->text().mid(0, 8).toDouble();
//        lon = m_lonLE->text().mid(0, 9).toDouble();
//    }
//    else if (m_radio2->isChecked())
//    {
//        QString _lat = m_latLE->text();
//        QString _lon = m_lonLE->text();

//        lat = _lat.mid(0, 2).toDouble() +
//              _lat.mid(4, 2).toDouble() / 60.0 +
//              _lat.mid(8, 6).toDouble() / 60.0 / 60.0;
//        lon = _lon.mid(0, 3).toDouble() +
//              _lon.mid(5, 2).toDouble() / 60.0 +
//              _lon.mid(9, 6).toDouble() / 60.0 / 60.0;
//    }

//    qDebug() << "GEOG:" << QString::number(lat, 'f', 20) << QString::number(lon, 'f', 20);

//    QString queryString = QString("SELECT ST_GeographyFromText('SRID=4326;POINT(%1 %2)')")
//            .arg(lon, 0, 'f', 5)
//            .arg(lat, 0, 'f', 5);
//    QSqlQuery query(queryString);
//    while (query.next()) {
//        m_geog = query.value(0).toString();
//    }

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

        if (m_geog.isEmpty()) {
            // input nothing into lineEdit's
            m_latLE->setText(QString());
            m_lonLE->setText(QString());
        } else {
            qreal lat;
            qreal lon;
            qint32 srid;

            QString queryString = QString("SELECT St_Y(\'%1\'::geometry),"
                                          "St_X(\'%1\'::geometry),"
                                          "St_SRID(\'%1\'::geometry)").arg(m_geog);
            QSqlQuery query(queryString);
            while (query.next()) {
                lat  = query.value(0).toReal();
                lon  = query.value(1).toReal();
                srid = query.value(2).toInt();
            }

            m_latLE->setText(QString::number(lat, 'f', 5));
            if (lon < 100.0)
                m_lonLE->setText(QString("0") + QString::number(lon, 'f', 5));
            else
                m_lonLE->setText(QString::number(lon, 'f', 5));
            m_sridLE->setText(QString::number(srid));
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
        }
        else
        {
            QString queryString = QString("SELECT St_AsLatLonText(\'%1\'::geometry, \'D M S.SSS\'),"
                                                 "St_SRID(\'%1\'::geometry)").arg(m_geog);

            QStringList coord;
            qint32 srid;
            QSqlQuery query(queryString);
            while (query.next()) {
                coord = query.value(0).toString().split(" ");
                srid = query.value(1).toInt();
            }

            qint32 lat_gg = QString(coord[0]).toInt();
            qint32 lat_mm = QString(coord[1]).toInt();
            qreal  lat_ss = QString(coord[2]).toDouble();
            qreal  lat = lat_gg * 100 * 100 + lat_mm * 100 + lat_ss;

            qint32 lon_gg = QString(coord[3]).toInt();
            qint32 lon_mm = QString(coord[4]).toInt();
            qreal  lon_ss = QString(coord[5]).toDouble();
            qreal  lon = lon_gg * 100 * 100 + lon_mm * 100 + lon_ss;

            m_latLE->setText(QString::number(lat, 'f', 3));
            if (lon < 1800000.0)
                m_lonLE->setText(QString("0") + QString::number(lon, 'f', 3));
            else
                m_lonLE->setText(QString::number(lon, 'f', 3));
            m_sridLE->setText(QString::number(srid));
        }
    }

    m_latLE->setCursorPosition(0);
    m_latLE->setFocus();
}
