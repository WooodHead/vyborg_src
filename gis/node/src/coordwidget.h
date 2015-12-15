#ifndef COORDWIDGET_H
#define COORDWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QStackedLayout;
QT_END_NAMESPACE

class GMScoord;
class GMcoord;


class CoordWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(qreal coord READ coord WRITE setCoord NOTIFY coordChanged)

public:
    explicit CoordWidget(QWidget *parent = 0);

    qreal coord() const;
    void setCoord(qreal &coord);

signals:
    void coordChanged(qreal &coord);

private slots:
    void updateCoord();
    void coordStyleChanged();

private:
    qreal m_coord;

    QStackedLayout *m_stack;
    GMScoord *m_gmsCoord;
    GMcoord *m_gmCoord;

    enum {
        GMS,
        GM,
        G
    } m_coordStyle;
};

#endif // COORDWIDGET_H
