#include <QtWidgets>

#include "calendarbutton.h"

CalendarButton::CalendarButton(QWidget *parent) :
    QPushButton(parent)
{
    connect(this, SIGNAL(clicked(bool)),
            this, SLOT(showCalendar()));
}

void CalendarButton::showCalendar()
{
    QDate date = QDate::fromString(this->text(), "dd MMMM yyyy");

    QCalendarWidget *calendar = new QCalendarWidget;
    calendar->setSelectedDate(date);
    calendar->show();
}
