#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QAbstractButton;
class QDialogButtonBox;
QT_END_NAMESPACE

class HourModel;
class TableView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void bboxClicked(QAbstractButton *button);

private:
    void add();
    void rem();
    void edit();
    void save();
    void rej();

private:
    QDialogButtonBox *bbox;

    HourModel *m_model;
    TableView *m_view;

    enum {
        AddRole = 1,
        RemRole,
        EditRole,
        SaveRole,
        RejRole
    };
};

#endif // MAINWINDOW_H
