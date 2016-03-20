#ifndef MAPPERDIALOG_H
#define MAPPERDIALOG_H

#include <vyborg.h>

QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE

class NodesListWidget;
class NodeListWidget;

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
    QLineEdit *m_sectorLE;
    QLineEdit *m_fullnameLE;
    QLineEdit *m_labelLE;
    QLineEdit *m_compoundLE;
    NodesListWidget *m_nodesListW;
    NodeListWidget *m_nodeListW;
};

#endif // MAPPERDIALOG_H
