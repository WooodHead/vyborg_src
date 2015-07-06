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
    MapperDialog(QSqlRelationalTableModel *model, QWidget *parent = 0);

protected:
    virtual void createPrivateWidgets() Q_DECL_OVERRIDE;
    virtual void layoutPrivateWidgets() Q_DECL_OVERRIDE;
    virtual void updatePrivateWidgets() Q_DECL_OVERRIDE;

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
