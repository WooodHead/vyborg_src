#include <QtWidgets>
#include <QSql>
#include <aviawidgets.h>

#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    GeogWidget *geogWidget = new GeogWidget;
    geogWidget->setEnabled(true);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(geogWidget);
    setLayout(mainLayout);
}
