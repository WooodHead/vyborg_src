#ifndef MAPPERDIALOG_H
#define MAPPERDIALOG_H

#include <vyborg.h>

QT_BEGIN_NAMESPACE
class QSpinBox;
QT_END_NAMESPACE

class MapperDialog : public VyborgMapperDialog
{
    Q_OBJECT

public:
    MapperDialog(QSqlTableModel *model, QWidget *parent = 0);

protected:
    virtual void createPrivateWidgets() Q_DECL_OVERRIDE;
    virtual void layoutPrivateWidgets() Q_DECL_OVERRIDE;
    virtual void updatePrivateWidgets() Q_DECL_OVERRIDE;

private:
    QSpinBox *m_yearSpinBox;
    QSpinBox *m_janSpinBox;
    QSpinBox *m_febSpinBox;
    QSpinBox *m_marSpinBox;
    QSpinBox *m_aprSpinBox;
    QSpinBox *m_maySpinBox;
    QSpinBox *m_junSpinBox;
    QSpinBox *m_julSpinBox;
    QSpinBox *m_augSpinBox;
    QSpinBox *m_sepSpinBox;
    QSpinBox *m_octSpinBox;
    QSpinBox *m_novSpinBox;
    QSpinBox *m_decSpinBox;
};

#endif // MAPPERDIALOG_H
