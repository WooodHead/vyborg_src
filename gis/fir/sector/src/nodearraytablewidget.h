#ifndef NODEARRAYTABLEWIDGET_H
#define NODEARRAYTABLEWIDGET_H

#include <QWidget>

class NodeArrayTableWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString nodepidarr READ nodepidarr WRITE setNodepidarr NOTIFY nodepidarrChanged USER true)

public:
    explicit NodeArrayTableWidget(QWidget *parent = 0);

    void setNodepidarr(const QString &nodepidarr);
    QString nodepidarr() const;

signals:
    void nodepidarrChanged();

private:
    QList<int> fromString(const QString &string);
    QString toString(QList<int> arr) const;

private:
    QList<int> m_nodepidarr;
};

#endif // NODEARRAYTABLEWIDGET_H
