#include <QtWidgets>
#include <QtSql>

#include <QAbstractItemModel>

#include "nodearraytablewidget.h"

NodeArrayTableWidget::NodeArrayTableWidget(QWidget *parent)
    : QWidget(parent),
      m_nodepidarr(QList<int>())
{
    m_model = new ArrayTableModel(m_nodepidarr, this);

    m_view = new QTableView;
    m_view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_view->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_view->setSelectionMode(QAbstractItemView::SingleSelection);
    m_view->setShowGrid(true);
    m_view->setAlternatingRowColors(true);
    m_view->verticalHeader()->setVisible(false);
    m_view->setModel(m_model);
    m_view->resizeColumnsToContents();


    m_addButton = new QPushButton(trUtf8("Add node"));
    m_removeButton = new QPushButton(trUtf8("Remove node"));

    connect(m_addButton, SIGNAL(clicked(bool)),
            this, SLOT(addButtonClicked()));
    connect(m_removeButton, SIGNAL(clicked(bool)),
            this, SLOT(removeButtonClicked()));


    QVBoxLayout *buttonLayout = new QVBoxLayout;
    buttonLayout->addWidget(m_addButton);
    buttonLayout->addWidget(m_removeButton);
    buttonLayout->addStretch();


    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(m_view);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
}

void NodeArrayTableWidget::setNodepidarr(const QString &nodepidarr)
{
    // Add here check for correct array string

    QList<int> l = fromString(nodepidarr);
    if (l != m_nodepidarr) {
        m_nodepidarr = l;
        m_model->setNodepidarr(m_nodepidarr);

        m_view->selectRow(0);

        emit nodepidarrChanged();
    }
}

QString NodeArrayTableWidget::nodepidarr() const
{
    QString nodepidarr = toString(m_nodepidarr);
    return nodepidarr;
}

void NodeArrayTableWidget::setEnabled(bool state)
{
    if (state == true) {
        m_addButton->setEnabled(true);
        m_removeButton->setEnabled(true);
    } else {
        m_addButton->setEnabled(false);
        m_removeButton->setEnabled(false);
    }
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

void NodeArrayTableWidget::addButtonClicked()
{
    bool ok;
    int val  = QInputDialog::getInt(this,
                                    trUtf8("Введите число"),
                                    trUtf8("Номер node:"),
                                    -1, 0, 100, 1,
                                    &ok);

    if (ok) {
        QModelIndex indx = m_view->currentIndex();
        int row = indx.row();
        m_model->insertRows(row, 1);
        m_model->setData(indx, val);

        m_nodepidarr = m_model->nodepidarr();
    }
}

void NodeArrayTableWidget::removeButtonClicked()
{
    QModelIndex indx = m_view->currentIndex();
    int row = indx.row();
    m_model->removeRows(row, 1);
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

Qt::ItemFlags ArrayTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

QVariant ArrayTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= m_nodepidarr.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        int row = index.row();
        int column = index.column();

        QSqlQuery query("SELECT pid,St_AsLatLonText(geog::geometry),noteru "
                        "FROM data.vw_node WHERE pid=" + QString::number(m_nodepidarr.at(row)));
        while (query.next()) {
            QString geog = query.value(1).toString();
            QString noteru = query.value(2).toString();
            if (column == 0)
                return geog;
            else if (column == 1)
                return noteru;
        }
    }

    return QVariant();
}

QVariant ArrayTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (section < 0)
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
    {
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
    }

    return QVariant();
//    return QAbstractTableModel::headerData(section, orientation, role);
}

bool ArrayTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        int i = index.row();
        m_nodepidarr.replace(i, value.toInt());
        emit dataChanged(index, index);
        return true;
    }

    return false;
}

int ArrayTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_nodepidarr.size();
}

int ArrayTableModel::columnCount(const QModelIndex &/*parent*/) const
{
    return 2;
}

void ArrayTableModel::setNodepidarr(QList<int> nodepidarr)
{
    if (nodepidarr != m_nodepidarr) {
        beginResetModel();
        m_nodepidarr = nodepidarr;
        endResetModel();
    }
}

QList<int> ArrayTableModel::nodepidarr() const
{
    return m_nodepidarr;
}

bool ArrayTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    if (row < 0 || row > m_nodepidarr.size())
        return false;

    beginInsertRows(parent, row, row + count - 1);

    for (int i = 0; i < count; i++)
        m_nodepidarr.insert(row + i, -1); // Inserting value of -1 into array

    endInsertRows();

    emit layoutChanged();
    return true;
}

bool ArrayTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if (row < 0 || row > m_nodepidarr.size())
        return false;

    beginRemoveRows(parent, row, row + count - 1);

    for (int i = 0; i < count; ++i)
        m_nodepidarr.removeAt(row + i);

    endRemoveRows();

    emit layoutChanged();
    return true;
}
