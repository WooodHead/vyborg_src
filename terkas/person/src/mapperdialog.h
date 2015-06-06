#ifndef MAPPERDIALOG_H
#define MAPPERDIALOG_H

#include <vyborg.h>

class QLineEdit;
class QTextEdit;


class MapperDialog : public VyborgMapperDialog
{
    Q_OBJECT

public:
    MapperDialog(QSortFilterProxyModel *proxy, QWidget *parent = 0);

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
