#ifndef IMAGELABAL_H
#define IMAGELABAL_H

#include <QWidget>
#include <QPixmap>
#include <QLabel>

class ImageLabel : public QLabel
{
    Q_OBJECT

public:
    ImageLabel(QWidget *parent = 0);

    QSize sizeHint() const;

    void loadPixmapFromFile(const QString &fileName);

private:
    QPixmap pixmap;
};

#endif // IMAGELABAL_H

