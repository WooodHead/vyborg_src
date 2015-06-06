#include "personpopupmenu.h"
#include "addvacancydialog.h"


PersonPopupMenu::PersonPopupMenu(QWidget *parent)
    : QMenu(parent)
{
    addVacationAction = new QAction(trUtf8("Добавить отпуск"), this);
    connect(addVacationAction, SIGNAL(triggered()),
            this, SLOT(addVacation()));
    addAction(addVacationAction);
}

void PersonPopupMenu::addVacation()
{
    AddVacancyDialog *dialog = new AddVacancyDialog(this);
    dialog->setPersonId(m_personId);
    dialog->show();
}

void PersonPopupMenu::setPersonId(const int personId)
{
    if (personId != m_personId) {
        m_personId = personId;
    }
}

int PersonPopupMenu::personId() const
{
    return m_personId;
}
