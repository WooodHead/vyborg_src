#include <QtWidgets>

#include "calendarbutton.h"

CalendarButton::CalendarButton(QWidget *parent) :
    QPushButton(parent)
{
    connect(this, SIGNAL(clicked(bool)),
            this, SLOT(showCalendar()));

    m_calendar = new QCalendarWidget;
    connect(m_calendar, SIGNAL(clicked(QDate)),
            this, SLOT(calendarClicked(QDate)));
}

void CalendarButton::showCalendar()
{
    QDate date = QDate::fromString(this->text(), "dd MMMM yyyy");

    m_calendar->setSelectedDate(date);
    m_calendar->show();
}

void CalendarButton::calendarClicked(const QDate &date)
{
    this->setText(date.toString("dd MMMM yyyy"));
    m_calendar->close();
}
