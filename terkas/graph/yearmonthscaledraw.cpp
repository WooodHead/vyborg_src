#include <QtWidgets>
#include <QDate>

#include "yearmonthscaledraw.h"


YearMonthScaleDraw::YearMonthScaleDraw(const QString &format)
{
    format_ = format;

    setTickLength( QwtScaleDiv::MajorTick, 10 );
    setTickLength( QwtScaleDiv::MinorTick, 0 );
    setTickLength( QwtScaleDiv::MediumTick, 0 );

    setLabelRotation(-90.0);
    setLabelAlignment(Qt::AlignLeft | Qt::AlignVCenter);
}

QwtText YearMonthScaleDraw::label(double value) const
{
    int years = (int)value / 12;
    int months = (int)value % 12;
    if (months == 0) {
        months = 12;
        years--;
    }
    QDate date(years, months, 1);

    QString str = QDate::longMonthName(date.month()) + QChar(' ') + QString::number(date.year());

    return str;
}
