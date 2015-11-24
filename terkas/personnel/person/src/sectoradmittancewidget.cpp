#include <QtWidgets>

#include "sectoradmittancewidget.h"

SectorAdmittanceWidget::SectorAdmittanceWidget(QWidget *parent)
    : QWidget(parent)
{
    m_checkG2 = new QCheckBox(trUtf8("Г2"));
    m_checkG3 = new QCheckBox(trUtf8("Г3"));
    m_checkG4 = new QCheckBox(trUtf8("Г4"));
    m_checkG5 = new QCheckBox(trUtf8("Г5"));
    m_checkG6 = new QCheckBox(trUtf8("Г6"));

    QHBoxLayout *hlayout1 = new QHBoxLayout;
    hlayout1->addWidget(m_checkG2);
    hlayout1->addWidget(m_checkG3);
    hlayout1->addWidget(m_checkG4);
    hlayout1->addWidget(m_checkG5);
    hlayout1->addWidget(m_checkG6);
    hlayout1->addStretch(1);

    QLabel *label1 = new QLabel(trUtf8("Горьковское направлениe"));

    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addWidget(label1);
    vlayout->addLayout(hlayout1);
//    vlayout->addSpacing(10);
    vlayout->addStretch(1);

    QGroupBox *groupBox = new QGroupBox(trUtf8("Допуски на секторах"));
    groupBox->setLayout(vlayout);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(groupBox);
}

void SectorAdmittanceWidget::setArray(const QString &array)
{
    m_checkG2->setChecked(false);
    m_checkG5->setChecked(false);

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

            if (position == trUtf8("Г2"))
                m_checkG2->setChecked(true);
            else if (position == trUtf8("Г5"))
                m_checkG5->setChecked(true);
        }
    }
}

QString SectorAdmittanceWidget::array() const
{
    QString secAdm = QString();

    if (m_checkG2->isChecked())
    {
        secAdm.isNull() ? secAdm.append(trUtf8("Г2"))
                        : secAdm.append(trUtf8(",Г2"));
    }
    if (m_checkG5->isChecked())
    {
        secAdm.isNull() ? secAdm.append(trUtf8("Г5"))
                        : secAdm.append(trUtf8(",Г5"));
    }

    if (!secAdm.isNull())
    {
        secAdm.prepend("{");
        secAdm.append("}");
        return secAdm;
    }
    else
        return QString();
}
