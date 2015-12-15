#ifndef COORD_H
#define COORD_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE


class GMScoord : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(qreal coord READ coord WRITE setCoord NOTIFY coordChanged)

public:
    explicit GMScoord(QWidget *parent = 0);

    qreal coord() const;
    void setCoord(qreal &coord);

signals:
    void coordChanged();

public slots:
    void coordRecalc();

private:
    QLineEdit *m_gle;
    QLineEdit *m_mle;
    QLineEdit *m_sle;

    qreal m_coord;
};

class GMcoord : public QWidget
{
    Q_OBJECT

public:
    explicit GMcoord(QWidget *parent = 0);

private:
    QLineEdit *m_gle;
    QLineEdit *m_mle;
};

#endif // COORD_H
