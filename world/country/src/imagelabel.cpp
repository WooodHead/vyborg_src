#include <QtGui>

#include "imagelabel.h"

ImageLabel::ImageLabel(QObject *parent)
{
    pixmap = QPixmap();
}

QSize ImageLabel::sizeHint() const
{
    qDebug() << "size Hint";
    return QSize(270, 170);
}

#include <QDebug>
void ImageLabel::loadPixmapFromFile(const QString &fileName)
{
    resize(270, 170);
    qDebug() << width() << height();
    pixmap = QPixmap(fileName).scaled(width() - 10,
                                      height() - 10,
                                      Qt::KeepAspectRatio,
                                      Qt::SmoothTransformation);
    setPixmap(pixmap);
}
