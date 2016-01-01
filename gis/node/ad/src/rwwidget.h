#ifndef RWWIDGET_H
#define RWWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QTableView;
QT_END_NAMESPACE

class RWWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RWWidget(QWidget *parent = 0);

    void setADId(const int &indx);

private:
    QTableView *m_tableView;
};

#endif // RWWIDGET_H
