#ifndef MAPPERDIALOG_H
#define MAPPERDIALOG_H

#include <vyborg.h>

QT_BEGIN_NAMESPACE
class QDateEdit;
class QLineEdit;
class QTextEdit;
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
    QDateEdit *m_dateEdit;
    QLineEdit *m_shiftEdit;
    QLineEdit *m_locationEdit;
    QTextEdit *m_causeEdit;
    QTextEdit *m_factorEdit;
    QTextEdit *m_detailsEdit;
    QLineEdit *m_sectorEdit;
    QLineEdit *m_accEdit;
    QLineEdit *m_classificationEdit;
};

#endif // MAPPERDIALOG_H
