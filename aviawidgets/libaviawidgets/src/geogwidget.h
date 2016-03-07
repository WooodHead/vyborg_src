#ifndef GEOGWIDGET_H
#define GEOGWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QRadioButton;
class QAbstractButton;
QT_END_NAMESPACE

class GeogWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString geog READ geog WRITE setGeog NOTIFY geogChanged USER true)

public:
    GeogWidget(QWidget *parent = 0);

    void setGeog(const QString &geog);
    QString geog() const;

    void setEnabled(bool state);

signals:
    void geogChanged();

private slots:
    void showGeog();

private:
    QLineEdit    *m_latLE;
    QLineEdit    *m_lonLE;
    QLineEdit    *m_sridLE;
    QRadioButton *m_radio1;
    QRadioButton *m_radio2;

private:
    mutable QString m_geog;
    double m_lat;
    double m_lon;
    int m_srid;
};

#endif // GEOGWIDGET_H
