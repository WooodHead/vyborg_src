#ifndef ADWIDGET_H
#define ADWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QTableView;
class QLabel;
QT_END_NAMESPACE
class TableModel;
class ProxyModel;


class ADwidget : public QWidget
{
    Q_OBJECT

public:
    ADwidget(QWidget *parent = 0);

private slots:
    void showMapperDialog();
    void showSortDialog();
    void showFilterDialog();
    void update();
    void add();
    void del();

private:
    void sort(const int &column, Qt::SortOrder order = Qt::AscendingOrder);
    void filter(const int &column,
                const QString &pattern,
                Qt::CaseSensitivity cs = Qt::CaseInsensitive);

private:
    TableModel *m_model;
    ProxyModel *m_proxy;
    QTableView *m_view;
    QLabel     *m_posLabel;
};

#endif // ADWIDGET_H
