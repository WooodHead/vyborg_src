#include <QtWidgets>
#include <QtSql>

#include "nodearraytablewidget.h"

NodeArrayTableWidget::NodeArrayTableWidget(QWidget *parent)
    : QWidget(parent),
      m_nodepidarr(QList<int>())
{
    m_model = new ArrayTableModel;
    m_model->setNodepidarr(m_nodepidarr);
//    m_model->setHorizontalHeaderItem(0, new QStandardItem(trUtf8("Координаты точки")));
//    m_model->setHorizontalHeaderItem(1, new QStandardItem(trUtf8("Примечание")));

    m_view = new QTableView;
    m_view->setModel(m_model);
    m_view->resizeColumnsToContents();

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(m_view);

    setLayout(mainLayout);
}

void NodeArrayTableWidget::setNodepidarr(const QString &nodepidarr)
{
    QList<int> l = fromString(nodepidarr);
    if (l != m_nodepidarr) {
        m_nodepidarr = l;
        m_model->setNodepidarr(m_nodepidarr);

        emit nodepidarrChanged();


//        m_model->removeRows(0, m_model->rowCount()); // Clear the model

//        for (int i = 0; i < m_nodepidarr.size(); i++) {
//            QSqlQuery query("SELECT pid,St_AsLatLonText(geog::geometry),noteru "
//                            "FROM data.vw_node WHERE pid=" + QString::number(m_nodepidarr.at(i)));
//            while (query.next()) {
//                QString geog = query.value(1).toString();
//                QString noteru = query.value(2).toString();

//                QStandardItem *itemGeog = new QStandardItem(geog);
//                QStandardItem *itemNoteru = new QStandardItem(noteru);
//                m_model->setItem(i, 0, itemGeog);
//                m_model->setItem(i, 1, itemNoteru);
//            }
//        }
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

    int row = index.row();

    if (role == Qt::DisplayRole)
        return m_nodepidarr.at(row);
    else
        return QVariant();
}

QVariant ArrayTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (section < 0 || section > columnCount())
        return QVariant();

    if (orientation == Qt::Horizontal) {
        if (role == Qt::DisplayRole)
        {
//            if (section == 0)
//                return "N";
            if (section == 0)
                return trUtf8("Координаты точки");
            else if (section == 1)
                return trUtf8("Примечание");
        }
    }

    return QAbstractTableModel::headerData(section, orientation, role);
}

int ArrayTableModel::rowCount(const QModelIndex &parent) const
{
    return m_nodepidarr.size();
}

int ArrayTableModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

void ArrayTableModel::setNodepidarr(QList<int> nodepidarr)
{
    beginResetModel();
    m_nodepidarr = nodepidarr;
    endResetModel();
}
