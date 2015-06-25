#include <QtWidgets>

#include "mapperdialog.h"
#include "declarations.h"


MapperDialog::MapperDialog(QSortFilterProxyModel *proxy, QWidget *parent)
    : VyborgMapperDialog(proxy, parent)
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


    mapper_->addMapping(dateEdit,            statistics_date);
    mapper_->addMapping(innerFlightsEdit,    statistics_innerFlights);
    mapper_->addMapping(foreignFlightsEdit,  statistics_foreignFlights);
    mapper_->addMapping(transitFlightsEdit,  statistics_transitFlights);
    mapper_->addMapping(charterFlightsEdit,  statistics_charterFlights);
    mapper_->addMapping(maxInDayFlightsEdit, statistics_maxInDayFlights);
    mapper_->addMapping(foreignACEdit,       statistics_foreignAC);
    mapper_->addMapping(noteEdit,            statistics_note);
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

    privateWidgetsLayout->addLayout(gridLayout);
}

void MapperDialog::updatePrivateWidgets()
{
    if (dirty_ == true) {
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
