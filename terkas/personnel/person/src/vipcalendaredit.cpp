#include <QtWidgets>

#include "vipcalendaredit.h"

#ifndef DATE_FORMAT_OUTPUT
#define DATE_FORMAT_OUTPUT QString("dd MMMM yyyy")
#endif

VipCalendarEdit::VipCalendarEdit(QWidget *parent)
    : QWidget(parent)
{
    m_lineEdit = new QLineEdit;
    m_lineEdit->setFocusPolicy(Qt::NoFocus);

    m_button = new QPushButton(trUtf8("..."));
    QSize textSize = m_button->fontMetrics().size(Qt::TextShowMnemonic, m_button->text());
    QStyleOptionButton opt;
    opt.initFrom(m_button);
    opt.rect.setSize(textSize);
    m_button->setMinimumSize(
      m_button->style()->sizeFromContents(QStyle::CT_PushButton,
                                        &opt,
                                        textSize,
                                        m_button));




    m_calendar = new QCalendarWidget(this);
    m_calendar->setWindowModality(Qt::ApplicationModal);
    m_calendar->setWindowFlags(Qt::Dialog);

    connect(m_button, SIGNAL(clicked(bool)),
            this, SLOT(showCalendar()));
    connect(m_calendar, SIGNAL(clicked(QDate)),
            this, SLOT(calendarClicked(QDate)));

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setSpacing(0);
    layout->setMargin(0);
    layout->addWidget(m_lineEdit);
    layout->addWidget(m_button);
}

void VipCalendarEdit::showCalendar()
{
    m_calendar->setSelectedDate(m_date);
    m_calendar->show();
}

void VipCalendarEdit::calendarClicked(const QDate &date)
{
    setDate(date);
    m_calendar->hide();
}

void VipCalendarEdit::setDate(const QDate &date)
{
    if (date != m_date) {
        m_date = date;
        m_lineEdit->setText(m_date.toString(DATE_FORMAT_OUTPUT));
        emit dateChanged();
    }
}

void VipCalendarEdit::setEditable(bool editable)
{
    editable == true ? m_button->setEnabled(true)
                     : m_button->setEnabled(false);
}
