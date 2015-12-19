#include <QBrush>
#include <QTime>

#include "tablemodel.h"
#include "declarations.h"
#include "rus.h"


TableModel::TableModel(QObject *parent)
    : QSqlRelationalTableModel(parent)
{
    setTable(MYSQL_TABLENAME);
    select();
}

QVariant TableModel::data(const QModelIndex &item, int role) const
{
    if (!item.isValid())
        return QVariant();

    if (item.column() > ColumnsNumber)
        return QVariant();

    switch (item.column()) {
    case col_indxICAO:
        if (role == Qt::DisplayRole) {
            QModelIndex indx = index(item.row(), AD_indxICAO);
            QString indxICAO = QSqlRelationalTableModel::data(indx, role).toString();
            if (!indxICAO.isEmpty()) {
                return indxICAO;
            } else
                return QVariant();
        } else if (role == Qt::TextAlignmentRole)
            return Qt::AlignCenter;
        break;
    case col_indxICAOru:
        if (role == Qt::DisplayRole) {
            QModelIndex indx = index(item.row(), AD_indxICAO);
            QString indxICAO = QSqlRelationalTableModel::data(indx, role).toString();
            if (!indxICAO.isEmpty()) {
                return lat2rus(indxICAO);
            } else
                return QVariant();
        } else if (role == Qt::ForegroundRole) {
            QBrush brush(Qt::blue);
            return brush;
        } else if (role == Qt::TextAlignmentRole)
            return Qt::AlignCenter;
        break;
    case col_indxIATA:
        if (role == Qt::DisplayRole) {
            QModelIndex indx = index(item.row(), AD_indxIATA);
            QString indxIATA = QSqlRelationalTableModel::data(indx, role).toString();
            if (!indxIATA.isEmpty()) {
                return indxIATA;
            } else
                return QVariant();
        } else if (role == Qt::TextAlignmentRole)
            return Qt::AlignCenter;
        break;
    case col_indxIATAru:
        if (role == Qt::DisplayRole) {
            QModelIndex indx = index(item.row(), AD_indxIATA);
            QString indxIATA = QSqlRelationalTableModel::data(indx, role).toString();
            if (!indxIATA.isEmpty()) {
                return lat2rus(indxIATA);
            } else
                return QVariant();
        } else if (role == Qt::ForegroundRole) {
            QBrush brush(Qt::blue);
            return brush;
        } else if (role == Qt::TextAlignmentRole)
            return Qt::AlignCenter;
        break;
    case col_milIndx4ru:
        if (role == Qt::DisplayRole) {
            QModelIndex indx = index(item.row(), AD_milIndx4ru);
            QString milIndx4ru = QSqlRelationalTableModel::data(indx, role).toString();
            if (!milIndx4ru.isEmpty())
                return milIndx4ru;
            else
                return QVariant();
        } else if (role == Qt::ForegroundRole) {
            QBrush brush(Qt::red);
            return brush;
        } else if (role == Qt::TextAlignmentRole)
            return Qt::AlignCenter;
        break;
    case col_milIndx2ru:
        if (role == Qt::DisplayRole) {
            QModelIndex indx = index(item.row(), AD_milIndx2ru);
            QString milIndx2ru = QSqlRelationalTableModel::data(indx, role).toString();
            if (!milIndx2ru.isEmpty())
                return milIndx2ru;
            else
                return QVariant();
        } else if (role == Qt::ForegroundRole) {
            QBrush brush(Qt::red);
            return brush;
        } else if (role == Qt::TextAlignmentRole)
            return Qt::AlignCenter;
        break;
    case col_city:
        if (role == Qt::DisplayRole) {
            QModelIndex indx = index(item.row(), AD_city);
            QString city = QSqlRelationalTableModel::data(indx, role).toString();
            if (!city.isEmpty())
                return city;
            else
                return QVariant();
        } else if (role == Qt::ForegroundRole) {
            QBrush brush(Qt::blue);
            return brush;
        }
        break;
    case col_cityRu:
        if (role == Qt::DisplayRole) {
            QModelIndex indx = index(item.row(), AD_cityRu);
            QString cityRu = QSqlRelationalTableModel::data(indx, role).toString();
            if (!cityRu.isEmpty())
                return cityRu;
            else
                return QVariant();
        } else if (role == Qt::ForegroundRole) {
            QBrush brush(Qt::blue);
            return brush;
        }
        break;
    case col_AD:
        if (role == Qt::DisplayRole) {
            QModelIndex indx = index(item.row(), AD_AD);
            QString AD = QSqlRelationalTableModel::data(indx, role).toString();
            if (!AD.isEmpty())
                return AD;
            else
                return QVariant();
        } else if (role == Qt::ForegroundRole) {
            QBrush brush(Qt::blue);
            return brush;
        }
        break;
    case col_ADru:
        if (role == Qt::DisplayRole) {
            QModelIndex indx = index(item.row(), AD_ADru);
            QString ADru = QSqlRelationalTableModel::data(indx, role).toString();
            if (!ADru.isEmpty())
                return ADru;
            else
                return QVariant();
        } else if (role == Qt::ForegroundRole) {
            QBrush brush(Qt::blue);
            return brush;
        }
        break;
    case col_milCSru:
        if (role == Qt::DisplayRole) {
            QModelIndex indx = index(item.row(), AD_milCSru);
            QString milCSru = QSqlRelationalTableModel::data(indx, role).toString();
            if (!milCSru.isEmpty())
                return milCSru;
            else
                return QVariant();
        } else if (role == Qt::ForegroundRole) {
            QBrush brush(Qt::red);
            return brush;
        }
        break;
    case col_milFRQ:
        if (role == Qt::DisplayRole) {
            QModelIndex indx = index(item.row(), AD_milFRQ);
            QString milFRQ = QSqlRelationalTableModel::data(indx, role).toString();
            if (!milFRQ.isEmpty())
                return milFRQ;
            else
                return QVariant();
        } else if (role == Qt::ForegroundRole) {
            QBrush brush(Qt::red);
            return brush;
        }
        break;
    case col_milBorder:
        if (role == Qt::DisplayRole) {
            QModelIndex indx = index(item.row(), AD_milBorder);
            QString milBorder = QSqlRelationalTableModel::data(indx, role).toString();
            if (!milBorder.isEmpty())
                return milBorder;
            else
                return QVariant();
        } else if (role == Qt::ForegroundRole) {
            QBrush brush(Qt::red);
            return brush;
        }
        break;
    case col_milBorderFLs:
        if (role == Qt::DisplayRole) {
            QModelIndex indx = index(item.row(), AD_milBorderFLs);
            QString milBorderFLs = QSqlRelationalTableModel::data(indx, role).toString();
            if (!milBorderFLs.isEmpty())
                return milBorderFLs;
            else
                return QVariant();
        } else if (role == Qt::ForegroundRole) {
            QBrush brush(Qt::red);
            return brush;
        }
        break;
    case col_milEnterExitPointRu:
        if (role == Qt::DisplayRole) {
            QModelIndex indx = index(item.row(), AD_milEnterExitPointRu);
            QString milEnterExitPointRu =
                    QSqlRelationalTableModel::data(indx, role).toString();
            if (!milEnterExitPointRu.isEmpty())
                return milEnterExitPointRu;
            else
                return QVariant();
        } else if (role == Qt::ForegroundRole) {
            QBrush brush(Qt::red);
            return brush;
        }
        break;
    case col_milTerkasInfoReceiver:
        if (role == Qt::DisplayRole) {
            QModelIndex indx = index(item.row(), AD_milTerkasInfoReceiver);
            QString milTerkasInfoReceiver =
                    QSqlRelationalTableModel::data(indx, role).toString();
            if (!milTerkasInfoReceiver.isEmpty())
                return milTerkasInfoReceiver;
            else
                return QVariant();
        } else if (role == Qt::ForegroundRole) {
            QBrush brush(Qt::red);
            return brush;
        }
        break;
    default:
        return QSqlRelationalTableModel::data(item, role);
        break;
    }

    return QSqlRelationalTableModel::data(item, role);
    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
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
                return QString("Индекс\nгос.а-ма");
            } else if (role == Qt::ForegroundRole) {
                QBrush brush(Qt::red);
                return brush;
            }
            break;
        case col_milIndx2ru:
            if (role == Qt::DisplayRole) {
                return QString("Индекс\nTERKAS");
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
//bool TableModel::setData(const QModelIndex &item, const QVariant &value, int role)
//{
//    qDebug() << "(" << item.row() << "," << item.column() << ")"
//             << value.toString()
//             << role;

//    switch (item.column()) {
//    case col_indxICAO:
//    case col_indxIATA:
//    case col_milIndx4ru:
//    case col_milIndx2ru:
//        if (value.toString().isEmpty()) {
////            emit dataChanged(item, item);
//            return QSqlRelationalTableModel::setData(item, QVariant(), role);
//        } else {
////            emit dataChanged(item, item);
//            return QSqlRelationalTableModel::setData(item, value, role);
//        }
//        break;
//    case col_indxICAOru:
//    case col_indxIATAru:
////        emit dataChanged(item, item);
//        break;
//    }

////    emit dataChanged(item, item);
//    return QSqlRelationalTableModel::setData(item, value, role);
//}

//void TableModel::sort(int column, Qt::SortOrder order)
//{
//    QSqlRelationalTableModel::sort(column, order);
//}

int TableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return ColumnsNumber;
}
