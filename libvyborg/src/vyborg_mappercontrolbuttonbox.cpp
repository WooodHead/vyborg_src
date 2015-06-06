#include <QtWidgets>

#include "vyborg_mappercontrolbuttonbox.h"


VyborgMapperControlButtonBox::VyborgMapperControlButtonBox(QWidget *parent)
    : QDialogButtonBox(parent),
      dirty_(false)
{
    editButton   = new QPushButton(trUtf8("Edit"));
    submitButton = new QPushButton(trUtf8("Submit"));
    revertButton = new QPushButton(trUtf8("Revert"));
    closeButton  = new QPushButton(trUtf8("Close"));


    addButton(editButton,   QDialogButtonBox::ActionRole);
    addButton(submitButton, QDialogButtonBox::ActionRole);
    addButton(revertButton, QDialogButtonBox::ActionRole);
    addButton(closeButton,  QDialogButtonBox::ActionRole);


    connect(editButton, SIGNAL(clicked()),
            this, SLOT(on_editButtonClicked()));
    connect(submitButton, SIGNAL(clicked()),
            this, SLOT(on_submitButtonClicked()));
    connect(revertButton, SIGNAL(clicked()),
            this, SLOT(on_revertButtonClicked()));
    connect(closeButton, SIGNAL(clicked()),
            this, SLOT(on_closeButtonClicked()));


    setDirty(dirty_);
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
    dirty_ = dirty;

    if (dirty_) {
        editButton->setEnabled(false);
        submitButton->setEnabled(true);
        revertButton->setEnabled(true);
        closeButton->setEnabled(true);
    } else {
        editButton->setEnabled(true);
        submitButton->setEnabled(false);
        revertButton->setEnabled(false);
        closeButton->setEnabled(true);
    }
}
