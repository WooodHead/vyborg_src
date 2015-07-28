#ifndef MAPPERDIALOG_H
#define MAPPERDIALOG_H

#include <vyborg.h>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QTextEdit;
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
    QLineEdit *surnameLineEdit;
    QLineEdit *nameLineEdit;
    QLineEdit *middleNameLineEdit;
    QLineEdit *innerIdLineEdit;
    QLineEdit *mobilePhoneLineEdit;
};

#endif // MAPPERDIALOG_H
