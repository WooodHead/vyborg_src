#ifndef MAPPERDIALOG_H
#define MAPPERDIALOG_H

#include <vyborg.h>

class MapperDialog : public VyborgMapperDialog
{
    Q_OBJECT

public:
    MapperDialog(QSqlRelationalTableModel *model, QWidget *parent = 0);
    ~MapperDialog();

protected:
    virtual void createPrivateWidgets();
    virtual void layoutPrivateWidgets();
    virtual void updatePrivateWidgets();
};

#endif // MAPPERDIALOG_H
