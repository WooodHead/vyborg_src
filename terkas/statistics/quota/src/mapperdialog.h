#ifndef MAPPERDIALOG_H
#define MAPPERDIALOG_H

#include <vyborg.h>

QT_BEGIN_NAMESPACE
class QComboBox;
class QLineEdit;
QT_END_NAMESPACE

class MapperDialog : public VyborgMapperDialog
{
    Q_OBJECT

public:
    MapperDialog(QSqlRelationalTableModel *model, QWidget *parent = 0);

protected:
    virtual void createPrivateWidgets() Q_DECL_OVERRIDE;
    virtual void layoutPrivateWidgets() Q_DECL_OVERRIDE;
    virtual void updatePrivateWidgets() Q_DECL_OVERRIDE;

private:
    QComboBox *m_abbrComboBox;
    QLineEdit *m_functionLineEdit;
    QLineEdit *m_valLineEdit;
    QLineEdit *m_valmaxLineEdit;
};

#endif // MAPPERDIALOG_H
