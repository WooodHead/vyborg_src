#ifndef GEOGWIDGET_H
#define GEOGWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QTableView;
QT_END_NAMESPACE

class GeogWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString geog READ geog WRITE setGeog NOTIFY geogChanged USER true)

public:
    GeogWidget(QWidget *parent = 0);

    void setGeog(const QString &geog);
    QString geog() const;

signals:
    void geogChanged();

private:
    QTableView *m_tableView;

private:
    QString m_geog;
};

#endif // GEOGWIDGET_H
