#include <QtWidgets>

#include "imagewidget.h"
#include "declarations.h"


ImageWidget::ImageWidget(QWidget *parent) :
    QWidget(parent), width_(300), height_(200)
{
}

QSize ImageWidget::sizeHint() const
{
    return QSize(width_, height_);
}

void ImageWidget::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    painter.save();
    painter.setRenderHint(QPainter::Antialiasing, true);

    if (!fileName_.isEmpty())
    {
        QPixmap pixmap = QPixmap(fileName_).scaled(width_,
                                                   height_,
                                                   Qt::KeepAspectRatio,
                                                   Qt::SmoothTransformation);
        QPoint point((width_ - pixmap.width()) / 2,
                     (height_ - pixmap.height()) / 2);
        painter.drawPixmap(point, pixmap);
        painter.drawRect(point.x(), point.y(), pixmap.width(), pixmap.height());
    }
    else
        painter.drawText(0, 0, "No Image");

    painter.restore();
}

void ImageWidget::mousePressEvent(QMouseEvent *event)
{
    switch (event->button()) {
    case Qt::LeftButton:
        fileName_ = QFileDialog::getOpenFileName(this,
                                                 trUtf8("Open Image File"),
                                                 IMAGE_DIR,
                                                 trUtf8("Image Files (*.png *.jpg *.bmp *.gif)"));
        break;
    default:
        QWidget::mousePressEvent(event);
        break;
    }
}

void ImageWidget::setFileName(const QString &fileName)
{
    if (!fileName.isEmpty())
        fileName_ = QString(IMAGE_DIR + fileName + "/flag/flag.png");
    else
        fileName_ = "";

    update();
}

QString ImageWidget::fileName() const
{
    return fileName_;
}
