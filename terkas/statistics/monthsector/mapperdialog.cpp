#include <QtWidgets>
#include <QtSql>

#include "declarations.h"
#include "mapperdialog.h"
#include "mapperdelegate.h"

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

    m_sectorCombo = new QComboBox;
    
    m_volEdit = new QLineEdit;

    QDataWidgetMapper* m_mapper = mapper();
    m_mapper->addMapping(m_dateEdit, monthsector_date);
    m_mapper->addMapping(m_sectorCombo, monthsector_sector);
    m_mapper->addMapping(m_volEdit, monthsector_vol);
    m_mapper->setItemDelegate(new MapperDelegate);
}

void MapperDialog::layoutPrivateWidgets()
{
    QLabel *dateLabel = new QLabel(trUtf8("Year and month:"));
    dateLabel->setBuddy(m_dateEdit);

    QLabel *sectorLabel = new QLabel(trUtf8("Сектор"));
    sectorLabel->setBuddy(m_sectorCombo);
    
    QLabel *volLabel = new QLabel(trUtf8("Количество ВС"));
    volLabel->setBuddy(m_volEdit);

    
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(dateLabel,   0, 0, 1, 1);    gridLayout->addWidget(m_dateEdit,   0, 1, 1, 1);
    gridLayout->addWidget(sectorLabel, 1, 0, 1, 1);    gridLayout->addWidget(m_sectorCombo, 1, 1, 1, 1);
    gridLayout->addWidget(volLabel,    2, 0, 1, 1);    gridLayout->addWidget(m_volEdit,    2, 1, 1, 1);

    QVBoxLayout *privateWidgetsLayout = layout();
    privateWidgetsLayout->addLayout(gridLayout);
}

void MapperDialog::updatePrivateWidgets()
{
    if (isDirty()) {
        m_dateEdit->setReadOnly(false);
        m_sectorCombo->setEditable(true);
        m_volEdit->setReadOnly(false);

        m_dateEdit->setFocus();
    } else {
        m_dateEdit->setReadOnly(true);
        m_sectorCombo->setEditable(false);
        m_volEdit->setReadOnly(true);
    }
}
