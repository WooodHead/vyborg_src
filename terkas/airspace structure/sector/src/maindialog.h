#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <vyborg.h>

class MainDialog : public VyborgMainDialog
{
    Q_OBJECT

public:
    MainDialog(QWidget *parent = 0);

protected:
    virtual void setupModel();
    virtual void setupView();
    virtual void setupMapperDialog();
    virtual void setupSortDialog();
    virtual void setupFilterDialog();
};

#endif // MAINDIALOG_H
