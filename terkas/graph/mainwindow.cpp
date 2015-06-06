#include <QtWidgets>
#include <QtSql>
#include <QDate>

#include <qwt_plot.h>
#include <qwt_plot_grid.h>

#include <qwt_plot_canvas.h>

#include <qwt_scale_draw.h>

#include <qwt_legend.h>
#include <qwt_legend_label.h>

#include <qwt_plot_curve.h>
#include <qwt_symbol.h>

#include <qwt_plot_magnifier.h>

#include <qwt_plot_panner.h>

#include <qwt_plot_picker.h>
#include <qwt_picker_machine.h>

#include "mainwindow.h"
#include "yearmonthscaledraw.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Создать поле со шкалами для отображения графика
    // (this) - разместить поле на текущем окне
    // #include <qwt_plot.h>
    d_plot = new QwtPlot(this);
    d_plot->setTitle("Статистика обслуженных ВС в филиале МЦ АУВД");  // заголовок


    QFont axisFont( "Helvetica", 9, QFont::Normal);
    d_plot->setAxisFont(QwtPlot::xBottom, axisFont);
    d_plot->setAxisFont(QwtPlot::yLeft, axisFont);


    // #include <qwt_plot_canvas.h>
    QwtPlotCanvas *canvas = new QwtPlotCanvas(d_plot);
    d_plot->setCanvas(canvas);
    canvas->setBorderRadius(5);
    d_plot->setCanvasBackground(Qt::white); // цвет фона


    // Установить внешние границы
    const int margin = 15;
    d_plot->setContentsMargins(margin, margin, margin, margin);

    // Параметры осей координат
    d_plot->setAxisTitle(QwtPlot::yLeft, "Количество ВС (тыс.)");
    d_plot->setAxisTitle(QwtPlot::xBottom, "Время (месяц год)");

    // Включить сетку
    // #include <qwt_plot_grid.h>
    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->setMajorPen(QPen(Qt::lightGray, 1)); // цвет линий и толщина
    grid->attach(d_plot); // добавить сетку к полю графика



    // Кривая innerFlights
    //#include <qwt_plot_curve.h>
    QwtPlotCurve *curveInnerFlights = new QwtPlotCurve();
    curveInnerFlights->setTitle("Внутренние\nрейсы");
    curveInnerFlights->setPen(Qt::green, 2); // цвет и толщина кривой
    curveInnerFlights->setRenderHint(QwtPlotItem::RenderAntialiased, true); // сглаживание

    // Маркеры кривой
    // #include <qwt_symbol.h>
    QwtSymbol *innerFlightsSymbol = new QwtSymbol(QwtSymbol::Ellipse,
                                      QBrush(Qt::yellow),
                                      QPen(Qt::green, 2),
                                      QSize(4, 4));
    curveInnerFlights->setSymbol(innerFlightsSymbol);



    // Кривая foreignFlights
    //#include <qwt_plot_curve.h>
    QwtPlotCurve *curveForeignFlights = new QwtPlotCurve();
    curveForeignFlights->setTitle("Международные\nрейсы");
    curveForeignFlights->setPen(Qt::black, 2); // цвет и толщина кривой
    curveForeignFlights->setRenderHint(QwtPlotItem::RenderAntialiased, true); // сглаживание

    // Маркеры кривой
    // #include <qwt_symbol.h>
    QwtSymbol *foreignFlightsSymbol = new QwtSymbol(QwtSymbol::Ellipse,
                                      QBrush(Qt::yellow),
                                      QPen(Qt::black, 2),
                                      QSize(4, 4));
    curveForeignFlights->setSymbol(foreignFlightsSymbol);



    // Кривая transitFlights
    //#include <qwt_plot_curve.h>
    QwtPlotCurve *curveTransitFlights = new QwtPlotCurve();
    curveTransitFlights->setTitle("Транзитные\nрейсы");
    curveTransitFlights->setPen(Qt::cyan, 2); // цвет и толщина кривой
    curveTransitFlights->setRenderHint(QwtPlotItem::RenderAntialiased, true); // сглаживание

    // Маркеры кривой
    // #include <qwt_symbol.h>
    QwtSymbol *transitFlightsSymbol = new QwtSymbol(QwtSymbol::Ellipse,
                                      QBrush(Qt::yellow),
                                      QPen(Qt::cyan, 2),
                                      QSize(4, 4));
    curveTransitFlights->setSymbol(transitFlightsSymbol);



    // Кривая charterFlights
    //#include <qwt_plot_curve.h>
    QwtPlotCurve *curveCharterFlights = new QwtPlotCurve();
    curveCharterFlights->setTitle("Чартерные\nрейсы");
    curveCharterFlights->setPen(Qt::magenta, 2); // цвет и толщина кривой
    curveCharterFlights->setRenderHint(QwtPlotItem::RenderAntialiased, true); // сглаживание

    // Маркеры кривой
    // #include <qwt_symbol.h>
    QwtSymbol *charterFlightsSymbol = new QwtSymbol(QwtSymbol::Ellipse,
                                      QBrush(Qt::yellow),
                                      QPen(Qt::magenta, 2),
                                      QSize(4, 4));
    curveCharterFlights->setSymbol(charterFlightsSymbol);



    // Кривая maxInDayFlights
    //#include <qwt_plot_curve.h>
    QwtPlotCurve *curveMaxInDayFlights = new QwtPlotCurve();
    curveMaxInDayFlights->setTitle("Максимально\nв сутки");
    curveMaxInDayFlights->setPen(Qt::red, 2); // цвет и толщина кривой
    curveMaxInDayFlights->setRenderHint(QwtPlotItem::RenderAntialiased, true); // сглаживание

    // Маркеры кривой
    // #include <qwt_symbol.h>
    QwtSymbol *maxInDayFlightsSymbol = new QwtSymbol(QwtSymbol::Ellipse,
                                      QBrush(Qt::yellow),
                                      QPen(Qt::red, 2),
                                      QSize(4, 4));
    curveMaxInDayFlights->setSymbol(maxInDayFlightsSymbol);



    // Кривая foreignAC
    //#include <qwt_plot_curve.h>
    QwtPlotCurve *curveForeignAC = new QwtPlotCurve();
    curveForeignAC->setTitle("Иностранные\nперевозчики");
    curveForeignAC->setPen(Qt::blue, 2); // цвет и толщина кривой
    curveForeignAC->setRenderHint(QwtPlotItem::RenderAntialiased, true); // сглаживание

    // Маркеры кривой
    // #include <qwt_symbol.h>
    QwtSymbol *foreignACSymbol = new QwtSymbol(QwtSymbol::Ellipse,
                                      QBrush(Qt::yellow),
                                      QPen(Qt::blue, 2),
                                      QSize(4, 4));
    curveForeignAC->setSymbol(foreignACSymbol);





    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("monrepo");
    db.setDatabaseName("terkas");
    if (!db.open()) {
        qDebug() << "Error while open database: " << db.lastError().text();
        return;
    }

    QPolygonF innerFlights;
    QPolygonF foreignFlights;
    QPolygonF transitFlights;
    QPolygonF charterFlights;
    QPolygonF maxInDayFlights;
    QPolygonF foreignAC;


    QSqlQuery query;
    query.prepare("SELECT "
                  "date,innerFlights,foreignFlights,transitFlights,charterFlights,maxInDayFlights,foreignAC "
                  "FROM statistics ORDER BY date");
    query.exec();
    while (query.next()) {
        QDate date = query.value(0).toDate();
        int years = date.year() * 12;
        int months = date.month();
        int dateNum = years + months;

        innerFlights    << QPointF(dateNum, query.value(1).toInt());
        foreignFlights  << QPointF(dateNum, query.value(2).toInt());
        transitFlights  << QPointF(dateNum, query.value(3).toInt());
        charterFlights  << QPointF(dateNum, query.value(4).toInt());
        maxInDayFlights << QPointF(dateNum, query.value(5).toInt());
        foreignAC       << QPointF(dateNum, query.value(6).toInt());
    }

    query.first();
    minDate_ = query.value(0).toDate();
    query.last();
    maxDate_ = query.value(0).toDate();

    query.finish();
    db.close();


    curveInnerFlights->setSamples(innerFlights);
    curveInnerFlights->attach(d_plot);

    curveForeignFlights->setSamples(foreignFlights);
    curveForeignFlights->attach(d_plot);

    curveTransitFlights->setSamples(transitFlights);
    curveMaxInDayFlights->attach(d_plot);

    curveCharterFlights->setSamples(charterFlights);
    curveCharterFlights->attach(d_plot);

    curveMaxInDayFlights->setSamples(maxInDayFlights);
    curveMaxInDayFlights->attach(d_plot);

    curveForeignAC->setSamples(foreignAC);
    curveForeignAC->attach(d_plot);


    // Текст меток на линейке осей координат
    d_plot->setAxisScaleDiv(QwtPlot::xBottom, yearScaleDiv());
    d_plot->setAxisScaleDraw(QwtPlot::xBottom, new YearMonthScaleDraw("ok"));

    // Задаем максимум осей
//    d_plot->setAxisScale(QwtPlot::xBottom, 0, 10);


    // Легенда
    QwtLegend *legend = new QwtLegend;
    legend->setDefaultItemMode(QwtLegendData::Checkable);
    d_plot->insertLegend(legend, QwtPlot::RightLegend);

    connect(legend, SIGNAL(checked(QVariant,bool,int)),
            SLOT(on_legendChecked(QVariant,bool,int)));



    // Включить возможность приближения/удаления графика
    // #include <qwt_plot_magnifier.h>
    QwtPlotMagnifier *magnifier = new QwtPlotMagnifier(d_plot->canvas());
    // клавиша, активирующая приближение/удаление
    magnifier->setMouseButton(Qt::MidButton);


    // Включить возможность перемещения по графику
    // #include <qwt_plot_panner.h>
    QwtPlotPanner *d_panner = new QwtPlotPanner(d_plot->canvas());
    // клавиша, активирующая перемещение
    d_panner->setMouseButton(Qt::RightButton);


    // Включить отображение координат курсора и двух перпендикулярных
    // линий в месте его отображения
    // #include <qwt_plot_picker.h>

    // настройка функций
    QwtPlotPicker *d_picker = new QwtPlotPicker(
                QwtPlot::xBottom, QwtPlot::yLeft, // ассоциация с осями
                QwtPlotPicker::CrossRubberBand,   // стиль перпендикулярных линий
                QwtPicker::ActiveOnly,            // включение/выключение
                d_plot->canvas());                // ассоциация с полем

    // Цвет перпендикулярных линий
    d_picker->setRubberBandPen(QColor(Qt::red));

    // цвет координат положения указателя
    d_picker->setTrackerPen(QColor(Qt::black));

    // непосредственное включение вышеописанных функций
    d_picker->setStateMachine(new QwtPickerDragPointMachine());


    setCentralWidget(d_plot);



    showCurve(curveInnerFlights, true);
    showCurve(curveForeignFlights, true);
    showCurve(curveTransitFlights, true);
    showCurve(curveCharterFlights, true);
//    showCurve(curveMaxInDayFlights, true);
    showCurve(curveForeignAC, true);
    showCurve(curveMaxInDayFlights, false);
}

MainWindow::~MainWindow()
{

}

QwtScaleDiv MainWindow::yearScaleDiv() const
{
    int min = minDate_.year() * 12 + minDate_.month();
    int max = maxDate_.year() * 12 + maxDate_.month();

    QList<double> majorTicks;
    for (double i = min; i <= max; i++) {
        majorTicks += i;
    }

    QList<double> mediumTicks;
    for (double i = min; i < max; i++) {
        mediumTicks += i;
    }

    QList<double> minorTicks;
    for (double i = min; i < max; i++) {
        minorTicks += i;
    }

    QwtScaleDiv scaleDiv(min - 1, max + 1,
                         minorTicks, mediumTicks, majorTicks);
    return scaleDiv;
}

void MainWindow::on_legendChecked(const QVariant &itemInfo, bool on, int /*index*/)
{
    QwtPlotItem *plotItem = d_plot->infoToItem(itemInfo);
    if (plotItem) {
        showCurve(plotItem, on);
    }
    d_plot->replot();
}

void MainWindow::showCurve(QwtPlotItem *item, bool on)
{
    item->setVisible(on);

    QwtLegend *lgd = qobject_cast<QwtLegend *>(d_plot->legend());

    QList<QWidget *> legendWidgets = lgd->legendWidgets(d_plot->itemToInfo(item));

    if (legendWidgets.size() == 1)
    {
        QwtLegendLabel *legendLabel = qobject_cast<QwtLegendLabel *>(legendWidgets[0]);

        if (legendLabel)
            legendLabel->setChecked(on);
    }
}

