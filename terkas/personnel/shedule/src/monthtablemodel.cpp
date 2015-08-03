#include <QDate>
#include <QtSql>

#include "monthtablemodel.h"


MonthTableModel::MonthTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    QDate date = QDate::currentDate();

    m_year  = date.year();
    m_month = date.month();

    m_shiftNum = 0;
    m_sectorsGroup = 0;

    createPersonIdList();
}

MonthTableModel::MonthTableModel(int year, int month, QObject *parent)
    : QAbstractTableModel(parent)
{
    m_year  = year;
    m_month = month;

    m_shiftNum = 0;
    m_sectorsGroup = 0;

    createPersonIdList();
}

int MonthTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    QDate date(m_year, m_month, 1);
    return date.daysInMonth();
}

int MonthTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return m_personIdList.size();
}

#include <QDebug>
QVariant MonthTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }


    int day = index.column() + 1;
    QDate date = QDate(m_year, m_month, day);

    int personId = m_personIdList.at(index.row());
    QString table("id" + QString::number(personId));


    QSqlQuery query;
    query.prepare("SELECT activity_id FROM "
                  + table + " " +
                  "WHERE :date BETWEEN startDate AND endDate");
    query.bindValue(":date", date);
    if (!query.exec()) {
        return QVariant();
    }
    int activity_id = -1;
    while (query.next()) {
        activity_id = query.value(0).toInt();
    }

    switch (role) {
    case Qt::DisplayRole: {
        query.clear();
        query.prepare("SELECT abbr FROM activity WHERE id=:id");
        query.bindValue(":id", activity_id);
        if (!query.exec()) {
            return QVariant();
        }
        QString abbr = "";
        while (query.next()) {
            abbr = query.value(0).toString();
        }
        return abbr;
        break;
    }
    case Qt::EditRole:
        return activity_id;
        break;
    case Qt::ToolTipRole:
        return QVariant();
        return "Not implemented yet";
        break;
    default:
        return QVariant();
        break;
    }
}

QVariant MonthTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal) {
        switch (role) {
        case Qt::DisplayRole:
            return QString::number(section + 1);
            break;
        }
    } else if (orientation == Qt::Vertical) {
        switch (role) {
        case Qt::EditRole:
            return QString::number(m_personIdList.at(section));
            break;
        case Qt::DisplayRole: {
            QSqlQuery query;
            query.prepare("SELECT surname, name, middleName "
                          "FROM person "
                          "WHERE personId=:personId");
            query.bindValue(":personId", m_personIdList.at(section));
            query.exec();
            while (query.next()) {
                QString surname = query.value(0).toString();
                QString name = query.value(1).toString().mid(0, 1);
                QString middleName = query.value(2).toString().mid(0, 1);
                QString fullName = QString(surname + " " + name + ". " + middleName + ".");
                return fullName;
            }
            break;
        }
        }
    }

    return QVariant();
}

QDate MonthTableModel::dateData(const QModelIndex &index) const
{
    int day = index.column() + 1;
    QDate date = QDate(m_year, m_month, day);
    return date;
}

int MonthTableModel::personIdData(const QModelIndex &index) const
{
    int row = index.row();
    int personId = headerData(row, Qt::Vertical, Qt::EditRole).toInt();
    return personId;
}

void MonthTableModel::setMonth(const int month)
{
    if (month != m_month) {
        beginResetModel();
        m_month = month;
        endResetModel();
    }
}

int MonthTableModel::month() const
{
    return m_month;
}

void MonthTableModel::setYear(const int year)
{
    if (year != m_year) {
        beginResetModel();
        m_year = year;
        endResetModel();
    }
}

int MonthTableModel::year() const
{
    return m_year;
}

void MonthTableModel::setShiftNum(const int shiftNum)
{
    qDebug() << "setting shiftNum";
    if (shiftNum != m_shiftNum) {
        beginResetModel();
        m_shiftNum = shiftNum;
        createPersonIdList();
        endResetModel();
    }
}

int MonthTableModel::shiftNum() const
{
    return m_shiftNum;
}

void MonthTableModel::setSectorsGroup(const int sectorsGroup)
{
    if (sectorsGroup != m_sectorsGroup) {
        beginResetModel();
        m_sectorsGroup = sectorsGroup;
        createPersonIdList();
        endResetModel();
    }
}

int MonthTableModel::sectorsGroup() const
{
    return m_sectorsGroup;
}

//void MonthTableModel::setPersonIdList(const QList<int> &personIdList)
//{
//    if (personIdList != m_personIdList) {
//        beginResetModel();
//        m_personIdList = personIdList;
//        endResetModel();
//    }
//}

//QList<int> MonthTableModel::personIdList() const
//{
//    return m_personIdList;
//}

QList<int> MonthTableModel::createPersonIdList()
{
    if (!m_personIdList.isEmpty()) {
        m_personIdList.clear();
    }

    QSqlQuery query;
    if (m_shiftNum > 0 && m_sectorsGroup > 0) {
        query.prepare("SELECT personId "
                      "FROM person "
                      "WHERE shiftNum=:shiftNum AND sectorsGroup_id=:sectorsGroup "
                      "ORDER BY surname");
        query.bindValue(":shiftNum", m_shiftNum);
        query.bindValue(":sectorsGroup", m_sectorsGroup);
    } else if (m_shiftNum > 0) {
        query.prepare("SELECT personId "
                      "FROM person "
                      "WHERE shiftNum=:shiftNum "
                      "ORDER BY surname");
        query.bindValue(":shiftNum", m_shiftNum);
    } else if (m_sectorsGroup > 0) {
        query.prepare("SELECT personId "
                      "FROM person "
                      "sectorsGroup_id=:sectorsGroup "
                      "ORDER BY surname");
        query.bindValue(":sectorsGroup", m_sectorsGroup);
    } else {
        query.prepare("SELECT personId "
                      "FROM person "
                      "ORDER BY surname");
    }
    query.exec();
    while (query.next()) {
        int personId = query.value(0).toInt();
        m_personIdList << personId;

//        QString surname = query.value(1).toString();
//        QString name = query.value(2).toString().mid(0, 1);
//        QString middleName = query.value(3).toString().mid(0, 1);
//        QString fullName = QString(surname + " " + name + ". " + middleName + ".");
//        namesList << fullName;
    }

    return m_personIdList;
}
