#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qwt_plot.h>
#include <qwt_scale_div.h>
#include <QDate>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private Q_SLOTS:
    void on_legendChecked(const QVariant &itemInfo, bool on, int index);

private:
    QwtScaleDiv yearScaleDiv() const;
    void showCurve(QwtPlotItem *item, bool state);

    QwtPlot *d_plot;

    QDate minDate_;
    QDate maxDate_;
};

#endif // MAINWINDOW_H
