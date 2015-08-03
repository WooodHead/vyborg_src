#ifndef MONTHTABLEMODEL_H
#define MONTHTABLEMODEL_H

#include <QAbstractTableModel>
#include <QDate>
#include <QList>


class MonthTableModel : public QAbstractTableModel
{
    Q_OBJECT
    Q_PROPERTY(int month READ month WRITE setMonth)
    Q_PROPERTY(int year READ year WRITE setYear)
    Q_PROPERTY(int shiftNum READ shiftNum WRITE setShiftNum)
    Q_PROPERTY(int sectorsGroup READ sectorsGroup WRITE setSectorsGroup)

public:
    explicit MonthTableModel(QObject *parent = 0);
    explicit MonthTableModel(int year, int month, QObject *parent = 0);

    int columnCount(const QModelIndex &parent) const;
    int rowCount(const QModelIndex &parent) const;

    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    QDate dateData(const QModelIndex &index) const;
    int personIdData(const QModelIndex &index) const;

public slots:
    void setMonth(const int month);
    int month() const;
    void setYear(const int year);
    int year() const;
    void setShiftNum(const int shiftNum);
    int shiftNum() const;
    void setSectorsGroup(const int sectorsGroup);
    int sectorsGroup() const;

private:
    QList<int> createPersonIdList();

private:
    int m_year;
    int m_month;
    int m_shiftNum;
    int m_sectorsGroup;

    QList<int> m_personIdList;
};

#endif // MONTHTABLEMODEL_H
