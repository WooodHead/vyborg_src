#ifndef NODEWIDGET_H
#define NODEWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QRadioButton;
QT_END_NAMESPACE

class NodeWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString geog READ geog WRITE setGeog NOTIFY geogChanged USER true)

public:
    NodeWidget(QWidget *parent = 0);

    void setGeog(const QString &geog);
    QString geog() const;

    void setEnabled(bool state);

signals:
    void geogChanged();

private slots:
    void showNode();

private:
    QLineEdit    *m_latLE;
    QLineEdit    *m_lonLE;
    QLineEdit    *m_sridLE;
    QRadioButton *m_radio1;
    QRadioButton *m_radio2;

private:
    mutable QString m_geog;
};

#endif // NODEWIDGET_H
