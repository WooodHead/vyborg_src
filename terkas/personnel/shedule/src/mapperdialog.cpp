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
//    m_dateEdit            = new QDateEdit;
//    m_dateEdit->setDisplayFormat("yyyy MMMM dd");

    m_fullnameComboBox = new QComboBox;
//    m_middlenameLineEdit = new QLineEdit;
//    m_surnameLineEdit = new QLineEdit;
    m_innernumLineEdit = new QLineEdit;
    m_shiftnumLineEdit = new QLineEdit;
    m_activityLineEdit = new QLineEdit;
    m_sectorpidLineEdit = new QLineEdit;

    m_startDateEdit = new QDateEdit;
    m_stopDateEdit = new QDateEdit;

    m_startDateEdit->setDisplayFormat("yyyy MMMM dd");
    m_stopDateEdit->setDisplayFormat("yyyy MMMM dd");


    QDataWidgetMapper* m_mapper = mapper();
    m_mapper->addMapping(m_fullnameComboBox,       shedule_fullname);
//    m_mapper->addMapping(m_middlenameLineEdit, shedule_middlename);
//    m_mapper->addMapping(m_surnameLineEdit,    shedule_surname);
    m_mapper->addMapping(m_innernumLineEdit,   shedule_innernum);
    m_mapper->addMapping(m_shiftnumLineEdit,   shedule_shiftnum);
    m_mapper->addMapping(m_activityLineEdit,   shedule_activity);
    m_mapper->addMapping(m_sectorpidLineEdit,  shedule_sector_pid);
    m_mapper->addMapping(m_startDateEdit,      shedule_start);
    m_mapper->addMapping(m_stopDateEdit,       shedule_stop);
    m_mapper->setItemDelegate(new MapperDelegate);
}

void MapperDialog::layoutPrivateWidgets()
{
    QHBoxLayout *layout1 = new QHBoxLayout;
    layout1->addWidget(m_innernumLineEdit);
    layout1->addWidget(new QLabel("Номер смены:"));
    layout1->addWidget(m_shiftnumLineEdit);

    QHBoxLayout *layout2 = new QHBoxLayout;
    layout2->addWidget(m_startDateEdit);
    layout2->addWidget(new QLabel(trUtf8("Дата окончания:")));
    layout2->addWidget(m_stopDateEdit);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("Имя:", m_fullnameComboBox);
    formLayout->addRow("Табельный номер:", layout1);
    formLayout->addRow("Вид деятельности:", m_activityLineEdit);
    formLayout->addRow("Сектор:", m_sectorpidLineEdit);
    formLayout->addRow(trUtf8("Дата начала:"), layout2);

    QVBoxLayout *privateWidgetsLayout = layout();
    privateWidgetsLayout->addLayout(formLayout);
}

void MapperDialog::updatePrivateWidgets()
{
    if (isDirty())
    {
//        m_fullnameLineEdit->setReadOnly(false);
        m_innernumLineEdit->setReadOnly(false);
        m_shiftnumLineEdit->setReadOnly(false);
        m_activityLineEdit->setReadOnly(false);
        m_sectorpidLineEdit->setReadOnly(false);
        m_startDateEdit->setReadOnly(false);
        m_stopDateEdit->setReadOnly(false);
    }
    else
    {
//        m_fullnameLineEdit->setReadOnly(true);
        m_innernumLineEdit->setReadOnly(true);
        m_shiftnumLineEdit->setReadOnly(true);
        m_activityLineEdit->setReadOnly(true);
        m_sectorpidLineEdit->setReadOnly(true);
        m_startDateEdit->setReadOnly(true);
        m_stopDateEdit->setReadOnly(true);
    }
}
