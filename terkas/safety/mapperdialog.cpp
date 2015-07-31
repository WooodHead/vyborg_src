#include <QtWidgets>

#include "mapperdialog.h"
#include "declarations.h"


MapperDialog::MapperDialog(QSqlRelationalTableModel *model, QWidget *parent)
    : VyborgMapperDialog(model, parent)
{
    createPrivateWidgets();
    layoutPrivateWidgets();
    updatePrivateWidgets();
}

void MapperDialog::createPrivateWidgets()
{
    m_dateEdit            = new QDateEdit;
    m_dateEdit->setDisplayFormat("yyyy MMMM dd");

    m_shiftEdit = new QLineEdit;
    m_locationEdit = new QLineEdit;
    m_causeEdit = new QTextEdit;
    m_factorEdit = new QTextEdit;
    m_detailsEdit = new QTextEdit;
    m_sectorEdit = new QLineEdit;
    m_accEdit = new QLineEdit;
    m_classificationEdit = new QLineEdit;

    QDataWidgetMapper* m_mapper = mapper();
    m_mapper->addMapping(m_dateEdit,           safety_date);
    m_mapper->addMapping(m_shiftEdit,          safety_shift);
    m_mapper->addMapping(m_locationEdit,       safety_location);
    m_mapper->addMapping(m_causeEdit,          safety_cause);
    m_mapper->addMapping(m_factorEdit,         safety_factor);
    m_mapper->addMapping(m_detailsEdit,        safety_details);
    m_mapper->addMapping(m_sectorEdit,         safety_sector_id);
    m_mapper->addMapping(m_accEdit,            safety_acc);
    m_mapper->addMapping(m_classificationEdit, safety_classification);
}

void MapperDialog::layoutPrivateWidgets()
{
    QLabel *dateLabel = new QLabel(trUtf8("Дата события:"));
    dateLabel->setBuddy(m_dateEdit);

    QLabel *shiftLabel = new QLabel(trUtf8("Shift:"));
    shiftLabel->setBuddy(m_shiftEdit);

    QLabel *locationLabel = new QLabel(trUtf8("Location:"));
    locationLabel->setBuddy(m_locationEdit);

    QLabel *causeLabel = new QLabel(trUtf8("Cause:"));
    causeLabel->setBuddy(m_causeEdit);

    QLabel *factorLabel = new QLabel(trUtf8("Factor:"));
    factorLabel->setBuddy(m_factorEdit);

    QLabel *detailsLabel = new QLabel(trUtf8("Details:"));
    detailsLabel->setBuddy(m_detailsEdit);

    QLabel *sectorLabel = new QLabel(trUtf8("Sector:"));
    sectorLabel->setBuddy(m_sectorEdit);

    QLabel *accLabel = new QLabel(trUtf8("ACC:"));
    accLabel->setBuddy(m_accEdit);

    QLabel *classificationLabel = new QLabel(trUtf8("Classification:"));
    classificationLabel->setBuddy(m_classificationEdit);


    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(dateLabel,           0, 0, 1, 1);    gridLayout->addWidget(m_dateEdit,           0, 1, 1, 1);
    gridLayout->addWidget(shiftLabel,          1, 0, 1, 1);    gridLayout->addWidget(m_shiftEdit,          1, 1, 1, 1);
    gridLayout->addWidget(locationLabel,       2, 0, 1, 1);    gridLayout->addWidget(m_locationEdit,       2, 1, 1, 1);
    gridLayout->addWidget(causeLabel,          3, 0, 1, 1);    gridLayout->addWidget(m_causeEdit,          3, 1, 1, 1);
    gridLayout->addWidget(factorLabel,         4, 0, 1, 1);    gridLayout->addWidget(m_factorEdit,         4, 1, 1, 1);
    gridLayout->addWidget(detailsLabel,        5, 0, 1, 1);    gridLayout->addWidget(m_detailsEdit,        5, 1, 1, 1);
    gridLayout->addWidget(sectorLabel,         6, 0, 1, 1);    gridLayout->addWidget(m_sectorEdit,         6, 1, 1, 1);
    gridLayout->addWidget(accLabel,            7, 0, 1, 1);    gridLayout->addWidget(m_accEdit,            7, 1, 1, 1);
    gridLayout->addWidget(classificationLabel, 8, 0, 1, 1);    gridLayout->addWidget(m_classificationEdit, 8, 1, 1, 1);

    QVBoxLayout *privateWidgetsLayout = layout();
    privateWidgetsLayout->addLayout(gridLayout);
}

void MapperDialog::updatePrivateWidgets()
{
    if (isDirty()) {
//        dateEdit->setReadOnly(false);
//        innerFlightsEdit->setReadOnly(false);
//        foreignFlightsEdit->setReadOnly(false);
//        transitFlightsEdit->setReadOnly(false);
//        charterFlightsEdit->setReadOnly(false);
//        maxInDayFlightsEdit->setReadOnly(false);
//        foreignACEdit->setReadOnly(false);
//        noteEdit->setReadOnly(false);

//        dateEdit->setFocus();
    } else {
//        dateEdit->setReadOnly(true);
//        innerFlightsEdit->setReadOnly(true);
//        foreignFlightsEdit->setReadOnly(true);
//        transitFlightsEdit->setReadOnly(true);
//        charterFlightsEdit->setReadOnly(true);
//        maxInDayFlightsEdit->setReadOnly(true);
//        foreignACEdit->setReadOnly(true);
//        noteEdit->setReadOnly(true);
    }
}
