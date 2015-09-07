#include <QtWidgets>

#include "personwidget.h"

#include <QDebug>

PersonWidget::PersonWidget(QWidget *parent)
    : QWidget(parent)
{
    qDebug() << "START";
}

QString PersonWidget::text() const
{
    return m_text;
}

void PersonWidget::setText(const QString &text)
{
    qDebug() << text;
    if (text != m_text) {
        m_text = text;
        qDebug() << m_text;
        emit textChanged();
    }
}


