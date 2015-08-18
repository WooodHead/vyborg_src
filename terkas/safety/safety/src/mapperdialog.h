#ifndef MAPPERDIALOG_H
#define MAPPERDIALOG_H

#include <vyborg.h>

QT_BEGIN_NAMESPACE
class QDateEdit;
class QLineEdit;
class QComboBox;
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
    QComboBox *m_accCombo;
    QComboBox *m_classificationCombo;
    QComboBox *m_typeCombo;
    QComboBox *m_terkasCombo;
    QComboBox *m_alphaCombo;
    QComboBox *m_tcas1Combo;
    QComboBox *m_tcas2Combo;
};

#endif // MAPPERDIALOG_H
