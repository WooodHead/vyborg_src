#ifndef NODELISTWIDGET_H
#define NODELISTWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QSqlTableModel;
//class QSqlQueryModel;
class QTableView;
QT_END_NAMESPACE

class NodeListWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int sectorpid READ sectorpid WRITE setSectorpid NOTIFY sectorpidChanged USER true)

public:
    explicit NodeListWidget(QWidget *parent = 0);

    int sectorpid() const;
    void setSectorpid(int sectorpid);

signals:
    void sectorpidChanged();

private:
    int m_sectorpid;
    QSqlTableModel *m_model;
//    QSqlQueryModel *m_model;
    QTableView *m_view;
};

#endif // NODELISTWIDGET_H
