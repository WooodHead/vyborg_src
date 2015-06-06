#ifndef YEARMONTHSCALEDRAW_H
#define YEARMONTHSCALEDRAW_H

#include <qwt_scale_draw.h>


class YearMonthScaleDraw : public QwtScaleDraw
{
public:
    YearMonthScaleDraw(const QString &format);

    virtual QwtText label(double value) const;

private:
    QString format_;
};

#endif // YEARMONTHSCALEDRAW_H
