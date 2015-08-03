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
    MapperDialog(QSqlRelationalTableModel *model, QWidget *parent = 0);

protected:
    virtual void createPrivateWidgets();
    virtual void layoutPrivateWidgets();
    virtual void updatePrivateWidgets();

private:
    QLineEdit *m_surnameLineEdit;
    QLineEdit *m_nameLineEdit;
    QLineEdit *m_middlenameLineEdit;
    QLineEdit *m_innernumLineEdit;
    QLineEdit *m_phonemobileLineEdit;
};

#endif // MAPPERDIALOG_H
