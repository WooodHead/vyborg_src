#ifndef NODEINPUTDIALOG_H
#define NODEINPUTDIALOG_H

#include <QDialog>

class NodeInputDialog : public QDialog
{
    Q_OBJECT

public:
    NodeInputDialog(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
};

#endif // NODEINPUTDIALOG_H
