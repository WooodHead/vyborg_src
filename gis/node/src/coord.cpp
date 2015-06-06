#include <QtWidgets>

#include "coord.h"

#include <QDebug>


GMScoord::GMScoord(QWidget *parent)
    : QWidget(parent)
{
    m_gle = new QLineEdit;
    m_mle = new QLineEdit;
    m_sle = new QLineEdit;

    QFontMetrics metrics(QApplication::font());
    m_gle->setFixedWidth(metrics.width("00000"));
    m_mle->setFixedWidth(metrics.width("0000"));
    m_sle->setFixedWidth(metrics.width("0000"));

    connect(m_gle, SIGNAL(editingFinished()),
            this, SLOT(coordRecalc()));
    connect(m_mle, SIGNAL(editingFinished()),
            this, SLOT(coordRecalc()));
    connect(m_sle, SIGNAL(editingFinished()),
            this, SLOT(coordRecalc()));

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->setContentsMargins(0, 0, 0, 0);
    hLayout->setSpacing(0);
    hLayout->addWidget(m_gle);
    hLayout->addWidget(m_mle);
    hLayout->addWidget(m_sle);
    hLayout->addStretch();

    setLayout(hLayout);
}

qreal GMScoord::coord() const
{
    return m_coord;
}

void GMScoord::setCoord(qreal &coord)
{
    if (coord != m_coord) {
        m_coord = coord;

        qint64 gg = qFloor(m_coord);
        qint64 mm = qFloor(m_coord * 60 - gg * 60);
        qint64 ss = qRound(m_coord * 3600 - gg * 3600 - mm * 60.0);

        if (ss == 60) {
            mm++;
            ss = 0;
        }
        if (mm == 60) {
            gg++;
            mm = 0;
        }

        m_gle->setText(QString::number(gg));
        m_mle->setText(QString::number(mm));
        m_sle->setText(QString::number(ss));
    }
}

void GMScoord::coordRecalc()
{
    qint64 gg = m_gle->text().toInt();
    qint64 mm = m_mle->text().toInt();
    qint64 ss = m_sle->text().toInt();

    m_coord = (qreal)gg + (qreal)mm / 60.0 + (qreal)ss / 3600.0;

    emit coordChanged();
}

// ########################## GMcoord ##########################

GMcoord::GMcoord(QWidget *parent)
    : QWidget(parent)
{
    m_gle = new QLineEdit;
    m_mle = new QLineEdit;

    QFontMetrics metrics(QApplication::font());
    m_gle->setFixedWidth(metrics.width("00000"));
    m_mle->setFixedWidth(metrics.width("0000000000000000"));

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->setContentsMargins(0, 0, 0, 0);
    hLayout->setSpacing(0);
    hLayout->addWidget(m_gle);
    hLayout->addWidget(m_mle);

    setLayout(hLayout);
}

