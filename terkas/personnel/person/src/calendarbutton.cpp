#include <QtWidgets>

#include "calendarbutton.h"

#ifndef DATE_FORMAT
#define DATE_FORMAT QString("dd MMMM yyyy")
#endif

CalendarButton::CalendarButton(QWidget *parent) :
    QPushButton(parent)
{
    connect(this, SIGNAL(clicked(bool)),
            this, SLOT(showCalendar()));

    m_calendar = new QCalendarWidget(this);
    m_calendar->setWindowModality(Qt::ApplicationModal);
    m_calendar->setWindowFlags(Qt::Dialog);
    connect(m_calendar, SIGNAL(clicked(QDate)),
            this, SLOT(calendarClicked(QDate)));
}

void CalendarButton::showCalendar()
{
    QDate date = QDate::fromString(this->text(), DATE_FORMAT);
    m_calendar->setSelectedDate(date);
    m_calendar->show();
}

void CalendarButton::calendarClicked(const QDate &date)
{
    this->setText(date.toString(DATE_FORMAT));
    m_calendar->hide();
}

QString CalendarButton::stringDate() const
{
    QDate date = QDate::fromString(this->text(), DATE_FORMAT);
    return QString(date.toString("yyyy-MM-dd"));
}
