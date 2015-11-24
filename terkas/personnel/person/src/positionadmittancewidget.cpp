#include <QtWidgets>
#include <QStringList>

#include "positionadmittancewidget.h"

PositionAdmittanceWidget::PositionAdmittanceWidget(QWidget *parent)
    : QWidget(parent)
{
    m_checkRP    = new QCheckBox(trUtf8("Руководитель полетов"));
    m_checkSD    = new QCheckBox(trUtf8("Старший диспетчер"));
    m_checkDI    = new QCheckBox(trUtf8("Диспетчер-инструктор"));
    m_checkD     = new QCheckBox(trUtf8("Диспетчер РЛУ и ПК"));
    m_checkSDGOP = new QCheckBox(trUtf8("Старший диспетчер ГОП"));
    m_checkDGOP  = new QCheckBox(trUtf8("Диспетчер ГОП"));

    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addWidget(m_checkRP);
    vlayout->addWidget(m_checkSD);
    vlayout->addWidget(m_checkDI);
    vlayout->addWidget(m_checkD);
    vlayout->addSpacing(10);
    vlayout->addWidget(m_checkSDGOP);
    vlayout->addWidget(m_checkDGOP);
    vlayout->addStretch(1);

    QGroupBox *groupBox = new QGroupBox(trUtf8("Допуски к работе"));
    groupBox->setLayout(vlayout);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(groupBox);
}

QString PositionAdmittanceWidget::array() const
{
    QString posAdm = QString();

    if (m_checkRP->isChecked())
    {
        posAdm.isNull() ? posAdm.append(trUtf8("РП"))
                        : posAdm.append(trUtf8(",РП"));
    }
    if (m_checkSD->isChecked())
    {
        posAdm.isNull() ? posAdm.append(trUtf8("СД"))
                        : posAdm.append(trUtf8(",СД"));
    }
    if (m_checkDI->isChecked())
    {
        posAdm.isNull() ? posAdm.append(trUtf8("ДИ"))
                        : posAdm.append(trUtf8(",ДИ"));
    }
    if (m_checkD->isChecked())
    {
        posAdm.isNull() ? posAdm.append(trUtf8("Дисп"))
                        : posAdm.append(trUtf8(",Дисп"));
    }
    if (m_checkSDGOP->isChecked())
    {
        posAdm.isNull() ? posAdm.append(trUtf8("СДГОП"))
                        : posAdm.append(trUtf8(",СДГОП"));
    }
    if (m_checkDGOP->isChecked())
    {
        posAdm.isNull() ? posAdm.append(trUtf8("ДиспГОП"))
                        : posAdm.append(trUtf8(",ДиспГОП"));
    }

    if (!posAdm.isNull())
    {
        posAdm.prepend("{");
        posAdm.append("}");
        return posAdm;
    }
    else
        return QString();
}

void PositionAdmittanceWidget::setArray(const QString &array)
{
    m_checkRP->setChecked(false);
    m_checkSD->setChecked(false);
    m_checkDI->setChecked(false);
    m_checkD->setChecked(false);
    m_checkSDGOP->setChecked(false);
    m_checkDGOP->setChecked(false);

    if (!array.isEmpty()) {
        QRegExp rx("(\\w+)");
        QStringList list;
        int pos = 0;

        while ((pos = rx.indexIn(array, pos)) != -1) {
            list << rx.cap(1);
            pos += rx.matchedLength();
        }

        for (int i = 0; i < list.size(); i++)
        {
            QString position = list.at(i);

            if (position == trUtf8("РП"))
                m_checkRP->setChecked(true);
            else if (position == trUtf8("СД"))
                m_checkSD->setChecked(true);
            else if (position == trUtf8("ДИ"))
                m_checkDI->setChecked(true);
            else if (position == trUtf8("Дисп"))
                m_checkD->setChecked(true);
            else if (position == trUtf8("СДГОП"))
                m_checkSDGOP->setChecked(true);
            else if (position == trUtf8("ДиспГОП"))
                m_checkDGOP->setChecked(true);
        }
    }
}
