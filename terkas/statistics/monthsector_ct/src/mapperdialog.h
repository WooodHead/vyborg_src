#ifndef MAPPERDIALOG_H
#define MAPPERDIALOG_H

#include <vyborg.h>

QT_BEGIN_NAMESPACE
class QDateEdit;
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
    QDateEdit *m_dateEdit;
    QLineEdit *m_a5edit;
    QLineEdit *m_a6edit;
    QLineEdit *m_v1edit;
    QLineEdit *m_v2edit;
    QLineEdit *m_v3edit;
    QLineEdit *m_v4edit;
    QLineEdit *m_g2edit;
    QLineEdit *m_g3edit;
    QLineEdit *m_g4edit;
    QLineEdit *m_g5edit;
    QLineEdit *m_g6edit;
    QLineEdit *m_z1edit;
    QLineEdit *m_z2edit;
    QLineEdit *m_k1edit;
    QLineEdit *m_k2edit;
    QLineEdit *m_l1edit;
    QLineEdit *m_p1edit;
    QLineEdit *m_p2edit;
    QLineEdit *m_s1edit;
    QLineEdit *m_h1edit;
    QLineEdit *m_h2edit;
};

#endif // MAPPERDIALOG_H
