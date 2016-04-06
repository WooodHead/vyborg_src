#ifndef NODEARRAYTABLEMODEL_H
#define NODEARRAYTABLEMODEL_H

#include <QAbstractTableModel>

class NodeArrayTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    NodeArrayTableModel(QObject *parent = Q_NULLPTR);
    NodeArrayTableModel(QList<int> nodepidarr, QObject *parent = Q_NULLPTR);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) Q_DECL_OVERRIDE;

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) Q_DECL_OVERRIDE;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) Q_DECL_OVERRIDE;

    void setNodepidarr(QList<int> nodepidarr);
    QList<int> nodepidarr() const;

private:
    QList<int> m_nodepidarr;
};

#endif // NODEARRAYTABLEMODEL_H
