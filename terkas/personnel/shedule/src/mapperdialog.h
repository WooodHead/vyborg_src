#ifndef MAPPERDIALOG_H
#define MAPPERDIALOG_H

#include <vyborg/vyborg.h>

QT_BEGIN_NAMESPACE
class QDateEdit;
class QLineEdit;
//class QComboBox;
//class QTextEdit;
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
    QLineEdit *m_nameLineEdit;
    QLineEdit *m_middlenameLineEdit;
    QLineEdit *m_surnameLineEdit;
    QLineEdit *m_innernumLineEdit;
    QLineEdit *m_activityLineEdit;
    QLineEdit *m_sectorpidLineEdit;
    QDateEdit *m_startDateEdit;
    QDateEdit *m_stopDateEdit;
};

#endif // MAPPERDIALOG_H
