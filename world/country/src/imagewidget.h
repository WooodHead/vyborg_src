#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>


class ImageWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName)

public:
    ImageWidget(QWidget *parent = 0);

    QSize sizeHint() const;
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);

    void setFileName(const QString &fileName);
    QString fileName() const;

private:
    QString fileName_;
    int width_;
    int height_;
};

#endif // IMAGEWIDGET_H
