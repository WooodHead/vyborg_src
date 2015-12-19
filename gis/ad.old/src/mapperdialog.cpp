#include <QtWidgets>

#include "mapperdialog.h"
#include "declarations.h"
#include "proxymodel.h"


MapperDialog::MapperDialog(QWidget *parent)
    : QDialog(parent)
{
    m_mapper = new QDataWidgetMapper(this);
    m_mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);

    m_ICAOlineEdit =                  new QLineEdit;
    m_milICAOlineEdit =               new QLineEdit;
    m_IATAlineEdit =                  new QLineEdit;
    m_mil2letterCodeRuLineEdit =      new QLineEdit;
    m_cityLineEdit =                  new QLineEdit;
    m_cityRuLineEdit =                new QLineEdit;
    m_ADlineEdit =                    new QLineEdit;
    m_ADruLineEdit =                  new QLineEdit;
    m_milCSruLineEdit =               new QLineEdit;
    m_milFRQlineEdit =                new QLineEdit;
    m_LATlineEdit =                   new QLineEdit;
    m_LONlineEdit =                   new QLineEdit;
    m_VARlineEdit =                   new QLineEdit;
    m_ELEVlineEdit =                  new QLineEdit;
    m_timeZoneLineEdit =              new QLineEdit;
    m_milBorderLineEdit =             new QLineEdit;
    m_milBorderFLsLineEdit =          new QLineEdit;
    m_milEnterExitPointRuLineEdit =   new QLineEdit;
    m_milTerkasInfoReceiverLineEdit = new QLineEdit;
    m_noteLineEdit =                  new QLineEdit;
    m_noteRuLineEdit =                new QLineEdit;

    m_tabWidget = new QTabWidget;
    m_tabWidget->addTab(generalPage(),  trUtf8("Общая информация"));
    m_tabWidget->addTab(militaryPage(), trUtf8("Государственные аэродромы"));


    QPushButton *editButton   = new QPushButton(trUtf8("Редактировать"));
    QPushButton *submitButton = new QPushButton(trUtf8("Сохранить"));
    QPushButton *revertButton = new QPushButton(trUtf8("Отменить"));

    connect(submitButton, SIGNAL(clicked()),
            this, SLOT(submit()));

    QDialogButtonBox *buttonBox = new QDialogButtonBox(Qt::Vertical);
    buttonBox->addButton(editButton,   QDialogButtonBox::ActionRole);
    buttonBox->addButton(submitButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(revertButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(QDialogButtonBox::Close);

    connect(buttonBox, SIGNAL(rejected()),
            this, SLOT(reject()));


    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(m_tabWidget);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    m_ICAOlineEdit->setFocus();

    setWindowTitle(trUtf8("Данные аэродрома"));
}

void MapperDialog::setProxyModel(ProxyModel *proxyModel)
{
    m_mapper->setModel(proxyModel);
    m_mapper->addMapping(m_ICAOlineEdit,                  AD_indxICAO);
    m_mapper->addMapping(m_milICAOlineEdit,               AD_milIndx4ru);
    m_mapper->addMapping(m_IATAlineEdit,                  AD_indxIATA);
    m_mapper->addMapping(m_mil2letterCodeRuLineEdit,      AD_milIndx2ru);
    m_mapper->addMapping(m_cityLineEdit,                  AD_city);
    m_mapper->addMapping(m_cityRuLineEdit,                AD_cityRu);
    m_mapper->addMapping(m_ADlineEdit,                    AD_AD);
    m_mapper->addMapping(m_ADruLineEdit,                  AD_ADru);
    m_mapper->addMapping(m_milCSruLineEdit,               AD_milCSru);
    m_mapper->addMapping(m_milFRQlineEdit,                AD_milFRQ);
    m_mapper->addMapping(m_LATlineEdit,                   AD_LAT);
    m_mapper->addMapping(m_LONlineEdit,                   AD_LON);
    m_mapper->addMapping(m_VARlineEdit,                   AD_VAR);
    m_mapper->addMapping(m_ELEVlineEdit,                  AD_ELEV);
    m_mapper->addMapping(m_timeZoneLineEdit,              AD_TZ);
    m_mapper->addMapping(m_milBorderLineEdit,             AD_milBorder);
    m_mapper->addMapping(m_milBorderFLsLineEdit,          AD_milBorderFLs);
    m_mapper->addMapping(m_milEnterExitPointRuLineEdit,   AD_milEnterExitPointRu);
    m_mapper->addMapping(m_milTerkasInfoReceiverLineEdit, AD_milTerkasInfoReceiver);
    m_mapper->addMapping(m_noteLineEdit,                  AD_note);
    m_mapper->addMapping(m_noteRuLineEdit,                AD_noteRu);

    m_mapper->toFirst();
}

void MapperDialog::setCurrentIndex(const QModelIndex &index)
{
    m_mapper->setCurrentModelIndex(index);
}

QWidget* MapperDialog::generalPage()
{
    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(trUtf8("Индекс ИКАО"),          m_ICAOlineEdit);
    formLayout->addRow(trUtf8("Индекс ИАТА"),          m_IATAlineEdit);
    formLayout->addRow(trUtf8("Город"),                m_cityLineEdit);
    formLayout->addRow(trUtf8("Город"),                m_cityRuLineEdit);
    formLayout->addRow(trUtf8("Аэродром"),             m_ADlineEdit);
    formLayout->addRow(trUtf8("Аэродром"),             m_ADruLineEdit);
    formLayout->addRow(trUtf8("Широта"),               m_LATlineEdit);
    formLayout->addRow(trUtf8("Долгота"),              m_LONlineEdit);
    formLayout->addRow(trUtf8("Магнитное склонение"),  m_VARlineEdit);
    formLayout->addRow(trUtf8("Превышение аэродрома"), m_ELEVlineEdit);
    formLayout->addRow(trUtf8("Часовой пояс"),         m_timeZoneLineEdit);
    formLayout->addRow(trUtf8("Примечание"),           m_noteLineEdit);
    formLayout->addRow(trUtf8("Примечание"),           m_noteRuLineEdit);

    QWidget *page = new QWidget;
    page->setLayout(formLayout);
    return page;
}

QWidget* MapperDialog::militaryPage()
{
    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(trUtf8("Государственный Индекс"),               m_milICAOlineEdit);
    formLayout->addRow(trUtf8("Государственный 2-х буквенный Индекс"), m_mil2letterCodeRuLineEdit);
    formLayout->addRow(trUtf8("Государственный позывной"),             m_milCSruLineEdit);
    formLayout->addRow(trUtf8("Государственная частота"),              m_milFRQlineEdit);
    formLayout->addRow(trUtf8("Государственная граница аэродрома"),    m_milBorderLineEdit);
    formLayout->addRow(trUtf8("Эшелоны"),                              m_milBorderFLsLineEdit);
    formLayout->addRow(trUtf8("Точки входа/выхода"),                   m_milEnterExitPointRuLineEdit);
    formLayout->addRow(trUtf8("Сектор поступления информации"),        m_milTerkasInfoReceiverLineEdit);

    QWidget *page = new QWidget;
    page->setLayout(formLayout);
    return page;
}

void MapperDialog::submit()
{
    m_mapper->submit();
}
