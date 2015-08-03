#include <QtSql>

#include "shiftnumsectorsgrouppickerwidget.h"
#include "ui_shiftnumsectorsgrouppickerwidget.h"


ShiftNumSectorsGroupPickerWidget::ShiftNumSectorsGroupPickerWidget(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::ShiftNumSectorsGroupPickerWidget)
{
    ui->setupUi(this);

    ui->shiftNumComboBox->clear();
    ui->shiftNumComboBox->addItem("Все смены", QVariant(0));
    ui->shiftNumComboBox->addItem("Смена 1", QVariant(1));
    ui->shiftNumComboBox->addItem("Смена 2", QVariant(2));
    ui->shiftNumComboBox->addItem("Смена 3", QVariant(3));
    ui->shiftNumComboBox->addItem("Смена 4", QVariant(4));
    ui->shiftNumComboBox->addItem("Смена 5", QVariant(5));
    ui->shiftNumComboBox->addItem("Смена 6", QVariant(6));

    QSqlQuery query;
    query.prepare("SELECT id,sectorsGroup FROM terkas.sectorsGroup");
    query.exec();
    ui->sectorsGroupComboBox->clear();
    while (query.next()) {
        int id = query.value(0).toInt();
        QString sectorsGroup = query.value(1).toString();
        ui->sectorsGroupComboBox->addItem(sectorsGroup, id);
    }
}

ShiftNumSectorsGroupPickerWidget::~ShiftNumSectorsGroupPickerWidget()
{
    delete ui;
}

void ShiftNumSectorsGroupPickerWidget::setShiftNum(const int shiftNum)
{
    if (shiftNum != m_shiftNum) {
        m_shiftNum = shiftNum;
        ui->shiftNumComboBox->setCurrentIndex(m_shiftNum);
        emit shiftNumChanged(m_shiftNum);
    }
}

int ShiftNumSectorsGroupPickerWidget::shiftNum() const
{
    return m_shiftNum;
}

void ShiftNumSectorsGroupPickerWidget::setSectorsGroup(const int sectorsGroup)
{
    if (sectorsGroup != m_sectorsGroup) {
        m_sectorsGroup = sectorsGroup;

        QSqlQuery query;
        query.prepare("SELECT sectorsGroup FROM terkas.sectorsGroup WHERE id=:id");
        query.bindValue(":id", sectorsGroup);
        query.exec();
        while (query.next()) {
            QString name = query.value(0).toString();
            ui->sectorsGroupComboBox->setCurrentText(name);
        }

        emit sectorsGroupChanged(m_sectorsGroup);
    }
}

int ShiftNumSectorsGroupPickerWidget::sectorsGroup() const
{
    return m_sectorsGroup;
}

void ShiftNumSectorsGroupPickerWidget::on_shiftNumComboBox_currentIndexChanged(int index)
{
    setShiftNum(index);
}

void ShiftNumSectorsGroupPickerWidget::on_sectorsGroupComboBox_currentIndexChanged(int index)
{
    Q_UNUSED(index)

    int id = ui->sectorsGroupComboBox->currentData().toInt();
    setSectorsGroup(id);
}
