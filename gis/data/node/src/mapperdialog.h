#ifndef MAPPERDIALOG_H
#define MAPPERDIALOG_H

#include <vyborg.h>

QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE

class GeogWidget;

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
    GeogWidget *m_geogWid;
    QLineEdit  *m_noteruLE;
};

#endif // MAPPERDIALOG_H
