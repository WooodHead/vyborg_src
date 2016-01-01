#include <QtWidgets>
#include <QtSql>

#include "declarations.h"
#include "dialog.h"
#include "mapperdialog.h"

Dialog::Dialog(QWidget *parent)
    : VyborgMainDialog(parent)
{
    setupModel();
    setupView();

    setupMapperDialog();
    setupFilterDialog();
    setupSortDialog();
}

void Dialog::setupModel()
{
    m_model->setTable(PGSQL_TABLENAME);
    bool ret = m_model->select();
    if (ret == false) {
        QString msgText("SELECT returned FALSE: " + m_model->lastError().text());
        QMessageBox::warning(this,
                             "ERROR",
                             msgText,
                             QMessageBox::Close);
        qApp->quit();
    }

//    m_model->setHeaderData(monthsector_date, Qt::Horizontal,
//                           trUtf8("Дата\n(Месяц, Год)"), Qt::DisplayRole);
//    m_model->setHeaderData(monthsector_sector, Qt::Horizontal,
//                           trUtf8("Сектор"), Qt::DisplayRole);
//    m_model->setHeaderData(monthsector_vol, Qt::Horizontal,
//                           trUtf8("Количество"), Qt::DisplayRole);
}

void Dialog::setupView()
{
    m_view->setModel(m_model);

//    m_view->setColumnHidden(statistics_note, true);

//    m_view->setItemDelegateForColumn(monthsector_date, new TableDelegate(m_view));

    m_view->resizeRowsToContents();
    m_view->resizeColumnsToContents();

    m_view->selectRow(0);


//    QHeaderView *header = m_view->horizontalHeader();
//    header->setSectionResizeMode(statistics_date, QHeaderView::Fixed);
}

void Dialog::setupMapperDialog()
{
    MapperDialog *mapperDialog = new MapperDialog(m_model);
    m_mapperDialog = static_cast<VyborgMapperDialog *>(mapperDialog);
}

void Dialog::setupFilterDialog()
{

}

void Dialog::setupSortDialog()
{

}
