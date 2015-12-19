#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QComboBox;
QT_END_NAMESPACE

class SortDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SortDialog(QWidget *parent = 0);

    void addValues(const QStringList &labels, const QList<int> &values);

private slots:
    void sort();

private:
    QComboBox *m_comboBox;
};

#endif // SORTDIALOG_H
