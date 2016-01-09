#ifndef RWWIDGET_H
#define RWWIDGET_H

#include <QWidget>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
class QTableView;
QT_END_NAMESPACE

class RWWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int adid READ adid WRITE setAdid NOTIFY adidChanged USER true)

public:
    RWWidget(QWidget *parent = 0);

    void setAdid(const int &adid);
    int adid() const;

signals:
    void adidChanged();

private:
    QTableView *m_tableView;

private:
    int m_adid;
};

class RWTableModel : public QSqlTableModel
{
    Q_OBJECT

public:
    RWTableModel(QObject *parent = Q_NULLPTR, QSqlDatabase db = QSqlDatabase());

    QVariant data(const QModelIndex &idx, int role) const;
};

#endif // RWWIDGET_H
