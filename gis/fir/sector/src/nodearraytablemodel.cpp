#include <QAbstractTableModel>
#include <QSqlQuery>

#include <vyborg/convert.h>

#include "nodearraytablemodel.h"

NodeArrayTableModel::NodeArrayTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    m_nodepidarr = QList<int>();
}

NodeArrayTableModel::NodeArrayTableModel(QList<int> nodepidarr, QObject *parent)
    : QAbstractTableModel(parent)
{
    m_nodepidarr = nodepidarr;
}

Qt::ItemFlags NodeArrayTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

QVariant NodeArrayTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= m_nodepidarr.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        int row = index.row();
        int column = index.column();

        QSqlQuery query("SELECT pid,St_AsLatLonText(geog::geometry, 'D M S.SSS'), noteru "
                        "FROM data.vw_node WHERE pid=" + QString::number(m_nodepidarr.at(row)));
        while (query.next()) {
            QString geog = query.value(1).toString();
            QString noteru = query.value(2).toString();
            if (column == 0)
                return coordRaw2readable(geog);
            else if (column == 1)
                return noteru;
        }
    }

    return QVariant();
}

QVariant NodeArrayTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (section < 0)
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            if (section > columnCount())
                return QVariant();

            switch (section) {
            case 0:
                return trUtf8("Координаты точки");
            case 1:
                return trUtf8("Примечание");
            default:
                return QVariant();
            }
        } else if (orientation == Qt::Vertical) {
            return trUtf8("%1").arg(section + 1);
        }
    }

    return QVariant();
}

bool NodeArrayTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        int i = index.row();
        m_nodepidarr.replace(i, value.toInt());
        emit dataChanged(index, index);
        return true;
    }

    return false;
}

int NodeArrayTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_nodepidarr.size();
}

int NodeArrayTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 2;
}

void NodeArrayTableModel::setNodepidarr(QList<int> nodepidarr)
{
    if (nodepidarr != m_nodepidarr) {
        beginResetModel();
        m_nodepidarr = nodepidarr;
        endResetModel();
    }
}

QList<int> NodeArrayTableModel::nodepidarr() const
{
    return m_nodepidarr;
}

bool NodeArrayTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    if (row < 0 || row > m_nodepidarr.size())
        return false;

    beginInsertRows(parent, row, row + count - 1);

    for (int i = 0; i < count; i++)
        m_nodepidarr.insert(row + i, -1); // Inserting value of -1 into array

    endInsertRows();
    return true;
}

bool NodeArrayTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if (row < 0 || row > m_nodepidarr.size())
        return false;

    beginRemoveRows(parent, row, row + count - 1);

    for (int i = 0; i < count; ++i)
        m_nodepidarr.removeAt(row + i);

    endRemoveRows();
    return true;
}
