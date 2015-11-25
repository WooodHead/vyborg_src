#include <QtWidgets>

#include "sectoradmittancewidget.h"

SectorAdmittanceWidget::SectorAdmittanceWidget(QWidget *parent)
    : QWidget(parent)
{
    QLabel *label1 = new QLabel(trUtf8("Горьковское направлениe"));

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

    QLabel *label2 = new QLabel(trUtf8("Север-Ленинград-Западное направление"));

    m_checkS1 = new QCheckBox(trUtf8("С1"));
    m_checkL1 = new QCheckBox(trUtf8("Л1"));
    m_checkZ1 = new QCheckBox(trUtf8("З1"));
    m_checkZ2 = new QCheckBox(trUtf8("З2"));

    QHBoxLayout *hlayout2 = new QHBoxLayout;
    hlayout2->addWidget(m_checkS1);
    hlayout2->addWidget(m_checkL1);
    hlayout2->addWidget(m_checkZ1);
    hlayout2->addWidget(m_checkZ2);
    hlayout2->addStretch(1);

    QLabel *label3 = new QLabel(trUtf8("Киев-Харьковское направление"));

    m_checkK1 = new QCheckBox(trUtf8("К1"));
    m_checkK2 = new QCheckBox(trUtf8("К2"));
    m_checkH1 = new QCheckBox(trUtf8("Х1"));
    m_checkH2 = new QCheckBox(trUtf8("Х2"));

    QHBoxLayout *hlayout3 = new QHBoxLayout;
    hlayout3->addWidget(m_checkK1);
    hlayout3->addWidget(m_checkK2);
    hlayout3->addWidget(m_checkH1);
    hlayout3->addWidget(m_checkH2);
    hlayout3->addStretch(1);

    QLabel *label4 = new QLabel(trUtf8("Пензенское направление"));

    m_checkV1 = new QCheckBox(trUtf8("В1"));
    m_checkP1 = new QCheckBox(trUtf8("П1"));
    m_checkP2 = new QCheckBox(trUtf8("П2"));

    QHBoxLayout *hlayout4 = new QHBoxLayout;
    hlayout4->addWidget(m_checkV1);
    hlayout4->addWidget(m_checkP1);
    hlayout4->addWidget(m_checkP2);
    hlayout4->addStretch(1);

    QLabel *label5 = new QLabel(trUtf8("Воронежское направление"));

    m_checkV2 = new QCheckBox(trUtf8("В2"));
    m_checkV3 = new QCheckBox(trUtf8("В3"));
    m_checkV4 = new QCheckBox(trUtf8("В4"));

    QHBoxLayout *hlayout5 = new QHBoxLayout;
    hlayout5->addWidget(m_checkV2);
    hlayout5->addWidget(m_checkV3);
    hlayout5->addWidget(m_checkV4);
    hlayout5->addStretch(1);

    QLabel *label6 = new QLabel(trUtf8("Внетрассовый сектор (Саксофон), Москва-Центр"));

    m_checkA1 = new QCheckBox(trUtf8("А1"));
    m_checkA2 = new QCheckBox(trUtf8("А2"));
    m_checkA3 = new QCheckBox(trUtf8("А3"));
    m_checkA5 = new QCheckBox(trUtf8("А5"));

    QHBoxLayout *hlayout6 = new QHBoxLayout;
    hlayout6->addWidget(m_checkA1);
    hlayout6->addWidget(m_checkA2);
    hlayout6->addWidget(m_checkA3);
    hlayout6->addWidget(m_checkA5);
    hlayout6->addStretch(1);



    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addWidget(label1);
    vlayout->addLayout(hlayout1);
    vlayout->addSpacing(10);
    vlayout->addWidget(label2);
    vlayout->addLayout(hlayout2);
    vlayout->addSpacing(10);
    vlayout->addWidget(label3);
    vlayout->addLayout(hlayout3);
    vlayout->addSpacing(10);
    vlayout->addWidget(label4);
    vlayout->addLayout(hlayout4);
    vlayout->addSpacing(10);
    vlayout->addWidget(label5);
    vlayout->addLayout(hlayout5);
    vlayout->addSpacing(10);
    vlayout->addWidget(label6);
    vlayout->addLayout(hlayout6);
    vlayout->addStretch(1);

    QGroupBox *groupBox = new QGroupBox(trUtf8("Допуски на секторах"));
    groupBox->setLayout(vlayout);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(groupBox);
}

void SectorAdmittanceWidget::setArray(const QString &array)
{
    m_checkG2->setChecked(false);
    m_checkG3->setChecked(false);
    m_checkG4->setChecked(false);
    m_checkG5->setChecked(false);
    m_checkG6->setChecked(false);
    m_checkS1->setChecked(false);
    m_checkL1->setChecked(false);
    m_checkZ1->setChecked(false);
    m_checkZ2->setChecked(false);
    m_checkK1->setChecked(false);
    m_checkK2->setChecked(false);
    m_checkH1->setChecked(false);
    m_checkH2->setChecked(false);
    m_checkV1->setChecked(false);
    m_checkP1->setChecked(false);
    m_checkP2->setChecked(false);
    m_checkV2->setChecked(false);
    m_checkV3->setChecked(false);
    m_checkV4->setChecked(false);
    m_checkA1->setChecked(false);
    m_checkA2->setChecked(false);
    m_checkA3->setChecked(false);
    m_checkA5->setChecked(false);

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
            else if (position == trUtf8("Г3"))
                m_checkG3->setChecked(true);
            else if (position == trUtf8("Г4"))
                m_checkG4->setChecked(true);
            else if (position == trUtf8("Г5"))
                m_checkG5->setChecked(true);
            else if (position == trUtf8("Г6"))
                m_checkG6->setChecked(true);
            else if (position == trUtf8("С1"))
                m_checkS1->setChecked(true);
            else if (position == trUtf8("Л1"))
                m_checkL1->setChecked(true);
            else if (position == trUtf8("З1"))
                m_checkZ1->setChecked(true);
            else if (position == trUtf8("З2"))
                m_checkZ2->setChecked(true);
            else if (position == trUtf8("К1"))
                m_checkK1->setChecked(true);
            else if (position == trUtf8("К2"))
                m_checkK2->setChecked(true);
            else if (position == trUtf8("Х1"))
                m_checkH1->setChecked(true);
            else if (position == trUtf8("Х2"))
                m_checkH2->setChecked(true);
            else if (position == trUtf8("В1"))
                m_checkV1->setChecked(true);
            else if (position == trUtf8("П1"))
                m_checkP1->setChecked(true);
            else if (position == trUtf8("П2"))
                m_checkP2->setChecked(true);
            else if (position == trUtf8("В2"))
                m_checkV2->setChecked(true);
            else if (position == trUtf8("В3"))
                m_checkV3->setChecked(true);
            else if (position == trUtf8("В4"))
                m_checkV4->setChecked(true);
            else if (position == trUtf8("А1"))
                m_checkA1->setChecked(true);
            else if (position == trUtf8("А2"))
                m_checkA2->setChecked(true);
            else if (position == trUtf8("А3"))
                m_checkA3->setChecked(true);
            else if (position == trUtf8("А5"))
                m_checkA5->setChecked(true);
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
    if (m_checkG3->isChecked())
    {
        secAdm.isNull() ? secAdm.append(trUtf8("Г3"))
                        : secAdm.append(trUtf8(",Г3"));
    }
    if (m_checkG4->isChecked())
    {
        secAdm.isNull() ? secAdm.append(trUtf8("Г4"))
                        : secAdm.append(trUtf8(",Г4"));
    }
    if (m_checkG5->isChecked())
    {
        secAdm.isNull() ? secAdm.append(trUtf8("Г5"))
                        : secAdm.append(trUtf8(",Г5"));
    }
    if (m_checkG6->isChecked())
    {
        secAdm.isNull() ? secAdm.append(trUtf8("Г6"))
                        : secAdm.append(trUtf8(",Г6"));
    }
    if (m_checkS1->isChecked())
    {
        secAdm.isNull() ? secAdm.append(trUtf8("С1"))
                        : secAdm.append(trUtf8(",С1"));
    }
    if (m_checkL1->isChecked())
    {
        secAdm.isNull() ? secAdm.append(trUtf8("Л1"))
                        : secAdm.append(trUtf8(",Л1"));
    }
    if (m_checkZ1->isChecked())
    {
        secAdm.isNull() ? secAdm.append(trUtf8("З1"))
                        : secAdm.append(trUtf8(",З1"));
    }
    if (m_checkZ2->isChecked())
    {
        secAdm.isNull() ? secAdm.append(trUtf8("З2"))
                        : secAdm.append(trUtf8(",З2"));
    }
    if (m_checkK1->isChecked())
    {
        secAdm.isNull() ? secAdm.append(trUtf8("К1"))
                        : secAdm.append(trUtf8(",К1"));
    }
    if (m_checkK2->isChecked())
    {
        secAdm.isNull() ? secAdm.append(trUtf8("К2"))
                        : secAdm.append(trUtf8(",К2"));
    }
    if (m_checkH1->isChecked())
    {
        secAdm.isNull() ? secAdm.append(trUtf8("Х1"))
                        : secAdm.append(trUtf8(",Х1"));
    }
    if (m_checkH2->isChecked())
    {
        secAdm.isNull() ? secAdm.append(trUtf8("Х2"))
                        : secAdm.append(trUtf8(",Х2"));
    }
    if (m_checkV1->isChecked())
    {
        secAdm.isNull() ? secAdm.append(trUtf8("В1"))
                        : secAdm.append(trUtf8(",В1"));
    }
    if (m_checkP1->isChecked())
    {
        secAdm.isNull() ? secAdm.append(trUtf8("П1"))
                        : secAdm.append(trUtf8(",П1"));
    }
    if (m_checkP2->isChecked())
    {
        secAdm.isNull() ? secAdm.append(trUtf8("П2"))
                        : secAdm.append(trUtf8(",П2"));
    }
    if (m_checkV2->isChecked())
    {
        secAdm.isNull() ? secAdm.append(trUtf8("В2"))
                        : secAdm.append(trUtf8(",В2"));
    }
    if (m_checkV3->isChecked())
    {
        secAdm.isNull() ? secAdm.append(trUtf8("В3"))
                        : secAdm.append(trUtf8(",В3"));
    }
    if (m_checkV4->isChecked())
    {
        secAdm.isNull() ? secAdm.append(trUtf8("В4"))
                        : secAdm.append(trUtf8(",В4"));
    }
    if (m_checkA1->isChecked())
    {
        secAdm.isNull() ? secAdm.append(trUtf8("А1"))
                        : secAdm.append(trUtf8(",А1"));
    }
    if (m_checkA2->isChecked())
    {
        secAdm.isNull() ? secAdm.append(trUtf8("А2"))
                        : secAdm.append(trUtf8(",А2"));
    }
    if (m_checkA3->isChecked())
    {
        secAdm.isNull() ? secAdm.append(trUtf8("А3"))
                        : secAdm.append(trUtf8(",А3"));
    }
    if (m_checkA5->isChecked())
    {
        secAdm.isNull() ? secAdm.append(trUtf8("А5"))
                        : secAdm.append(trUtf8(",А5"));
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
