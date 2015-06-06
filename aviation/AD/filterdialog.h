#ifndef FILTERDIALOG_H
#define FILTERDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QComboBox;
class QLineEdit;
class QCheckBox;
QT_END_NAMESPACE


class FilterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FilterDialog(QWidget *parent = 0);

    void addValues(const QStringList &labels, const QList<int> &values);

    int column() const;
    QString pattern() const;
    Qt::CaseSensitivity cs() const;

private slots:
    void filter();

private:
    QComboBox *m_comboBox;
    QLineEdit *m_lineEdit;
    QCheckBox *m_csCheckBox;

    QString m_pattern;
};

#endif // FILTERDIALOG_H
