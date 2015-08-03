#ifndef ADDVACANCYDIALOG_H
#define ADDVACANCYDIALOG_H

#include <QDialog>
#include <QDate>

namespace Ui {
class AddVacancyDialog;
}


class AddVacancyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddVacancyDialog(QWidget *parent = 0);
    ~AddVacancyDialog();

    int personId() const;
    void setPersonId(const int personId);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_startDateCalendar_clicked(const QDate &date);
    void on_endDateCalendar_clicked(const QDate &date);
    void on_startDateEdit_dateChanged(const QDate &date);
    void on_endDateEdit_dateChanged(const QDate &date);

private:
    QDate startDate() const;
    void setStartDate(const QDate &startDate);
    QDate endDate() const;
    void setEndDate(const QDate &endDate);

private:
    Ui::AddVacancyDialog *ui;

    QDate m_startDate;
    QDate m_endDate;
    int m_personId;
};

#endif // ADDVACANCYDIALOG_H
