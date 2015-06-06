#ifndef SHIFTNUM_H
#define SHIFTNUM_H

#include <QSpinBox>


class ShiftNum : public QSpinBox
{
    Q_OBJECT

public:
    ShiftNum(QWidget *parent = 0);

    QString textFromValue(int val) const;
    int valueFromText(const QString &text) const;
};

#endif // SHIFTNUM_H
