#ifndef PERSONWIDGET_H
#define PERSONWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE

class PersonWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int pid READ pid WRITE setPid NOTIFY pidChanged USER true)
    
public:
    PersonWidget(QWidget *parent = 0);

    int pid() const;
    void setPid(const int &pid);

Q_SIGNALS:
    void pidChanged(int);

private:
    int m_pid;
    QLineEdit *m_fullnameLE;
    QLineEdit *m_numLE;
    QLineEdit *m_shiftLE;
};

#endif // PERSONWIDGET_H
