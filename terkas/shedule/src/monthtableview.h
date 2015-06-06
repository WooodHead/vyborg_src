#ifndef MONTHTABLEVIEW_H
#define MONTHTABLEVIEW_H

#include <QTableView>

class MonthTableModel;


class MonthTableView : public QTableView
{
    Q_OBJECT

public:
    explicit MonthTableView(QWidget *parent = 0);

private:
    void mousePressEvent(QMouseEvent *event);
    MonthTableModel* model();
};

#endif // MONTHTABLEVIEW_H
