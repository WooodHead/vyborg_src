#ifndef RWWIDGET_H
#define RWWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QTableView;
//class QLabel;
//class QLineEdit;
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
//    QLineEdit  *m_latLE;
//    QLineEdit  *m_lonLE;

private:
    int m_adid;
};

#endif // RWWIDGET_H