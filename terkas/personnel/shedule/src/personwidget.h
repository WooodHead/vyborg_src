#ifndef PERSONWIDGET_H
#define PERSONWIDGET_H

#include <QWidget>

class PersonWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged USER true)

public:
    PersonWidget(QWidget *parent = 0);

    QString text() const;
    void setText(const QString &text);

signals:
    void textChanged();

private:
    QString m_text;
};

#endif // PERSONWIDGET_H
