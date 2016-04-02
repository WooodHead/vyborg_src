#ifndef NODEARRAYTABLEWIDGET_H
#define NODEARRAYTABLEWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QTableView;
class QPushButton;
QT_END_NAMESPACE

class ArrayTableModel;

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

private slots:
    void addButtonClicked();
    void removeButtonClicked();

private: // functions
    QList<int> fromString(const QString &string);
    QString toString(QList<int> arr) const;

private:
    QList<int> m_nodepidarr;

    ArrayTableModel *m_model;
    QTableView *m_view;
    QPushButton *m_addButton;
    QPushButton *m_removeButton;
};

#include <QAbstractTableModel>

class ArrayTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    ArrayTableModel(QObject *parent = Q_NULLPTR);
    ArrayTableModel(QList<int> nodepidarr, QObject *parent = Q_NULLPTR);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) Q_DECL_OVERRIDE;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) Q_DECL_OVERRIDE;

    void setNodepidarr(QList<int> nodepidarr);

private:
    QList<int> m_nodepidarr;
};

#endif // NODEARRAYTABLEWIDGET_H
