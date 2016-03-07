#include <QtWidgets>
#include <QSql>
#include <aviawidgets.h>

#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    GeogWidget *geogWidget = new GeogWidget;
    geogWidget->setEnabled(true);
    geogWidget->setGeog("0101000020E61000000282397AFCA24240CDCCCCCCCCCC4B40");
//    geogWidget->setGeog("");

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(geogWidget);
    setLayout(mainLayout);
}
