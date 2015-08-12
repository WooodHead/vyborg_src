#include <QtWidgets>

#include "mapperdialog.h"
#include "declarations.h"
#include "mapperdelegate.h"


MapperDialog::MapperDialog(QSqlRelationalTableModel *model, QWidget *parent)
    : VyborgMapperDialog(model, parent)
{
    createPrivateWidgets();
    layoutPrivateWidgets();
    updatePrivateWidgets();
}

void MapperDialog::createPrivateWidgets()
{
//    innerFlightsEdit    = new QLineEdit;
//    innerFlightsEdit->setValidator(new QIntValidator(0, 100000, this));

    m_abbrComboBox = new QComboBox;

    m_functionLineEdit = new QLineEdit;
    m_valLineEdit      = new QLineEdit;
    m_valmaxLineEdit   = new QLineEdit;

    QDataWidgetMapper* m_mapper = mapper();
    m_mapper->addMapping(m_abbrComboBox,     quota_abbr);
    m_mapper->addMapping(m_functionLineEdit, quota_function);
    m_mapper->addMapping(m_valLineEdit,      quota_val);
    m_mapper->addMapping(m_valmaxLineEdit,   quota_valmax);
    m_mapper->setItemDelegate(new MapperDelegate);
}

void MapperDialog::layoutPrivateWidgets()
{
    QLabel *abbrLabel = new QLabel(trUtf8("Сектор УВД:"));
    abbrLabel->setBuddy(m_abbrComboBox);

    QLabel *functionLabel = new QLabel(trUtf8("Выполняемые функции:"));
    functionLabel->setBuddy(m_functionLineEdit);

    QLabel *valLabel = new QLabel(trUtf8("Допустимое значение:"));
    valLabel->setBuddy(m_valLineEdit);

    QLabel *valmaxLabel = new QLabel(trUtf8("Предельно-допустимое значение:"));
    valmaxLabel->setBuddy(m_valmaxLineEdit);

//    QGridLayout *gridLayout = new QGridLayout;
//    gridLayout->addWidget(Label,            0, 0, 1, 1);    gridLayout->addWidget(dateEdit,            0, 1, 1, 1);
    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(trUtf8("Сектор УВД:"), m_abbrComboBox);
    formLayout->addRow(trUtf8("Выполняемые функции:"), m_functionLineEdit);
    formLayout->addRow(trUtf8("Допустимое значение:"), m_valLineEdit);
    formLayout->addRow(trUtf8("Предельно-допустимое значение:"), m_valmaxLineEdit);

    QVBoxLayout *privateWidgetsLayout = layout();
    privateWidgetsLayout->addLayout(formLayout);
}

void MapperDialog::updatePrivateWidgets()
{
    if (isDirty()) {
        m_abbrComboBox->setEditable(true);
        m_functionLineEdit->setReadOnly(false);
        m_valLineEdit->setReadOnly(false);
        m_valmaxLineEdit->setReadOnly(false);

        m_abbrComboBox->setFocus();
    } else {
        m_abbrComboBox->setEditable(false);
        m_functionLineEdit->setReadOnly(true);
        m_valLineEdit->setReadOnly(true);
        m_valmaxLineEdit->setReadOnly(true);
    }
}
