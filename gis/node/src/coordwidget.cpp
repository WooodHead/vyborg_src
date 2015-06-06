#include <QtWidgets>

#include "coordwidget.h"
#include "coord.h"

#include <QDebug>


CoordWidget::CoordWidget(QWidget *parent)
    : QWidget(parent),
      m_coordStyle(GMS)
{
    m_gmsCoord = new GMScoord;
    m_gmCoord = new GMcoord;

    connect(m_gmsCoord, SIGNAL(coordChanged()),
            this, SLOT(updateCoord()));
//    connect(m_gmCoord, SIGNAL(coordChanged(qreal &coord)),
//            this, SLOT(coordRecalc(qreal &coord)));

    m_stack = new QStackedLayout;
    m_stack->addWidget(m_gmsCoord);
    m_stack->addWidget(m_gmCoord);

    m_stack->setCurrentIndex(m_coordStyle);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    mainLayout->addLayout(m_stack);
    mainLayout->addStretch();

    setLayout(mainLayout);
}

qreal CoordWidget::coord() const
{
    return m_coord;
}

void CoordWidget::setCoord(qreal &coord)
{
    if (coord != m_coord) {
        m_coord = coord;
        emit coordChanged(m_coord);

        m_gmsCoord->setCoord(m_coord);
    }
}

void CoordWidget::updateCoord()
{
    qreal coord = m_gmsCoord->coord();

    if (coord != m_coord) {
        m_coord = coord;
        emit coordChanged(m_coord);

        if (m_gmsCoord->coord() != m_coord)
            m_gmsCoord->setCoord(m_coord);
    }
}

void CoordWidget::coordStyleChanged()
{
    if (m_coordStyle == GMS)
        m_stack->setCurrentIndex(GMS);
    else if (m_coordStyle == GM)
        m_stack->setCurrentIndex(GM);
}
