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
    virtual void createPrivateWidgets() Q_DECL_OVERRIDE;
    virtual void layoutPrivateWidgets() Q_DECL_OVERRIDE;
    virtual void updatePrivateWidgets() Q_DECL_OVERRIDE;

private:
    QLineEdit *m_yearLineEdit;
    QLineEdit *m_janLineEdit;
    QLineEdit *m_febLineEdit;
    QLineEdit *m_marLineEdit;
    QLineEdit *m_aprLineEdit;
    QLineEdit *m_mayLineEdit;
    QLineEdit *m_junLineEdit;
    QLineEdit *m_julLineEdit;
    QLineEdit *m_augLineEdit;
    QLineEdit *m_sepLineEdit;
    QLineEdit *m_octLineEdit;
    QLineEdit *m_novLineEdit;
    QLineEdit *m_decLineEdit;
};

#endif // MAPPERDIALOG_H
