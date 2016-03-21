#include <QtWidgets>
#include <QtSql>

#include "nodearraytablewidget.h"

NodeArrayTableWidget::NodeArrayTableWidget(QWidget *parent)
    : QWidget(parent)
{
    m_nodepidarr = QList<int>();
}

void NodeArrayTableWidget::setNodepidarr(const QString &nodepidarr)
{
    QList<int> l = fromString(nodepidarr);
    if (l != m_nodepidarr) {
        m_nodepidarr = l;
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
