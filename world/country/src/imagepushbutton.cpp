#include <QtGui>
//#include <QtWidgets>

#include "imagepushbutton.h"

ImagePushButton::ImagePushButton(QWidget *parent) :
    QPushButton(parent)
{
    connect(this, SIGNAL(clicked()),
            this, SLOT(selectPicture()));
}

void ImagePushButton::setImageText(const QString &text)
{
    my_imageText = text;

    if (!my_imageText.isEmpty()) {
        QPixmap pixmap(my_imageText);
        pixmap.scaled(width() - 10, height() - 10, Qt::KeepAspectRatio);
        QIcon buttonIcon;
        buttonIcon.addPixmap(pixmap);
        setIcon(buttonIcon);
        setIconSize(QSize(width() - 10, height() - 10));
    } else {
        setIcon(QIcon());
    }
}

QString ImagePushButton::imageText() const
{
    return my_imageText;
}

void ImagePushButton::selectPicture()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    trUtf8("Open Picture"),
                                                    "/usr/share/vyborg/images/flags/",
                                                    trUtf8("Image Files (*.png *.gif *.jpg *.jpeg *.svg)"));
    setImageText(fileName);
    update();
}

void ImagePushButton::setPressed(bool value)
{
    pressedState = value;
    setFlat(pressedState);
}
