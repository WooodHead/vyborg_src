#ifndef MAPPERDIALOG_H
#define MAPPERDIALOG_H

#include <vyborg/vyborg.h>

QT_BEGIN_NAMESPACE
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
    QLineEdit *m_labelLineEdit;
    QLineEdit *m_fullnameLineEdit;
    QLineEdit *m_sectorLineEdit;
    QLineEdit *m_compoundLineEdit;
};

#endif // MAPPERDIALOG_H
