#include <QtSql>
#include <QMessageBox>

#include "addvacationdialog.h"
#include "ui_addvacationdialog.h"
#include "declarations.h"


AddVacancyDialog::AddVacancyDialog(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::AddVacancyDialog)
{
    m_startDate = QDate::currentDate();
    m_endDate = QDate::currentDate();


    ui->setupUi(this);

    ui->startDateEdit->setDate(m_startDate);
    ui->endDateEdit->setDate(m_endDate);
}

AddVacancyDialog::~AddVacancyDialog()
{
    delete ui;
}

void AddVacancyDialog::on_buttonBox_accepted()
{
    int activity_id = ACTIVITY_VACATION;
    QString table("id" + QString::number(m_personId));

    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS "
                  + table + " " +
                  "LIKE id5294");
    query.bindValue(":table", table);
    query.exec();

    query.clear();
    query.prepare("INSERT INTO "
                  + table + " " +
                  "(activity_id, startDate, endDate) "
                  "VALUES "
                  "(:activity_id, :startDate, :endDate)");
    query.bindValue(":table", table);
    query.bindValue(":activity_id", activity_id);
    query.bindValue(":startDate", m_startDate);
    query.bindValue(":endDate", m_endDate);
    query.exec();
}

void AddVacancyDialog::on_buttonBox_rejected()
{
}

QDate AddVacancyDialog::startDate() const
{
    return m_startDate;
}

void AddVacancyDialog::setStartDate(const QDate &startDate)
{
    if (startDate > m_endDate) {
        QMessageBox::warning(this,
                             trUtf8("Предупреждение"),
                             trUtf8("Дата начала отпуска не может быть\n"
                                    "позже даты окончания отпуска!"),
                             QMessageBox::Close);
        return;
    }

    if (startDate != m_startDate) {
        m_startDate = startDate;

        ui->startDateEdit->setDate(m_startDate);
        ui->startDateCalendar->setSelectedDate(m_startDate);
        ui->durationSpinBox->setValue(m_startDate.daysTo(m_endDate) + 1);
    }
}

QDate AddVacancyDialog::endDate() const
{
    return m_endDate;
}

void AddVacancyDialog::setEndDate(const QDate &endDate)
{
    if (endDate < m_startDate) {
        QMessageBox::warning(this,
                             trUtf8("Предупреждение"),
                             trUtf8("Дата окончания отпуска не может быть\n"
                                    "раньше даты начала отпуска!"),
                             QMessageBox::Close);
        return;
    }

    if (endDate != m_endDate) {
        m_endDate = endDate;

        ui->endDateEdit->setDate(m_endDate);
        ui->endDateCalendar->setSelectedDate(m_endDate);
        ui->durationSpinBox->setValue(m_startDate.daysTo(m_endDate) + 1);
    }
}

int AddVacancyDialog::personId() const
{
    return m_personId;
}

void AddVacancyDialog::setPersonId(const int personId)
{
    if (personId != m_personId) {
        m_personId = personId;

        QSqlQuery query;
        query.prepare("SELECT surname, name, middleName "
                      "FROM person "
                      "WHERE personId=:personId");
        query.bindValue(":personId", m_personId);
        query.exec();
        while (query.next()) {
            QString surname = query.value(0).toString();
            QString name = query.value(1).toString().mid(0, 1);
            QString middleName = query.value(2).toString().mid(0, 1);
            QString fullName = QString(surname + " " + name + ". " + middleName + ".");
            ui->nameLabel->setText(fullName);
        }
    }
}

void AddVacancyDialog::on_startDateCalendar_clicked(const QDate &date)
{
    setStartDate(date);
}

void AddVacancyDialog::on_endDateCalendar_clicked(const QDate &date)
{
    setEndDate(date);
}

void AddVacancyDialog::on_startDateEdit_dateChanged(const QDate &date)
{
    setStartDate(date);
}

void AddVacancyDialog::on_endDateEdit_dateChanged(const QDate &date)
{
    setEndDate(date);
}
