#ifndef YEARMONTHPICKERWIDGET_H
#define YEARMONTHPICKERWIDGET_H

#include <QWidget>

namespace Ui {
class YearMonthPickerWidget;
}


class YearMonthPickerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit YearMonthPickerWidget(QWidget *parent = 0);
    ~YearMonthPickerWidget();

    void setYear(const int year);
    int year() const;
    void setMonth(const int month);
    int month() const;

signals:
    void yearChanged(int year);
    void monthChanged(int month);

private slots:
    void on_yearComboBox_currentTextChanged(const QString &year);
    void on_monthComboBox_currentIndexChanged(int month);

private:
    Ui::YearMonthPickerWidget *ui;

    int m_year;
    int m_month;
};

#endif // YEARMONTHPICKERWIDGET_H
