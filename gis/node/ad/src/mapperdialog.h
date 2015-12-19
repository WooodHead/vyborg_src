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
    // Visual elements
    QLineEdit *m_validLE;
    QLineEdit *m_countryindxLE;
    QLineEdit *m_countryLE;
    QLineEdit *m_cityLE;
    QLineEdit *m_nameLE;
    QLineEdit *m_indxLE;
    QLineEdit *m_indxruLE;
    QLineEdit *m_typeLE;
    QLineEdit *m_intlLE;
    QLineEdit *m_staffLE;
    QLineEdit *m_elevationLE;
    QLineEdit *m_emailLE;
    QLineEdit *m_webLE;
    QLineEdit *m_noteLE;
    QLineEdit *m_coordLE;
};

#endif // MAPPERDIALOG_H
