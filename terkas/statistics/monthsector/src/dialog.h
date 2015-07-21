#ifndef DIALOG_H
#define DIALOG_H

#include <vyborg.h>

class Dialog : public VyborgMainDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);

protected:
    virtual void setupModel()        Q_DECL_OVERRIDE;
    virtual void setupView()         Q_DECL_OVERRIDE;
    virtual void setupMapperDialog() Q_DECL_OVERRIDE;
    virtual void setupFilterDialog() Q_DECL_OVERRIDE;
    virtual void setupSortDialog()   Q_DECL_OVERRIDE;
};

#endif // DIALOG_H
