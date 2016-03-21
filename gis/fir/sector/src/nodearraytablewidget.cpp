#include <QtWidgets>
#include <QtSql>

#include "nodearraytablewidget.h"

NodeArrayTableWidget::NodeArrayTableWidget(QWidget *parent)
    : QWidget(parent), m_nodepidarr(QList<int>())
{
    m_listW = new QListWidget;

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(m_listW);

    setLayout(mainLayout);
}

void NodeArrayTableWidget::setNodepidarr(const QString &nodepidarr)
{
    QList<int> l = fromString(nodepidarr);
    if (l != m_nodepidarr) {
        m_nodepidarr = l;
        emit nodepidarrChanged();

        m_listW->clear();

        for (int i = 0; i < m_nodepidarr.size(); i++) {
            QSqlQuery query("SELECT pid,St_AsLatLonText(geog::geometry),noteru "
                            "FROM data.vw_node WHERE pid=" + QString::number(m_nodepidarr.at(i)));
            query.exec();
            QListWidgetItem *item = new QListWidgetItem;
            item->setText(QString::number(i));
            m_listW->addItem(QString::number(i));
        }
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
