#include <QtWidgets>
#include <QtSql>

#include "mainwindow.h"
#include "hourmodel.h"
#include "tableview.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    m_model = new HourModel;
    m_model->setTable("statistics.vw_sectorworkload");
    m_model->select();

    m_view = new TableView;
    m_view->setModel(m_model);
    m_view->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_view->setSelectionMode(QAbstractItemView::SingleSelection);
    m_view->selectRow(0);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(m_view);

    bbox = new QDialogButtonBox(Qt::Vertical);
    mainLayout->addWidget(bbox);

    QPushButton *addButton = new QPushButton(trUtf8("Add"));
    addButton->setProperty("ActionRole", AddRole);

    QPushButton *remButton = new QPushButton(trUtf8("Remove"));
    remButton->setProperty("ActionRole", RemRole);

    bbox->addButton(addButton, QDialogButtonBox::ActionRole);
    bbox->addButton(remButton, QDialogButtonBox::ActionRole);

    connect(bbox, SIGNAL(clicked(QAbstractButton*)),
            this, SLOT(bboxClicked(QAbstractButton*)));

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(mainLayout);

    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{

}

void MainWindow::bboxClicked(QAbstractButton *button)
{
    QDialogButtonBox::StandardButton standardButton = bbox->standardButton(button);
    switch (standardButton) {
        case QDialogButtonBox::NoButton: {
            int actionRole = button->property("ActionRole").toInt();
            switch(actionRole) {
                case AddRole:
                    break;
                case RemRole:
                    qDebug() << "Removing row";
                    rem();
                    break;
                default:
                    break;
            }
        }
    default: // shouldn't happen
        break;
    }
}

void MainWindow::add()
{

}

void MainWindow::rem()
{
    qDebug() << "rem()";
    QModelIndex indx = m_view->currentIndex();
    m_model->removeRow(indx.row());
}

void MainWindow::edit()
{

}

void MainWindow::save()
{

}

void MainWindow::rej()
{

}
