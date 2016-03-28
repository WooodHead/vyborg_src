#include <QtWidgets>
#include <QtSql>

#include "nodearraytablewidget.h"

NodeArrayTableWidget::NodeArrayTableWidget(QWidget *parent)
    : QWidget(parent),
      m_nodepidarr(QList<int>())
{
    m_model = new ArrayTableModel(m_nodepidarr, this);

    m_view = new QTableView;
    m_view->setModel(m_model);
    m_view->resizeColumnsToContents();

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(m_view);

    setLayout(mainLayout);
}

void NodeArrayTableWidget::setNodepidarr(const QString &nodepidarr)
{
    // Add here check for correct array string

    QList<int> l = fromString(nodepidarr);
    if (l != m_nodepidarr) {
        m_nodepidarr = l;
        m_model->setNodepidarr(m_nodepidarr);
        emit nodepidarrChanged();
    }
}

QString NodeArrayTableWidget::nodepidarr() const
{
    QString string = toString(m_nodepidarr);
    return string;
}

QList<int> NodeArrayTableWidget::fromString(const QString &string)
{
    if (string.isEmpty())
        return QList<int>();

    if (string.left(1) != "{")
        return QList<int>();

    if (string.right(1) != "}")
        return QList<int>();

    QStringRef sref(&string, 1, string.length() - 2); // Remove braces
    QVector<QStringRef> v = sref.split(",");
    QList<int> list = QList<int>();
    for (const QStringRef &r: v) {
        list << r.toInt();
    }

    return list;
}

QString NodeArrayTableWidget::toString(QList<int> arr) const
{
    if (arr.isEmpty())
        return QString();

    QString string;
    for (int i = 0; i < arr.size(); i++) {
        string += QString::number(arr.at(i));
        if (i < arr.size() - 1)
            string += ",";
    }
    string.prepend("{");
    string.append("}");

    return string;
}

ArrayTableModel::ArrayTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    m_nodepidarr = QList<int>();
}

ArrayTableModel::ArrayTableModel(QList<int> nodepidarr, QObject *parent)
    : QAbstractTableModel(parent)
{
    m_nodepidarr = nodepidarr;
}

QVariant ArrayTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int column = index.column();

    if (role == Qt::DisplayRole)
    {
        for (int i = 0; i < m_nodepidarr.size(); i++) {
            QSqlQuery query("SELECT pid,St_AsLatLonText(geog::geometry),noteru "
                            "FROM data.vw_node WHERE pid=" + QString::number(m_nodepidarr.at(i)));
            while (query.next()) {
                QString geog = query.value(1).toString();
                QString noteru = query.value(2).toString();
                if (column == 0)
                    return geog;
                else if (column == 1)
                    return noteru;
            }
        }
    }

    return QVariant();
    return QAbstractTableModel::data(index, role);
}

QVariant ArrayTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (section < 0)
        return QVariant();

    if (orientation == Qt::Horizontal)
    {
        if (section > columnCount())
            return QVariant();

        if (role == Qt::DisplayRole)
        {
            switch (section) {
            case 0: return trUtf8("Координаты точки");
                break;
            case 1: return trUtf8("Примечание");
                break;
            }
        }
    }

    return QAbstractTableModel::headerData(section, orientation, role);
}

int ArrayTableModel::rowCount(const QModelIndex &/*parent*/) const
{
    return m_nodepidarr.size();
}

int ArrayTableModel::columnCount(const QModelIndex &/*parent*/) const
{
    return 2;
}

void ArrayTableModel::setNodepidarr(QList<int> nodepidarr)
{
    beginResetModel();
    m_nodepidarr = nodepidarr;
    endResetModel();
}
