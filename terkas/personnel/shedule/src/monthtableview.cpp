#include <QMouseEvent>
#include <QtSql>

#include "declarations.h"
#include "monthtableview.h"
#include "monthtablemodel.h"

MonthTableView::MonthTableView(QWidget *parent)
    : QTableView(parent)
{
}

#include <QDebug>
void MonthTableView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton) {
        QModelIndex index = indexAt(event->pos());
        int cellData = index.data(Qt::EditRole).toInt();

        switch (cellData) {
        case ACTIVITY_VACATION:
            MonthTableModel *monthTableModel = model();
            QDate date = monthTableModel->dateData(index);
            int personId = monthTableModel->personIdData(index);
            QString table("id" + QString::number(personId));

            QSqlQuery query;
            query.prepare("DELETE FROM "
                          + table + " " +
                          "WHERE :date BETWEEN startDate AND endDate");
            query.bindValue(":date", date);
            query.exec();

            break;
        }
    } else {
        QTableView::mousePressEvent(event);
    }
}

MonthTableModel* MonthTableView::model()
{
    MonthTableModel *monthTableModel;
    monthTableModel = static_cast<MonthTableModel *>(QTableView::model());
    return monthTableModel;
}
