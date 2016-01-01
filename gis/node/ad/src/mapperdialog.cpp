#include <QtWidgets>
#include <QtSql>

#include "mapperdialog.h"
#include "declarations.h"
#include "rwwidget.h"


MapperDialog::MapperDialog(QSqlTableModel *model, QWidget *parent)
    : VyborgMapperDialog(model, parent)
{
    createPrivateWidgets();
    layoutPrivateWidgets();
    updatePrivateWidgets();
}

void MapperDialog::createPrivateWidgets()
{
    m_validLE = new QLineEdit;
    m_countryindxLE = new QLineEdit;
    m_countryLE = new QLineEdit;
    m_cityLE = new QLineEdit;
    m_nameLE = new QLineEdit;
    m_nameengLE = new QLineEdit;
    m_indxLE = new QLineEdit;
    m_indxruLE = new QLineEdit;
    m_typeLE = new QLineEdit;
    m_intlLE = new QLineEdit;
    m_staffLE = new QLineEdit;
    m_reglamentLE = new QLineEdit;
    m_elevationLE = new QLineEdit;
    m_magnLE = new QLineEdit;
    m_emailLE = new QLineEdit;
    m_webLE = new QLineEdit;
    m_noteTE = new QTextEdit;
    m_coordLE = new QLineEdit;


    QDataWidgetMapper* m_mapper = mapper();
    m_mapper->addMapping(m_validLE, ad_valid);
    m_mapper->addMapping(m_countryindxLE, ad_countryindx);
    m_mapper->addMapping(m_countryLE, ad_country);
    m_mapper->addMapping(m_cityLE, ad_city);
    m_mapper->addMapping(m_nameLE, ad_name);
    m_mapper->addMapping(m_nameengLE, ad_nameeng);
    m_mapper->addMapping(m_indxLE, ad_indx);
    m_mapper->addMapping(m_indxruLE, ad_indxru);
    m_mapper->addMapping(m_typeLE, ad_type);
    m_mapper->addMapping(m_intlLE, ad_intl);
    m_mapper->addMapping(m_staffLE, ad_staff);
    m_mapper->addMapping(m_reglamentLE, ad_reglament);
    m_mapper->addMapping(m_elevationLE, ad_elevation);
    m_mapper->addMapping(m_magnLE, ad_magn);
    m_mapper->addMapping(m_emailLE, ad_email);
    m_mapper->addMapping(m_webLE, ad_web);
    m_mapper->addMapping(m_noteTE, ad_note);
    m_mapper->addMapping(m_coordLE, ad_coord);

    connect(m_mapper, SIGNAL(currentIndexChanged(int)),
            this, SLOT(changeIndx(int)));

//    m_mapper->setItemDelegate(new MapperDelegate);
}

void MapperDialog::layoutPrivateWidgets()
{
    // Основные данные
    QFormLayout *formLayout1 = new QFormLayout;
    formLayout1->addRow(trUtf8("Действующий/Недействующий"), m_validLE);
    formLayout1->addRow(trUtf8("Индекс страны"), m_countryindxLE);
    formLayout1->addRow(trUtf8("Страна"), m_countryLE);
    formLayout1->addRow(trUtf8("Город"), m_cityLE);
    formLayout1->addRow(trUtf8("Аэропорт"), m_nameLE);
    formLayout1->addRow(trUtf8("Aerodrome (EN)"), m_nameengLE);
    formLayout1->addRow(trUtf8("Индекс"), m_indxLE);
    formLayout1->addRow(trUtf8("Индекс Рус"), m_indxruLE);
    formLayout1->addRow(trUtf8("Тип аэродрома"), m_typeLE);
    formLayout1->addRow(trUtf8("Международный"), m_intlLE);
    formLayout1->addRow(trUtf8("Организация"), m_staffLE);
    formLayout1->addRow(trUtf8("Регламент работы"), m_reglamentLE);
    formLayout1->addRow(trUtf8("Превышение"), m_elevationLE);
    formLayout1->addRow(trUtf8("Магн склонение"), m_magnLE);
    formLayout1->addRow(trUtf8("Координаты"), m_coordLE);

    QWidget *page1 = new QWidget;
    page1->setLayout(formLayout1);


    // Контакты
    QFormLayout *formLayout2 = new QFormLayout;
    formLayout2->addRow(trUtf8("E-mail"), m_emailLE);
    formLayout2->addRow(trUtf8("Web-сайт"), m_webLE);

    QWidget *page2 = new QWidget;
    page2->setLayout(formLayout2);


    // Примечание
    QVBoxLayout *vbLayout3 = new QVBoxLayout;
    vbLayout3->addWidget(m_noteTE);

    QWidget *page3 = new QWidget;
    page3->setLayout(vbLayout3);


    // Данные ВПП
    rwwid = new RWWidget();

    QVBoxLayout *vbLayout4 = new QVBoxLayout;
    vbLayout4->addWidget(rwwid);

    QWidget *page4 = new QWidget;
    page4->setLayout(vbLayout4);



    QTabWidget *tabWidget = new QTabWidget;
    tabWidget->addTab(page1, trUtf8("Основные данные"));
    tabWidget->addTab(page4, trUtf8("Данные ВПП"));
    tabWidget->addTab(page3, trUtf8("Примечание"));
    tabWidget->addTab(page2, trUtf8("Контакты"));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);

    QVBoxLayout *privateWidgetsLayout = layout();
    privateWidgetsLayout->addLayout(mainLayout);
}

void MapperDialog::updatePrivateWidgets()
{
    if (isDirty())
    {
        m_validLE->setReadOnly(false);
        m_countryindxLE->setReadOnly(false);
        m_countryLE->setReadOnly(false);
        m_cityLE->setReadOnly(false);
        m_nameLE->setReadOnly(false);
        m_nameengLE->setReadOnly(false);
        m_indxLE->setReadOnly(false);
        m_indxruLE->setReadOnly(false);
        m_typeLE->setReadOnly(false);
        m_intlLE->setReadOnly(false);
        m_staffLE->setReadOnly(false);
        m_reglamentLE->setReadOnly(false);
        m_elevationLE->setReadOnly(false);
        m_magnLE->setReadOnly(false);
        m_emailLE->setReadOnly(false);
        m_webLE->setReadOnly(false);
        m_noteTE->setReadOnly(false);
        m_coordLE->setReadOnly(false);
    }
    else
    {
        m_validLE->setReadOnly(true);
        m_countryindxLE->setReadOnly(true);
        m_countryLE->setReadOnly(true);
        m_cityLE->setReadOnly(true);
        m_nameLE->setReadOnly(true);
        m_nameengLE->setReadOnly(true);
        m_indxLE->setReadOnly(true);
        m_indxruLE->setReadOnly(true);
        m_typeLE->setReadOnly(true);
        m_intlLE->setReadOnly(true);
        m_staffLE->setReadOnly(true);
        m_reglamentLE->setReadOnly(true);
        m_elevationLE->setReadOnly(true);
        m_magnLE->setReadOnly(true);
        m_emailLE->setReadOnly(true);
        m_webLE->setReadOnly(true);
        m_noteTE->setReadOnly(true);
        m_coordLE->setReadOnly(true);
    }
}

void MapperDialog::changeIndx(int indx)
{
    rwwid->setADId(indx);
}
