#ifndef NODESLISTWIDGET_H
#define NODESLISTWIDGET_H

#include <QListWidget>

class NodesListWidget : public QListWidget
{
    Q_OBJECT
    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged USER true)

public:
    NodesListWidget(QWidget *parent = 0);

    QString id() const;
    void setId(const QString &id);

signals:
    void idChanged();

private:
    QString m_id;
};

#endif // NODESLISTWIDGET_H
