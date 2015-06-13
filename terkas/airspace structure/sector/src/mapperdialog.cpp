#include <QtWidgets>

#include "mapperdialog.h"

MapperDialog::MapperDialog(QSqlRelationalTableModel *model, QWidget *parent)
    : VyborgMapperDialog(model, parent)
{
    createPrivateWidgets();
    layoutPrivateWidgets();
    updatePrivateWidgets();
}

void MapperDialog::createPrivateWidgets()
{
    m_leSector = new QLineEdit;
    m_leLabel = new QLineEdit;

    mapper_->addMapping(m_leSector, 1);
    mapper_->addMapping(m_leLabel, 2);
}

void MapperDialog::layoutPrivateWidgets()
{
    privateWidgetsLayout->addWidget(m_leSector);
    privateWidgetsLayout->addWidget(m_leLabel);
}

void MapperDialog::updatePrivateWidgets()
{

}
