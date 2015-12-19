#include <QtWidgets>
#include <QtSql>

#include "ADwidget.h"
#include "declarations.h"
#include "tablemodel.h"
#include "proxymodel.h"
#include "mapperdialog.h"
#include "sortdialog.h"
#include "filterdialog.h"


ADwidget::ADwidget(QWidget *parent)
    : QWidget(parent)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("monrepo");
    db.setDatabaseName("aviation");
    db.open();

    m_model = new TableModel;

    m_proxy = new ProxyModel(this);
    m_proxy->setSourceModel(m_model);


    m_view = new QTableView;
    m_view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_view->setModel(m_proxy);
//    m_view->setModel(m_model);
    m_view->hideColumn(col_id);
//    m_view->hideColumn(col_milIndx2ru);
    m_view->hideColumn(col_milFRQ);
    m_view->hideColumn(col_LAT);
    m_view->hideColumn(col_LON);
    m_view->hideColumn(col_VAR);
    m_view->hideColumn(col_ELEV);
    m_view->hideColumn(col_TZ);
    m_view->hideColumn(col_milBorder);
    m_view->hideColumn(col_milBorderFLs);
    m_view->hideColumn(col_milEnterExitPointRu);
    m_view->hideColumn(col_milTerkasInfoReceiver);
    m_view->hideColumn(col_note);
    m_view->hideColumn(col_noteRu);

    m_view->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_view->setSelectionMode(QAbstractItemView::SingleSelection);
    m_view->resizeColumnsToContents();
    m_view->resizeRowsToContents();
    m_view->setAlternatingRowColors(true);

    m_view->selectRow(0);
    m_view->setFocus();

    connect(m_view, SIGNAL(doubleClicked(QModelIndex)),
            this, SLOT(showMapperDialog()));
    
    
    m_posLabel = new QLabel(trUtf8("Элемент из"));


    QPushButton *mapperButton = new QPushButton(trUtf8("Смотреть"));
    QPushButton *sortButton   = new QPushButton(trUtf8("Сортировать"));
    QPushButton *filterButton = new QPushButton(trUtf8("Найти"));
    QPushButton *updateButton = new QPushButton(trUtf8("Обновить"));
    QPushButton *addButton    = new QPushButton(trUtf8("Добавить"));
    QPushButton *delButton    = new QPushButton(trUtf8("Удалить"));


    connect(mapperButton, SIGNAL(clicked()),
            this, SLOT(showMapperDialog()));
    connect(sortButton, SIGNAL(clicked()),
            this, SLOT(showSortDialog()));
    connect(filterButton, SIGNAL(clicked()),
            this, SLOT(showFilterDialog()));
    connect(updateButton, SIGNAL(clicked()),
            this, SLOT(update()));
    connect(addButton, SIGNAL(clicked()),
            this, SLOT(add()));
    connect(delButton, SIGNAL(clicked()),
            this, SLOT(del()));


    QDialogButtonBox *buttonBox = new QDialogButtonBox(Qt::Vertical);
    buttonBox->addButton(mapperButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(sortButton,   QDialogButtonBox::ActionRole);
    buttonBox->addButton(filterButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(updateButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(addButton,    QDialogButtonBox::ActionRole);
    buttonBox->addButton(delButton,    QDialogButtonBox::ActionRole);
    buttonBox->addButton(QDialogButtonBox::Close);

    connect(buttonBox, SIGNAL(rejected()),
            qApp, SLOT(quit()));


    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(m_view);
    vLayout->addWidget(m_posLabel);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(vLayout);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(trUtf8("Аэродромы"));
}

void ADwidget::showMapperDialog()
{
    MapperDialog *dialog = new MapperDialog;
    dialog->setProxyModel(m_proxy);
    dialog->setCurrentIndex(m_view->currentIndex());
    int r = dialog->exec();

    if (r == QDialog::Accepted) {
        qDebug() << "ACCEPT";
    }
}

void ADwidget::showSortDialog()
{
    QStringList labels;
    labels << trUtf8("Index ICAO")
           << trUtf8("Индекс ИКАО")
           << trUtf8("Index IATA")
           << trUtf8("Индекс ИАТА")
           << trUtf8("Индекс государственного аэродрома")
           << trUtf8("Индекс TERKAS")
           << trUtf8("City Name")
           << trUtf8("Название города")
           << trUtf8("Aerodrome Name")
           << trUtf8("Название аэродрома")
           << trUtf8("Государственный позывной") ;

    QList<int> values;
    values << col_indxICAO
           << col_indxICAOru
           << col_indxIATA
           << col_indxIATAru
           << col_milIndx4ru
           << col_milIndx2ru
           << col_city
           << col_cityRu
           << col_AD
           << col_ADru
           << col_milCSru;

    SortDialog *sortDialog = new SortDialog;
    sortDialog->addValues(labels, values);
    int res = sortDialog->exec();
    if (res != QDialog::Rejected) {
        sort(res);
    }
}

void ADwidget::showFilterDialog()
{
    QStringList labels;
    labels << trUtf8("Index ICAO")
           << trUtf8("Индекс ИКАО")
           << trUtf8("Index IATA")
           << trUtf8("Индекс ИАТА")
           << trUtf8("Индекс государственного аэродрома")
           << trUtf8("Индекс TERKAS")
           << trUtf8("City Name")
           << trUtf8("Название города")
           << trUtf8("Aerodrome Name")
           << trUtf8("Название аэродрома")
           << trUtf8("Государственный позывной") ;

    QList<int> values;
    values << col_indxICAO
           << col_indxICAOru
           << col_indxIATA
           << col_indxIATAru
           << col_milIndx4ru
           << col_milIndx2ru
           << col_city
           << col_cityRu
           << col_AD
           << col_ADru
           << col_milCSru;

    FilterDialog *filterDialog = new FilterDialog;
    filterDialog->addValues(labels, values);
    int res = filterDialog->exec();
    if (res != QDialog::Rejected) {
        int column = filterDialog->column();
        QString pattern = filterDialog->pattern();
        Qt::CaseSensitivity cs = filterDialog->cs();
        filter(column, pattern, cs);
    }
}

void ADwidget::sort(const int &column, Qt::SortOrder order)
{
    m_proxy->sort(column, order);
    qDebug() << "SORT COLUMN: " << column;
//    m_model->sort(column, order);
}

void ADwidget::filter(const int &column, const QString &pattern, Qt::CaseSensitivity cs)
{
    m_proxy->setFilterKeyColumn(column);
    m_proxy->setFilterRegExp(QRegExp(pattern, cs, QRegExp::RegExp));
}

void ADwidget::update()
{
    m_proxy->setFilterFixedString(QString());
}

void ADwidget::add()
{
    int ret = QMessageBox::question(this,
                                    trUtf8("Добавить"),
                                    trUtf8("Добавить новый аэродром?"));
    if (ret == QMessageBox::Yes) {
        m_proxy->insertRow(0);
        QModelIndex index = m_proxy->index(0, 0);
        m_view->setCurrentIndex(index);
        m_view->selectRow(0);

        showMapperDialog();
    }
}

void ADwidget::del()
{
    int ret = QMessageBox::question(this,
                                    trUtf8("Удалить"),
                                    trUtf8("Удалить аэродром из базы данных?"));
    if (ret == QMessageBox::Yes) {
        QModelIndex index = m_view->currentIndex();
        int row = index.row();

        m_proxy->removeRow(row);

        m_view->setCurrentIndex(m_proxy->index(row - 1, 0));
        m_view->selectRow(row - 1);
    }
}
