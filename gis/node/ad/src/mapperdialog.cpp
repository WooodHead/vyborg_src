#include <QtWidgets>
#include <QtSql>

#include "mapperdialog.h"
#include "declarations.h"

#include "rwwidget.h"
#include "geogwidget.h"

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
    m_cityruLE = new QLineEdit;
    m_nameruLE = new QLineEdit;
    m_nameLE = new QLineEdit;
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
    m_geogLE = new QLineEdit;

    m_geogWid = new GeogWidget;
    m_rwWid = new RWWidget;

    QDataWidgetMapper* m_mapper = mapper();
    m_mapper->addMapping(m_geogWid, ad_geog);
    m_mapper->addMapping(m_rwWid, ad_pid);
    m_mapper->addMapping(m_validLE, ad_valid);
    m_mapper->addMapping(m_countryindxLE, ad_countryindx);
    m_mapper->addMapping(m_countryLE, ad_country);
    m_mapper->addMapping(m_cityruLE, ad_cityru);
    m_mapper->addMapping(m_nameruLE, ad_nameru);
    m_mapper->addMapping(m_nameLE, ad_name);
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
    m_mapper->addMapping(m_geogLE, ad_geog);
}

void MapperDialog::layoutPrivateWidgets()
{
    // Основные данные
    QFormLayout *formLayout1 = new QFormLayout;
    formLayout1->addRow(trUtf8("Действующий/Недействующий"), m_validLE);
    formLayout1->addRow(trUtf8("Индекс страны"), m_countryindxLE);
    formLayout1->addRow(trUtf8("Страна"), m_countryLE);
    formLayout1->addRow(trUtf8("Город"), m_cityruLE);
    formLayout1->addRow(trUtf8("Аэропорт"), m_nameruLE);
    formLayout1->addRow(trUtf8("Aerodrome (EN)"), m_nameLE);
    formLayout1->addRow(trUtf8("Индекс"), m_indxLE);
    formLayout1->addRow(trUtf8("Индекс Рус"), m_indxruLE);
    formLayout1->addRow(trUtf8("Тип аэродрома"), m_typeLE);
    formLayout1->addRow(trUtf8("Международный"), m_intlLE);
    formLayout1->addRow(trUtf8("Организация"), m_staffLE);
    formLayout1->addRow(trUtf8("Регламент работы"), m_reglamentLE);
    formLayout1->addRow(trUtf8("Превышение"), m_elevationLE);
    formLayout1->addRow(trUtf8("Магн склонение"), m_magnLE);
    formLayout1->addRow(trUtf8("Координаты"), m_geogLE);

    QVBoxLayout *vbLayout1 = new QVBoxLayout;
    vbLayout1->addLayout(formLayout1);
    vbLayout1->addWidget(m_geogWid);

    QWidget *page1 = new QWidget;
    page1->setLayout(vbLayout1);


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
    QVBoxLayout *vbLayout4 = new QVBoxLayout;
    vbLayout4->addWidget(m_rwWid);

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
        m_cityruLE->setReadOnly(false);
        m_nameruLE->setReadOnly(false);
        m_nameLE->setReadOnly(false);
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
        m_geogLE->setReadOnly(false);
    }
    else
    {
        m_validLE->setReadOnly(true);
        m_countryindxLE->setReadOnly(true);
        m_countryLE->setReadOnly(true);
        m_cityruLE->setReadOnly(true);
        m_nameruLE->setReadOnly(true);
        m_nameLE->setReadOnly(true);
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
        m_geogLE->setReadOnly(true);
    }
}
