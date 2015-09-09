#include <QtWidgets>

#include "personwidget.h"

PersonWidget::PersonWidget(QWidget *parent) : QWidget(parent)
{
    m_fullnameLE = new QLineEdit;
    m_numLE = new QLineEdit;
    m_shiftLE = new QLineEdit;

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(trUtf8("Имя:"), m_fullnameLE);
    formLayout->addRow(trUtf8("Табельный номер:"), m_numLE);
    formLayout->addRow(trUtf8("Номер смены"), m_shiftLE);

    setLayout(formLayout);
}

void PersonWidget::setPid(const int &pid)
{
    if (pid != m_pid)
    {
        m_pid = pid;
        emit pidChanged(m_pid);
    }
}

int PersonWidget::pid() const
{
    return m_pid;
}
