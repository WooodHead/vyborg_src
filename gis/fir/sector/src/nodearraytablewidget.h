#ifndef NODEARRAYTABLEWIDGET_H
#define NODEARRAYTABLEWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QAbstractTableModel;
class QTableView;
QT_END_NAMESPACE

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

    // Visible elements
    ArrayTableModel *m_model;
    QTableView *m_view;
};

#include <QAbstractTableModel>

class ArrayTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ArrayTableModel(QObject *parent = Q_NULLPTR);

    QVariant data(const QModelIndex &index, int role) const;

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
};

#endif // NODEARRAYTABLEWIDGET_H
