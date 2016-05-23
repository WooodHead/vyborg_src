#include <QtWidgets>
#include <QtSql>

#include <vyborg.h>

#include "mapperdialog.h"
#include "declarations.h"
#include "mapperdelegate.h"

MapperDialog::MapperDialog(QSqlTableModel *model, QWidget *parent)
    : VyborgMapperDialog(model, parent)
{
    createPrivateWidgets();
    layoutPrivateWidgets();
    updatePrivateWidgets();
}

void MapperDialog::createPrivateWidgets()
{
    m_countryLE   = new QLineEdit;
    m_cityruLE    = new QLineEdit;
    m_nameruLE    = new QLineEdit;
    m_nameLE      = new QLineEdit;
    m_indxLE      = new QLineEdit;
    m_reglamentLE = new QLineEdit;
    m_emailLE     = new QLineEdit;
    m_webLE       = new QLineEdit;

    m_elevationSB = new QSpinBox;
    m_elevationSB->setRange(-301, 4500);
    m_elevationSB->setSingleStep(1);
    m_elevationSB->setSpecialValueText(" ");

    m_magvarDSB = new QDoubleSpinBox;
    m_magvarDSB->setRange(-51.0, 50.0);
    m_magvarDSB->setSingleStep(1.0);
    m_magvarDSB->setSpecialValueText(" ");

    m_validCB = new QComboBox;
    m_typeCB  = new QComboBox;
    m_intlCB  = new QComboBox;
    m_staffCB = new QComboBox;

    m_notePTE = new QPlainTextEdit;

    m_nodeWid = new NodeWidget;

    m_rwWid = new RWWidget;

    QDataWidgetMapper* m_mapper = mapper();
    m_mapper->addMapping(m_nodeWid,     ad_geog);
    m_mapper->addMapping(m_rwWid,       ad_pid);
    m_mapper->addMapping(m_validCB,     ad_opr);
    m_mapper->addMapping(m_countryLE,   ad_country_pid);
    m_mapper->addMapping(m_cityruLE,    ad_cityru);
    m_mapper->addMapping(m_nameruLE,    ad_nameru);
    m_mapper->addMapping(m_nameLE,      ad_name);
    m_mapper->addMapping(m_indxLE,      ad_indx);
    m_mapper->addMapping(m_typeCB,      ad_type);
    m_mapper->addMapping(m_intlCB,      ad_intl);
    m_mapper->addMapping(m_staffCB,     ad_staff);
    m_mapper->addMapping(m_reglamentLE, ad_reglament);
    m_mapper->addMapping(m_elevationSB, ad_elevation);
    m_mapper->addMapping(m_magvarDSB,   ad_magvar);
    m_mapper->addMapping(m_emailLE,     ad_email);
    m_mapper->addMapping(m_webLE,       ad_web);
    m_mapper->addMapping(m_notePTE,     ad_note);

    m_mapper->setItemDelegate(new MapperDelegate);
}

void MapperDialog::layoutPrivateWidgets()
{
    // Основные данные

    QHBoxLayout *hlayout1 = new QHBoxLayout;
    hlayout1->addWidget(new QLabel(trUtf8("Тип")));
    hlayout1->addWidget(m_typeCB);
    hlayout1->addWidget(new QLabel(trUtf8("состояние")));
    hlayout1->addWidget(m_validCB);
    hlayout1->addWidget(new QLabel(trUtf8("Международный")));
    hlayout1->addWidget(m_intlCB);

    QHBoxLayout *hlayout2 = new QHBoxLayout;
    hlayout2->addWidget(new QLabel(trUtf8("Аэродром")));
    hlayout2->addWidget(m_nameruLE);
    hlayout2->addWidget(new QLabel(trUtf8("Aerodrome")));
    hlayout2->addWidget(m_nameLE);


    // (Page 1)

    QFormLayout *formLayout1 = new QFormLayout;
    formLayout1->addRow(trUtf8("Страна"),           m_countryLE);
    formLayout1->addRow(trUtf8("Город"),            m_cityruLE);
    formLayout1->addRow(trUtf8("Индекс"),           m_indxLE);
    formLayout1->addRow(trUtf8("Организация"),      m_staffCB);
    formLayout1->addRow(trUtf8("Регламент работы"), m_reglamentLE);
    formLayout1->addRow(trUtf8("Превышение"),       m_elevationSB);
    formLayout1->addRow(trUtf8("Магн склонение"),   m_magvarDSB);

    QVBoxLayout *vbLayout1 = new QVBoxLayout;
    vbLayout1->addLayout(formLayout1);
    vbLayout1->addWidget(m_nodeWid);

    QWidget *page1 = new QWidget;
//    page1->setLayout(formLayout1);
    page1->setLayout(vbLayout1);


    // Контакты
    QFormLayout *formLayout2 = new QFormLayout;
    formLayout2->addRow(trUtf8("E-mail"),   m_emailLE);
    formLayout2->addRow(trUtf8("Web-сайт"), m_webLE);

    QWidget *page2 = new QWidget;
    page2->setLayout(formLayout2);


    // Примечание
    QVBoxLayout *vbLayout3 = new QVBoxLayout;
    vbLayout3->addWidget(m_notePTE);

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
    mainLayout->addLayout(hlayout1);
    mainLayout->addLayout(hlayout2);
    mainLayout->addWidget(tabWidget);

    QVBoxLayout *privateWidgetsLayout = layout();
    privateWidgetsLayout->addLayout(mainLayout);
}

void MapperDialog::updatePrivateWidgets()
{
    if (state() == VyborgMapperDialog::Normal)
    {
        m_countryLE->setReadOnly(true);
        m_cityruLE->setReadOnly(true);
        m_nameruLE->setReadOnly(true);
        m_nameLE->setReadOnly(true);
        m_indxLE->setReadOnly(true);
        m_reglamentLE->setReadOnly(true);
        m_emailLE->setReadOnly(true);
        m_webLE->setReadOnly(true);

        m_elevationSB->setEnabled(false);

        m_magvarDSB->setEnabled(false);

        m_notePTE->setReadOnly(true);

        m_nodeWid->setEnabled(false);

        m_validCB->setEnabled(false);
        m_typeCB->setEnabled(false);
        m_intlCB->setEnabled(false);
        m_staffCB->setEnabled(false);
    }
    else
    {
        m_countryLE->setReadOnly(false);
        m_cityruLE->setReadOnly(false);
        m_nameruLE->setReadOnly(false);
        m_nameLE->setReadOnly(false);
        m_indxLE->setReadOnly(false);
        m_reglamentLE->setReadOnly(false);
        m_emailLE->setReadOnly(false);
        m_webLE->setReadOnly(false);

        m_elevationSB->setEnabled(true);

        m_magvarDSB->setEnabled(true);

        m_notePTE->setReadOnly(false);

        m_nodeWid->setEnabled(true);

        m_validCB->setEnabled(true);
        m_typeCB->setEnabled(true);
        m_intlCB->setEnabled(true);
        m_staffCB->setEnabled(true);
    }
}
