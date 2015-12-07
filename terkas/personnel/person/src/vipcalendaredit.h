#ifndef VIPCALENDAREDIT_H
#define VIPCALENDAREDIT_H

#include <QWidget>
#include <QDate>

QT_BEGIN_NAMESPACE
class QCalendarWidget;
class QLineEdit;
class QPushButton;
QT_END_NAMESPACE

class VipCalendarEdit : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QDate date READ date WRITE setDate NOTIFY dateChanged USER true)

public:
    explicit VipCalendarEdit(QWidget *parent = 0);

public Q_SLOTS:
    QDate date() const { return m_date; }
    void setDate(const QDate &date);

    void setEditable(bool editable);

Q_SIGNALS:
    void dateChanged();

private Q_SLOTS:
    void showCalendar();
    void clearDate() { setDate(QDate()); }
    void calendarClicked(const QDate & date);

private:
    // Visual elements
    QCalendarWidget *m_calendar;
    QLineEdit       *m_lineEdit;
    QPushButton     *m_buttonChange;
    QPushButton     *m_buttonClear;

    // Variables
    QDate m_date;
};

#endif // VIPCALENDAREDIT_H
