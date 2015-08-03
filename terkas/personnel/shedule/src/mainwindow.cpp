#include <QtWidgets>
#include <QtSql>
#include <QDate>

#include "mainwindow.h"
#include "monthtablemodel.h"
#include "monthtableview.h"
#include "monthdelegate.h"
#include "yearmonthpickerwidget.h"
#include "shiftnumsectorsgrouppickerwidget.h"
#include "monthheaderview.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_monthTableModel = new MonthTableModel;


    QDate currentDate = QDate::currentDate();
    QString currentDateStr = currentDate.toString(trUtf8("'Текущая дата:' <b>dd MMMM yyyy</b>"));

    QLabel *currentDateLabel = new QLabel(currentDateStr);

    YearMonthPickerWidget *yearMonthPickerWidget = new YearMonthPickerWidget;
    ShiftNumSectorsGroupPickerWidget *shiftNumSectorsGroupPickerWidget = new ShiftNumSectorsGroupPickerWidget;
    shiftNumSectorsGroupPickerWidget->setShiftNum(4);
    shiftNumSectorsGroupPickerWidget->setSectorsGroup(9);


    MonthTableView *monthTableView = new MonthTableView;
    monthTableView->setModel(m_monthTableModel);
    monthTableView->setAlternatingRowColors(true);
    monthTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    monthTableView->setSelectionMode(QAbstractItemView::SingleSelection);

    MonthDelegate *monthDelegate = new MonthDelegate(monthTableView);
    monthDelegate->setView(monthTableView);
    monthTableView->setItemDelegate(monthDelegate);

    monthTableView->resizeColumnsToContents();
    monthTableView->resizeRowsToContents();

    MonthHeaderView *monthHeaderView = new MonthHeaderView(Qt::Vertical, monthTableView);
    monthTableView->setVerticalHeader(monthHeaderView);

    monthTableView->selectRow(0);


    QHBoxLayout *currentDateLayout = new QHBoxLayout;
    currentDateLayout->addStretch(1);
    currentDateLayout->addWidget(currentDateLabel);
    currentDateLayout->addStretch(1);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(currentDateLayout);
    mainLayout->addWidget(yearMonthPickerWidget);
    mainLayout->addWidget(shiftNumSectorsGroupPickerWidget);
    mainLayout->addWidget(monthTableView);

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(mainLayout);



    setCentralWidget(centralWidget);

    monthTableView->setFocus();


    connect(yearMonthPickerWidget, SIGNAL(yearChanged(int)),
            m_monthTableModel, SLOT(setYear(int)));
    connect(yearMonthPickerWidget, SIGNAL(monthChanged(int)),
            m_monthTableModel, SLOT(setMonth(int)));
    connect(shiftNumSectorsGroupPickerWidget, SIGNAL(shiftNumChanged(int)),
            m_monthTableModel, SLOT(setShiftNum(int)));
    connect(shiftNumSectorsGroupPickerWidget, SIGNAL(sectorsGroupChanged(int)),
            m_monthTableModel, SLOT(setSectorsGroup(int)));
}
