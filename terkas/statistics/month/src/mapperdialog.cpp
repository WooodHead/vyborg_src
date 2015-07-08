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
    dateEdit            = new QDateEdit;
    dateEdit->setDisplayFormat("yyyy MMMM");

    innerFlightsEdit    = new QLineEdit;
    innerFlightsEdit->setValidator(new QIntValidator(0, 100000, this));

    foreignFlightsEdit  = new QLineEdit;
    transitFlightsEdit  = new QLineEdit;
    charterFlightsEdit  = new QLineEdit;
    maxInDayFlightsEdit = new QLineEdit;
    foreignACEdit       = new QLineEdit;
    noteEdit            = new QTextEdit;


    QDataWidgetMapper* m_mapper = mapper();
    m_mapper->addMapping(dateEdit,            statistics_date);
    m_mapper->addMapping(innerFlightsEdit,    statistics_internal);
    m_mapper->addMapping(foreignFlightsEdit,  statistics_external);
    m_mapper->addMapping(transitFlightsEdit,  statistics_transit);
    m_mapper->addMapping(charterFlightsEdit,  statistics_charter);
    m_mapper->addMapping(maxInDayFlightsEdit, statistics_maxday);
    m_mapper->addMapping(foreignACEdit,       statistics_foreigner);
    m_mapper->addMapping(noteEdit,            statistics_note);
}

void MapperDialog::layoutPrivateWidgets()
{
    QLabel *dateLabel = new QLabel(trUtf8("Year and month:"));
    dateLabel->setBuddy(dateEdit);

    QLabel *innerFlightsLabel = new QLabel(trUtf8("Inner Flights:"));
    innerFlightsLabel->setBuddy(innerFlightsEdit);

    QLabel *foreignFlightsLabel = new QLabel(trUtf8("Foreign Flights:"));
    foreignFlightsLabel->setBuddy(foreignFlightsEdit);

    QLabel *transitFlightsLabel = new QLabel(trUtf8("Transit Flights:"));
    transitFlightsLabel->setBuddy(transitFlightsEdit);

    QLabel *charterFlightsLabel = new QLabel(trUtf8("Charter Flights:"));
    charterFlightsLabel->setBuddy(charterFlightsEdit);

    QLabel *maxInDayFlightsLabel = new QLabel(trUtf8("Max in day Flights:"));
    maxInDayFlightsLabel->setBuddy(maxInDayFlightsEdit);

    QLabel *foreignACLabel = new QLabel(trUtf8("Foreign AC:"));
    foreignACLabel->setBuddy(foreignACEdit);

    QLabel *noteLabel = new QLabel(trUtf8("Note:"));
    noteLabel->setBuddy(noteEdit);


    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(dateLabel,            0, 0, 1, 1);    gridLayout->addWidget(dateEdit,            0, 1, 1, 1);
    gridLayout->addWidget(innerFlightsLabel,    1, 0, 1, 1);    gridLayout->addWidget(innerFlightsEdit,    1, 1, 1, 1);
    gridLayout->addWidget(foreignFlightsLabel,  2, 0, 1, 1);    gridLayout->addWidget(foreignFlightsEdit,  2, 1, 1, 1);
    gridLayout->addWidget(transitFlightsLabel,  3, 0, 1, 1);    gridLayout->addWidget(transitFlightsEdit,  3, 1, 1, 1);
    gridLayout->addWidget(charterFlightsLabel,  4, 0, 1, 1);    gridLayout->addWidget(charterFlightsEdit,  4, 1, 1, 1);
    gridLayout->addWidget(maxInDayFlightsLabel, 5, 0, 1, 1);    gridLayout->addWidget(maxInDayFlightsEdit, 5, 1, 1, 1);
    gridLayout->addWidget(foreignACLabel,       6, 0, 1, 1);    gridLayout->addWidget(foreignACEdit,       6, 1, 1, 1);
    gridLayout->addWidget(noteLabel,            7, 0, 1, 1);    gridLayout->addWidget(noteEdit,            7, 1, 2, 1);

    QVBoxLayout *privateWidgetsLayout = layout();
    privateWidgetsLayout->addLayout(gridLayout);
}

void MapperDialog::updatePrivateWidgets()
{
    if (isDirty()) {
        dateEdit->setReadOnly(false);
        innerFlightsEdit->setReadOnly(false);
        foreignFlightsEdit->setReadOnly(false);
        transitFlightsEdit->setReadOnly(false);
        charterFlightsEdit->setReadOnly(false);
        maxInDayFlightsEdit->setReadOnly(false);
        foreignACEdit->setReadOnly(false);
        noteEdit->setReadOnly(false);

        dateEdit->setFocus();
    } else {
        dateEdit->setReadOnly(true);
        innerFlightsEdit->setReadOnly(true);
        foreignFlightsEdit->setReadOnly(true);
        transitFlightsEdit->setReadOnly(true);
        charterFlightsEdit->setReadOnly(true);
        maxInDayFlightsEdit->setReadOnly(true);
        foreignACEdit->setReadOnly(true);
        noteEdit->setReadOnly(true);
    }
}
