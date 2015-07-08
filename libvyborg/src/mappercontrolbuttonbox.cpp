#include <QtWidgets>

#include "mappercontrolbuttonbox.h"

VyborgMapperControlButtonBox::VyborgMapperControlButtonBox(QWidget *parent)
    : QDialogButtonBox(parent),
      m_dirty(false)
{
    m_addButton    = new QPushButton(trUtf8("Add"));
    m_removeButton = new QPushButton(trUtf8("Remove"));
    m_editButton   = new QPushButton(trUtf8("Edit"));
    m_submitButton = new QPushButton(trUtf8("Submit"));
    m_revertButton = new QPushButton(trUtf8("Revert"));
    m_closeButton  = new QPushButton(trUtf8("Close"));

    addButton(m_addButton,    QDialogButtonBox::ActionRole);
    addButton(m_removeButton, QDialogButtonBox::ActionRole);
    addButton(m_editButton,   QDialogButtonBox::ActionRole);
    addButton(m_submitButton, QDialogButtonBox::ActionRole);
    addButton(m_revertButton, QDialogButtonBox::ActionRole);
    addButton(m_closeButton,  QDialogButtonBox::ActionRole);

    connect(m_addButton, SIGNAL(clicked(bool)),
            this, SLOT(on_addButtonClicked()));
    connect(m_removeButton, SIGNAL(clicked(bool)),
            this, SLOT(on_removeButtonClicked()));
    connect(m_editButton, SIGNAL(clicked()),
            this, SLOT(on_editButtonClicked()));
    connect(m_submitButton, SIGNAL(clicked()),
            this, SLOT(on_submitButtonClicked()));
    connect(m_revertButton, SIGNAL(clicked()),
            this, SLOT(on_revertButtonClicked()));
    connect(m_closeButton, SIGNAL(clicked()),
            this, SLOT(on_closeButtonClicked()));

    setDirty(m_dirty);
}

void VyborgMapperControlButtonBox::on_addButtonClicked()
{
    setDirty(true);
    emit add();
}

void VyborgMapperControlButtonBox::on_removeButtonClicked()
{
    setDirty(true);
    emit remove();
}

void VyborgMapperControlButtonBox::on_editButtonClicked()
{
    setDirty(true);
    emit edit();
}

void VyborgMapperControlButtonBox::on_submitButtonClicked()
{
    setDirty(false);
    emit submit();
}

void VyborgMapperControlButtonBox::on_revertButtonClicked()
{
    setDirty(false);
    emit revert();
}

void VyborgMapperControlButtonBox::on_closeButtonClicked()
{
    emit close();
}

void VyborgMapperControlButtonBox::setDirty(bool dirty)
{
    m_dirty = dirty;

    if (m_dirty) {
        m_addButton->setEnabled(false);
        m_removeButton->setEnabled(false);
        m_editButton->setEnabled(false);
        m_submitButton->setEnabled(true);
        m_revertButton->setEnabled(true);
        m_closeButton->setEnabled(true);
    } else {
        m_addButton->setEnabled(true);
        m_removeButton->setEnabled(true);
        m_editButton->setEnabled(true);
        m_submitButton->setEnabled(false);
        m_revertButton->setEnabled(false);
        m_closeButton->setEnabled(true);
    }
}
