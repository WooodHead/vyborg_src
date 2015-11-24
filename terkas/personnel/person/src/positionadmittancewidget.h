#ifndef POSITIONADMITTANCEWIDGET_H
#define POSITIONADMITTANCEWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QCheckBox;
QT_END_NAMESPACE

class PositionAdmittanceWidget : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QString array READ array WRITE setArray /*NOTIFY arrayChanged*/ USER true)

public:
    explicit PositionAdmittanceWidget(QWidget *parent = 0);

public Q_SLOTS:
    QString array() const;
    void setArray(const QString & array);

private:
    QCheckBox *m_checkRP;
    QCheckBox *m_checkSD;
    QCheckBox *m_checkDI;
    QCheckBox *m_checkD;
    QCheckBox *m_checkSDGOP;
    QCheckBox *m_checkDGOP;

    QString m_array;
};

#endif // POSITIONADMITTANCEWIDGET_H
