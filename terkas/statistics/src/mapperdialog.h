#ifndef MAPPERDIALOG_H
#define MAPPERDIALOG_H

#include <vyborg.h>

class QDateEdit;
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
    QDateEdit *dateEdit;
    QLineEdit *innerFlightsEdit;
    QLineEdit *foreignFlightsEdit;
    QLineEdit *transitFlightsEdit;
    QLineEdit *charterFlightsEdit;
    QLineEdit *maxInDayFlightsEdit;
    QLineEdit *foreignACEdit;
    QTextEdit *noteEdit;
};

#endif // MAPPERDIALOG_H
