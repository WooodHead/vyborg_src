#include <QtWidgets>
#include <QSql>
#include <aviawidgets.h>

#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    geogWidget = new GeogWidget;
    geogWidget->setEnabled(true);
//    geogWidget->setGeog("0101000020E61000000282397AFCA24240CDCCCCCCCCCC4B40");
//    geogWidget->setGeog(QString());
    geogWidget->setGeog("0101000020E6100000D925AAB7066A4240EACF7EA488284940");

    button = new QPushButton("Click me");
    connect(button, SIGNAL(clicked(bool)),
            this, SLOT(buttonClicked()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(geogWidget);
    mainLayout->addWidget(button);

    setLayout(mainLayout);
}

void Dialog::buttonClicked()
{
    QString geog = geogWidget->geog();
    qDebug() << "GEOG WIDGET OUT" << geog;
}
