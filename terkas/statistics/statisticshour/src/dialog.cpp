#include <QtWidgets>
#include <QtSql>

#include "dialog.h"
#include "hourmodel.h"
#include "tableview.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    HourModel *model = new HourModel;
    model->setTable("statistics.vw_sectorworkload");
    model->select();

    TableView *view = new TableView;
    view->setModel(model);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setSelectionMode(QAbstractItemView::SingleSelection);
    view->selectRow(0);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(view);

//    QDialogButtonBox *bbox = new QDialogButtonBox(Qt::Vertical);
//    mainLayout->addWidget(bbox);

//    QPushButton *addButton = bbox->addButton("Add", QDialogButtonBox::InvalidRole);
//    QPushButton *delButton = bbox->addButton("Remove", QDialogButtonBox::InvalidRole);

    setLayout(mainLayout);
}

void Dialog::add()
{

}

void Dialog::remove()
{

}

void Dialog::edit()
{

}

void Dialog::save()
{

}

void Dialog::reject()
{

}
