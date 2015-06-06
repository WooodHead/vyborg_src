#ifndef PERSONPOPUPMENU_H
#define PERSONPOPUPMENU_H

#include <QMenu>


class PersonPopupMenu : public QMenu
{
    Q_OBJECT

public:
    explicit PersonPopupMenu(QWidget *parent = 0);

    void setPersonId(const int personId);
    int personId() const;

private slots:
    void addVacation();

private:
    QAction *addVacationAction;

    int m_personId;
};

#endif // PERSONPOPUPMENU_H
