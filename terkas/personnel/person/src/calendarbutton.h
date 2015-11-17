#ifndef CALENDARBUTTON_H
#define CALENDARBUTTON_H

#include <QPushButton>

class CalendarButton : public QPushButton
{
    Q_OBJECT

public:
    CalendarButton(QWidget *parent = 0);

private slots:
    void showCalendar();
};

#endif // CALENDARBUTTON_H
