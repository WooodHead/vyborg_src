#include <QtWidgets>
#include <QtSql>

#include "declarations.h"
#include "mapperdialog.h"

MapperDialog::MapperDialog(QSqlRelationalTableModel *model, QWidget *parent)
    : VyborgMapperDialog(model, parent)
{
    createPrivateWidgets();
    layoutPrivateWidgets();
    updatePrivateWidgets();
}

void MapperDialog::createPrivateWidgets()
{
    m_dateEdit = new QDateEdit;
    m_dateEdit->setDisplayFormat("yyyy MMMM");

    m_sectorEdit = new QLineEdit;
    
    m_volEdit = new QLineEdit;

    QDataWidgetMapper* m_mapper = mapper();
    m_mapper->addMapping(m_dateEdit, monthsector_date);
    m_mapper->addMapping(m_sectorEdit, monthsector_sector);
    m_mapper->addMapping(m_volEdit, monthsector_vol);
}

void MapperDialog::layoutPrivateWidgets()
{
    QLabel *dateLabel = new QLabel(trUtf8("Year and month:"));
    dateLabel->setBuddy(m_dateEdit);

    QLabel *sectorLabel = new QLabel(trUtf8("Сектор"));
    sectorLabel->setBuddy(m_sectorEdit);
    
    QLabel *volLabel = new QLabel(trUtf8("Количество ВС"));
    volLabel->setBuddy(m_volEdit);

    
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(dateLabel,   0, 0, 1, 1);    gridLayout->addWidget(m_dateEdit,   0, 1, 1, 1);
    gridLayout->addWidget(sectorLabel, 1, 0, 1, 1);    gridLayout->addWidget(m_sectorEdit, 1, 1, 1, 1);
    gridLayout->addWidget(volLabel,    2, 0, 1, 1);    gridLayout->addWidget(m_volEdit,    2, 1, 1, 1);

    QVBoxLayout *privateWidgetsLayout = layout();
    privateWidgetsLayout->addLayout(gridLayout);
}

void MapperDialog::updatePrivateWidgets()
{
    if (isDirty()) {
        m_dateEdit->setReadOnly(false);
        m_sectorEdit->setReadOnly(false);
        m_volEdit->setReadOnly(false);

        m_dateEdit->setFocus();
    } else {
        m_dateEdit->setReadOnly(true);
        m_sectorEdit->setReadOnly(true);
        m_volEdit->setReadOnly(true);
    }
}
