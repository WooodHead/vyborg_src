#include <QtWidgets>

#include "dialog.h"
#include "navigationbuttonbox.h"
#include "yearmonthwidget.h"
#include "controlbuttonbox.h"
#include "mappercontrolbuttonbox.h"
#include "yearmonth.h"
#include "mapperdialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    NavigationButtonBox *navigationButtonBox = new NavigationButtonBox;
    navigationButtonBox->setCount(10);
    navigationButtonBox->setCurrentIndex(5);


    YearMonthWidget *yearMonthWidget = new YearMonthWidget("2014", "Fe");


    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(yearMonthWidget);
    hLayout->addStretch();


    ControlButtonBox *controlButtonBox = new ControlButtonBox;
    controlButtonBox->setOrientation(Qt::Vertical);


    MapperControlButtonBox *mapperControlButtonBox = new MapperControlButtonBox;
    mapperControlButtonBox->setOrientation(Qt::Vertical);


    MapperDialog *dialog = new MapperDialog;
    dialog->show();


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(navigationButtonBox);
    mainLayout->addLayout(hLayout);
    mainLayout->addWidget(controlButtonBox);
    mainLayout->addWidget(mapperControlButtonBox);


    setLayout(mainLayout);
}
