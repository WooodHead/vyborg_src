#include <QDate>

#include "yearmonthpickerwidget.h"
#include "ui_yearmonthpickerwidget.h"


YearMonthPickerWidget::YearMonthPickerWidget(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::YearMonthPickerWidget)
{
    ui->setupUi(this);

    QDate currentDate = QDate::currentDate();
    setYear(currentDate.year());
    setMonth(currentDate.month());

    ui->yearComboBox->setCurrentText(QString::number(m_year));
    ui->monthComboBox->setCurrentIndex(m_month);
}

YearMonthPickerWidget::~YearMonthPickerWidget()
{
    delete ui;
}

void YearMonthPickerWidget::setYear(const int year)
{
    if (year != m_year) {
        m_year = year;
        emit yearChanged(m_year);
    }
}

int YearMonthPickerWidget::year() const
{
    return m_year;
}

void YearMonthPickerWidget::setMonth(const int month)
{
    if (month != m_month) {
        m_month = month;
        emit monthChanged(m_month);
    }
}

int YearMonthPickerWidget::month() const
{
    return m_month;
}

void YearMonthPickerWidget::on_yearComboBox_currentTextChanged(const QString &year)
{
    setYear(year.toInt());
}

void YearMonthPickerWidget::on_monthComboBox_currentIndexChanged(int month)
{
    setMonth(month);
}
