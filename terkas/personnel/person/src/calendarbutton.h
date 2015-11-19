#ifndef CALENDARBUTTON_H
#define CALENDARBUTTON_H

#include <QPushButton>

QT_BEGIN_NAMESPACE
class QCalendarWidget;
QT_END_NAMESPACE

class CalendarButton : public QPushButton
{
    Q_OBJECT

public:
    CalendarButton(QWidget *parent = 0);

private slots:
    void showCalendar();
    void calendarClicked(const QDate & date);

private:
    QCalendarWidget *m_calendar;
};

#endif // CALENDARBUTTON_H
