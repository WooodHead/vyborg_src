#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MonthTableModel;
QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

private:
    MonthTableModel *m_monthTableModel;
};

#endif // MAINWINDOW_H
