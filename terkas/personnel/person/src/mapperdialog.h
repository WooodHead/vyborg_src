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
    virtual void createPrivateWidgets();
    virtual void layoutPrivateWidgets();
    virtual void updatePrivateWidgets();

private:
    QLineEdit *m_surnameLE;
    QLineEdit *m_nameLE;
    QLineEdit *m_middlenameLE;
    QLineEdit *m_tabnumLE;
    QLineEdit *m_birthdayLE;
    QLineEdit *m_positionLE;
    QLineEdit *m_divisionLE;
    QLineEdit *m_subdivisionLE;
    QLineEdit *m_shiftLE;
    QLineEdit *m_classLE;
    QLineEdit *m_icaolevelLE;
    QLineEdit *m_icaolevelvalidLE;
    QLineEdit *m_licencenumLE;
    QLineEdit *m_licencevalidLE;
    QLineEdit *m_mobilephoneLE;
    QLineEdit *m_stazhLE;
    QLineEdit *m_postupLE;
    QLineEdit *m_medicalvalidLE;
    QLineEdit *m_sectorgroupLE;
    QLineEdit *m_sectoradmittanceLE;
    QLineEdit *m_positionadmittanceLE;
    QLineEdit *m_kpkrpLE;
    QLineEdit *m_kpksdLE;
    QLineEdit *m_kpkdiLE;
    QLineEdit *m_kpkfactLE;
    QLineEdit *m_kpkplanLE;
    QLineEdit *m_kpkompfactLE;
    QLineEdit *m_kpkompplanLE;
    QLineEdit *m_vysshLE;
    QLineEdit *m_sredneeLE;
    QLineEdit *m_kursyLE;
    QLineEdit *m_obrazovLE;
    QLineEdit *m_gosnagradyLE;
    QLineEdit *m_otraslnagradyLE;
    QLineEdit *m_fgupnagradyLE;
    QLineEdit *m_filialnagradyLE;
};

#endif // MAPPERDIALOG_H
