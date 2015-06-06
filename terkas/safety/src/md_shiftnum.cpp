#include "md_shiftnum.h"


ShiftNum::ShiftNum(QWidget *parent)
    : QSpinBox(parent)
{
    setMinimum(0);
    setMaximum(6);
}

QString ShiftNum::textFromValue(int val) const
{
   if (val > 0)
       return QString::number(val);
   else
       return QString("No value");
}

int ShiftNum::valueFromText(const QString &text) const
{
    if (text == "No value")
        return 0;

    bool ok;
    return text.toInt(&ok);
}
