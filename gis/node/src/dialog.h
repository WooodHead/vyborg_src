#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QModelIndex>

//class QModelIndex;
class RelationalTableModel;
class QTableView;


class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);

private slots:
    void openMapperDialog(const QModelIndex &indx);
    void add();
    void remove();

private:
    RelationalTableModel *m_model;
    QTableView *m_view;
};

#endif // DIALOG_H
