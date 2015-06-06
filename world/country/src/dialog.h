#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>

class QSqlTableModel;
class QTableView;
class QPushButton;

class Dialog : public QWidget
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);

private slots:
//    void sort(int column,
//              Qt::SortOrder order = Qt::AscendingOrder,
//              Qt::CaseSensitivity cs = Qt::CaseInsensitive);
//    void search(int column,
//                QRegExp rx,
//                Qt::CaseSensitivity cs = Qt::CaseInsensitive);

//    void reset();

    void add();
    void remove();

private:
//    void showMapperDialog();
//    void showSearchDialog();
//    void showSortDialog();

private:
    QSqlTableModel *model_;
    QTableView *view_;
    QPushButton *resetButton;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *showButton;
    QPushButton *sortButton;
    QPushButton *searchButton;
    QPushButton *closeButton;
};

#endif // DIALOG_H
