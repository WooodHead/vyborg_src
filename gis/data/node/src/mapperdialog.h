#ifndef MAPPERDIALOG_H
#define MAPPERDIALOG_H

#include <vyborg.h>

QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE

class MapperDialog : public VyborgMapperDialog
{
    Q_OBJECT

public:
    MapperDialog(QSqlTableModel *model, QWidget *parent = 0);

protected:
    virtual void createPrivateWidgets();
    virtual void layoutPrivateWidgets();
    virtual void updatePrivateWidgets();

private:
    // Visual elements
    QLineEdit *m_latLE;
    QLineEdit *m_lonLE;
};

#endif // MAPPERDIALOG_H
