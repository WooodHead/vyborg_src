#include <QBrush>
#include <QTime>

#include "querymodel.h"
#include "declarations.h"
#include "rus.h"


#include <QDebug>
QueryModel::QueryModel(QObject *parent)
    : QSqlQueryModel(parent)
{
//    setTable(MYSQL_TABLENAME);
//    QTime timer;
//    timer.start();
//    qDebug() << "Start";
//    select();
//    qDebug() << "End" << timer.elapsed();


//    setEditStrategy(QSqlQueryModel::OnManualSubmit);
    m_query = "SELECT * FROM AD ";
    QString queryString(m_query);
    setQuery(queryString);

        insertColumns(col_indxICAOru, 1);
        insertColumns(col_indxIATAru, 1);
}

Qt::ItemFlags QueryModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QSqlQueryModel::flags(index);
    flags = flags | Qt::ItemIsSelectable | Qt::ItemIsEditable;
    return flags;
}

QVariant QueryModel::data(const QModelIndex &item, int role) const
{
    switch (item.column()) {
    case col_indxICAO:
    case col_indxIATA:
        if (role == Qt::TextAlignmentRole) {
            return Qt::AlignCenter;
        }
        break;
    case col_indxICAOru:
        if (role == Qt::DisplayRole) {
            QModelIndex indx = createIndex(item.row(), col_indxICAO);
            QString indxICAO = QSqlQueryModel::data(indx, role).toString();
            if (!indxICAO.isEmpty()) {
                return lat2rus(indxICAO);
            } else {
                return QVariant();
            }
        } else if (role == Qt::ForegroundRole) {
            QBrush brush(Qt::blue);
            return brush;
        } else if (role == Qt::TextAlignmentRole) {
            return Qt::AlignCenter;
        }
        break;
    case col_indxIATAru:
        if (role == Qt::DisplayRole) {
            QModelIndex indx = createIndex(item.row(), col_indxIATA);
            QString indxIATA = QSqlQueryModel::data(indx, role).toString();
            if (!indxIATA.isEmpty()) {
                return lat2rus(indxIATA);
            } else {
                return QVariant();
            }
        } else if (role == Qt::ForegroundRole) {
            QBrush brush(Qt::blue);
            return brush;
        } else if (role == Qt::TextAlignmentRole) {
            return Qt::AlignCenter;
        }
        break;
    case col_milIndx4ru:
    case col_milIndx2ru:
        if (role == Qt::ForegroundRole) {
            QBrush brush(Qt::red);
            return brush;
        } else if (role == Qt::TextAlignmentRole) {
            return Qt::AlignCenter;
        }
        break;
    case col_cityRu:
    case col_ADru:
        if (role == Qt::ForegroundRole) {
            QBrush brush(Qt::blue);
            return brush;
        }
        break;
    case col_milCSru:
    case col_milFRQ:
    case col_milBorder:
    case col_milBorderFLs:
    case col_milEnterExitPointRu:
    case col_milTerkasInfoReceiver:
        if (role == Qt::ForegroundRole) {
            QBrush brush(Qt::red);
            return brush;
        }
        break;
    default:
        return QSqlQueryModel::data(item, role);
        break;
    }

    return QSqlQueryModel::data(item, role);
    return QVariant();
}

QVariant QueryModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal) {
        switch (section) {
        case col_indxICAO: {
            if (role == Qt::DisplayRole) {
                return QString("ICAO\nindex");
            }
            break;
        }
        case col_indxICAOru:
            if (role == Qt::DisplayRole) {
                return QString("Индекс\nИКАО");
            }
            break;
        case col_indxIATA:
            if (role == Qt::DisplayRole) {
                return QString("IATA\nindex");
            }
            break;
        case col_indxIATAru:
            if (role == Qt::DisplayRole) {
                return QString("Индекс\nИАТА");
            }
            break;
        case col_milIndx4ru:
            if (role == Qt::DisplayRole) {
                return QString("Индекс\nгос.аэродрома");
            } else if (role == Qt::ForegroundRole) {
                QBrush brush(Qt::red);
                return brush;
            }
            break;
        case col_milIndx2ru:
            if (role == Qt::DisplayRole) {
                return QString("2-х букв.\nкод TERKAS");
            } else if (role == Qt::ForegroundRole) {
                QBrush brush(Qt::red);
                return brush;
            }
            break;
        case col_city:
            if (role == Qt::DisplayRole) {
                return QString("City Name");
            }
            break;
        case col_cityRu:
            if (role == Qt::DisplayRole) {
                return QString("Название города");
            }
            break;
        case col_AD:
            if (role == Qt::DisplayRole) {
                return QString("Aerodrome Name");
            }
            break;
        case col_ADru:
            if (role == Qt::DisplayRole) {
                return QString("Название аэродрома");
            }
            break;
        case col_milCSru:
            if (role == Qt::DisplayRole) {
                return QString("Воздушный позывной\nгос.органа УВД");
            } else if (role == Qt::ForegroundRole) {
                QBrush brush(Qt::red);
                return brush;
            }
            break;
        case col_milFRQ:
            if (role == Qt::DisplayRole) {
                return QString("Рабочая частота\nгосударственного органа УВД");
            }
            break;
        case col_LAT:
            if (role == Qt::DisplayRole) {
                return QString("Широта");
            }
            break;
        case col_LON:
            if (role == Qt::DisplayRole) {
                return QString("Долгота");
            }
            break;
        case col_VAR:
            if (role == Qt::DisplayRole) {
                return QString("Магнитное\nсклонение");
            }
            break;
        case col_ELEV:
            if (role == Qt::DisplayRole) {
                return QString("Превышение\nаэродрома");
            }
            break;
        case col_TZ:
            if (role == Qt::DisplayRole) {
                return QString("Часовой\nпояс");
            }
            break;
        case col_milBorder:
            if (role == Qt::DisplayRole) {
                return QString("Географическая\nграница");
            }
            break;
        case col_milBorderFLs:
            if (role == Qt::DisplayRole) {
                return QString("Диапазоны\nэшелонов");
            }
            break;
        case col_milEnterExitPointRu:
            if (role == Qt::DisplayRole) {
                return QString("Точки входа/схода\nс трассы");
            }
            break;
        case col_milTerkasInfoReceiver:
            if (role == Qt::DisplayRole) {
                return QString("Сектор получения\nинформации TERKAS");
            }
            break;
        case col_note:
            if (role == Qt::DisplayRole) {
                return QString("Note");
            }
            break;
        case col_noteRu:
            if (role == Qt::DisplayRole) {
                return QString("Примечание");
            }
            break;
        default:
            return QVariant();
            break;
        }
    }

    return QVariant();
}

#include <QDebug>
bool QueryModel::setData(const QModelIndex &item, const QVariant &value, int role)
{
    qDebug() << "(" << item.row() << "," << item.column() << ")" << value.toString() << role;

    switch (item.column()) {
    case col_indxICAO:
    case col_indxIATA:
    case col_milIndx4ru:
    case col_milIndx2ru:
        if (value.toString().isEmpty()) {
//            qDebug() << "HERE 1";
//            emit dataChanged(item, item);
            return QSqlQueryModel::setData(item, QVariant(), role);
        } else {
//            qDebug() << "HERE 2";
//            emit dataChanged(item, item);
            return QSqlQueryModel::setData(item, value, role);
        }
//        emit dataChanged(item, item);
        break;
    case col_indxICAOru:
    case col_indxIATAru:
//        emit dataChanged(item, item);
        break;
    }

//    emit dataChanged(item, item);
    return QSqlQueryModel::setData(item, value, role);
}

int QueryModel::columnCount(const QModelIndex &parent) const
{
    return QSqlQueryModel::columnCount(parent) + 2;
}

//void QueryModel::setSort(int column, Qt::SortOrder order)
//{
//    QSqlRelationalQueryModel::setSort(column, order);

//    insertColumns(col_indxICAOru, 1);
//    insertColumns(col_indxIATAru, 1);
//}

//bool QueryModel::select()
//{
//    insertColumns(col_indxICAOru, 1);
//    insertColumns(col_indxIATAru, 1);

//    return QSqlRelationalQueryModel::select();
//}

void QueryModel::sort(int column, Qt::SortOrder order)
{
    QString sortString = " WHERE indxIATA IS NOT NULL ORDER BY indxIATA";
    refresh(m_query + sortString);
}

void QueryModel::refresh(const QString &query)
{
    setQuery(query);

    insertColumns(col_indxICAOru, 1);
    insertColumns(col_indxIATAru, 1);
}
