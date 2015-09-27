#include <QtWidgets>
#include <QtSql>

#include "personwidget.h"

PersonWidget::PersonWidget(QWidget *parent) : QWidget(parent)
{
    m_fullnameLE = new QLineEdit;
    m_numLE = new QLineEdit;
    m_shiftLE = new QLineEdit;

    QHBoxLayout *numShiftLayout = new QHBoxLayout;
    numShiftLayout->addWidget(m_numLE);
    numShiftLayout->addWidget(new QLabel(trUtf8("Номер смены:")));
    numShiftLayout->addWidget(m_shiftLE);


    QFormLayout *formLayout = new QFormLayout;
    formLayout->setMargin(0);
    formLayout->setFormAlignment(Qt::AlignRight);

    formLayout->addRow(trUtf8("Имя:"), m_fullnameLE);
    formLayout->addRow(trUtf8("Табельный номер:"), numShiftLayout);

    setLayout(formLayout);
}

void PersonWidget::setPid(const int &pid)
{
    if (pid != m_pid)
    {
        m_pid = pid;
        emit pidChanged(m_pid);

        QSqlQuery query;
        query.prepare("SELECT * FROM person.vw_personwidget "
                      "WHERE pid=:id");
        query.bindValue(":id", m_pid);
        query.exec();
        query.next();
        QString fullname = query.value("fullname").toString();
        QString num = query.value("num").toString();
        QString shift = query.value("shift").toString();

        m_fullnameLE->setText(fullname);
        m_numLE->setText(num);
        m_shiftLE->setText(shift);
    }
}

int PersonWidget::pid() const
{
    return m_pid;
}
