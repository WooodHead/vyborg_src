#include <QtWidgets>

#include "mapperdialog.h"
#include "declarations.h"

MapperDialog::MapperDialog(QSqlRelationalTableModel *model, QWidget *parent)
    : VyborgMapperDialog(model, parent)
{
    createPrivateWidgets();
    layoutPrivateWidgets();
    updatePrivateWidgets();
}

void MapperDialog::createPrivateWidgets()
{
    m_personpidLineEdit = new QLineEdit;
    m_activityLineEdit = new QLineEdit;
    m_sectorpidLineEdit = new QLineEdit;

    m_startDateEdit = new QDateEdit;
    m_stopDateEdit = new QDateEdit;

    m_startDateEdit->setDisplayFormat("yyyy MMMM dd");
    m_stopDateEdit->setDisplayFormat("yyyy MMMM dd");


    QDataWidgetMapper* m_mapper = mapper();
    m_mapper->addMapping(m_personpidLineEdit,  shedule_personpid);
    m_mapper->addMapping(m_activityLineEdit,   shedule_activity);
    m_mapper->addMapping(m_sectorpidLineEdit,  shedule_sector_pid);
    m_mapper->addMapping(m_startDateEdit,      shedule_start);
    m_mapper->addMapping(m_stopDateEdit,       shedule_stop);
}

void MapperDialog::layoutPrivateWidgets()
{
    QHBoxLayout *layout2 = new QHBoxLayout;
    layout2->addWidget(m_startDateEdit);
    layout2->addWidget(new QLabel(trUtf8("Дата окончания:")));
    layout2->addWidget(m_stopDateEdit);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("Табельный номер:", m_personpidLineEdit);
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
        m_personpidLineEdit->setReadOnly(false);
        m_activityLineEdit->setReadOnly(false);
        m_sectorpidLineEdit->setReadOnly(false);
        m_startDateEdit->setReadOnly(false);
        m_stopDateEdit->setReadOnly(false);
    }
    else
    {
        m_personpidLineEdit->setReadOnly(true);
        m_activityLineEdit->setReadOnly(true);
        m_sectorpidLineEdit->setReadOnly(true);
        m_startDateEdit->setReadOnly(true);
        m_stopDateEdit->setReadOnly(true);
    }
}
