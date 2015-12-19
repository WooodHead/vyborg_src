#include <QtSql>
#include <QMessageBox>

#include "proxymodel.h"
#include "declarations.h"
#include "tablemodel.h"


ProxyModel::ProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{
}

#include <QDebug>
//bool ProxyModel::submitChanges()
//{
//    TableModel *model = static_cast<TableModel *>(sourceModel());
//    bool ret = model->submitAll();
//    if (ret == true) {
//        qDebug() << "Changes submitted";
//        return true;
//    } else {
//        model->revertAll();

//        QMessageBox msgBox;
//        msgBox.setWindowTitle(trUtf8("Информация"));
//        msgBox.setText(trUtf8("Ошибка сохранения базы данных:"));
//        msgBox.setInformativeText(model->lastError().text());
//        msgBox.setStandardButtons(QMessageBox::Close);
//        msgBox.exec();

//        return false;
//    }
//}

//QVariant ProxyModel::data(const QModelIndex &item, int role) const
//{
//    switch (item.column()) {
//    case AD_indxICAO:
//    case AD_indxIATA:
//        if (role == Qt::TextAlignmentRole) {
//            return Qt::AlignCenter;
//        }
//        break;
//    case AD_indxICAOru:
//        if (role == Qt::DisplayRole) {
//            QModelIndex indx = createIndex(item.row(), AD_indxICAO);
//            QString indxICAO = QSqlRelationalTableModel::data(indx, role).toString();
//            if (!indxICAO.isEmpty()) {
//                return lat2rus(indxICAO);
//            } else {
//                return QVariant();
//            }
//        } else if (role == Qt::ForegroundRole) {
//            QBrush brush(Qt::blue);
//            return brush;
//        } else if (role == Qt::TextAlignmentRole) {
//            return Qt::AlignCenter;
//        }
//        break;
//    case AD_indxIATAru:
//        if (role == Qt::DisplayRole) {
//            QModelIndex indx = createIndex(item.row(), AD_indxIATA);
//            QString indxIATA = QSqlRelationalTableModel::data(indx, role).toString();
//            if (!indxIATA.isEmpty()) {
//                return lat2rus(indxIATA);
//            } else {
//                return QVariant();
//            }
//        } else if (role == Qt::ForegroundRole) {
//            QBrush brush(Qt::blue);
//            return brush;
//        } else if (role == Qt::TextAlignmentRole) {
//            return Qt::AlignCenter;
//        }
//        break;
//    case AD_milIndx4ru:
//    case AD_milIndx2ru:
//        if (role == Qt::ForegroundRole) {
//            QBrush brush(Qt::red);
//            return brush;
//        } else if (role == Qt::TextAlignmentRole) {
//            return Qt::AlignCenter;
//        }
//        break;
//    case AD_cityRu:
//    case AD_ADru:
//        if (role == Qt::ForegroundRole) {
//            QBrush brush(Qt::blue);
//            return brush;
//        }
//        break;
//    case AD_milCSru:
//    case AD_milFRQ:
//    case AD_milBorder:
//    case AD_milBorderFLs:
//    case AD_milEnterExitPointRu:
//    case AD_milTerkasInfoReceiver:
//        if (role == Qt::ForegroundRole) {
//            QBrush brush(Qt::red);
//            return brush;
//        }
//        break;
//    default:
//        return QSqlRelationalTableModel::data(item, role);
//        break;
//    }

//    return QSqlRelationalTableModel::data(item, role);
//    return QVariant();
//}

//QVariant ProxyModel::headerData(int section, Qt::Orientation orientation, int role) const
//{
//    if (orientation == Qt::Horizontal) {
//        switch (section) {
//        case AD_indxICAO: {
//            if (role == Qt::DisplayRole) {
//                return QString("ICAO\nindex");
//            }
//            break;
//        }
//        case AD_indxICAOru:
//            if (role == Qt::DisplayRole) {
//                return QString("Индекс\nИКАО");
//            }
//            break;
//        case AD_indxIATA:
//            if (role == Qt::DisplayRole) {
//                return QString("IATA\nindex");
//            }
//            break;
//        case AD_indxIATAru:
//            if (role == Qt::DisplayRole) {
//                return QString("Индекс\nИАТА");
//            }
//            break;
//        case AD_milIndx4ru:
//            if (role == Qt::DisplayRole) {
//                return QString("Индекс\nгос.аэродрома");
//            } else if (role == Qt::ForegroundRole) {
//                QBrush brush(Qt::red);
//                return brush;
//            }
//            break;
//        case AD_milIndx2ru:
//            if (role == Qt::DisplayRole) {
//                return QString("2-х букв.\nкод TERKAS");
//            } else if (role == Qt::ForegroundRole) {
//                QBrush brush(Qt::red);
//                return brush;
//            }
//            break;
//        case AD_city:
//            if (role == Qt::DisplayRole) {
//                return QString("City Name");
//            }
//            break;
//        case AD_cityRu:
//            if (role == Qt::DisplayRole) {
//                return QString("Название города");
//            }
//            break;
//        case AD_AD:
//            if (role == Qt::DisplayRole) {
//                return QString("Aerodrome Name");
//            }
//            break;
//        case AD_ADru:
//            if (role == Qt::DisplayRole) {
//                return QString("Название аэродрома");
//            }
//            break;
//        case AD_milCSru:
//            if (role == Qt::DisplayRole) {
//                return QString("Воздушный позывной\nгос.органа УВД");
//            } else if (role == Qt::ForegroundRole) {
//                QBrush brush(Qt::red);
//                return brush;
//            }
//            break;
//        case AD_milFRQ:
//            if (role == Qt::DisplayRole) {
//                return QString("Рабочая частота\nгосударственного органа УВД");
//            }
//            break;
//        case AD_LAT:
//            if (role == Qt::DisplayRole) {
//                return QString("Широта");
//            }
//            break;
//        case AD_LON:
//            if (role == Qt::DisplayRole) {
//                return QString("Долгота");
//            }
//            break;
//        case AD_VAR:
//            if (role == Qt::DisplayRole) {
//                return QString("Магнитное\nсклонение");
//            }
//            break;
//        case AD_ELEV:
//            if (role == Qt::DisplayRole) {
//                return QString("Превышение\nаэродрома");
//            }
//            break;
//        case AD_TZ:
//            if (role == Qt::DisplayRole) {
//                return QString("Часовой\nпояс");
//            }
//            break;
//        case AD_milBorder:
//            if (role == Qt::DisplayRole) {
//                return QString("Географическая\nграница");
//            }
//            break;
//        case AD_milBorderFLs:
//            if (role == Qt::DisplayRole) {
//                return QString("Диапазоны\nэшелонов");
//            }
//            break;
//        case AD_milEnterExitPointRu:
//            if (role == Qt::DisplayRole) {
//                return QString("Точки входа/схода\nс трассы");
//            }
//            break;
//        case AD_milTerkasInfoReceiver:
//            if (role == Qt::DisplayRole) {
//                return QString("Сектор получения\nинформации TERKAS");
//            }
//            break;
//        case AD_note:
//            if (role == Qt::DisplayRole) {
//                return QString("Note");
//            }
//            break;
//        case AD_noteRu:
//            if (role == Qt::DisplayRole) {
//                return QString("Примечание");
//            }
//            break;
//        default:
//            return QVariant();
//            break;
//        }
//    }

//    return QVariant();
//}

//#include <QDebug>
//bool ProxyModel::submit()
//{
//    qDebug() << "SUBMIT MODEL";
//    TableModel *model = static_cast<TableModel *>(sourceModel());
//    bool ret = model->submitAll();
//    if (ret == true) {
//        qDebug() << "Changes submitted";
//        clear();
//        setSourceModel(model);
//        return true;
//    } else {
//        model->revertAll();

//        QMessageBox msgBox;
//        msgBox.setWindowTitle(trUtf8("Информация"));
//        msgBox.setText(trUtf8("Ошибка сохранения базы данных:"));
//        msgBox.setInformativeText(model->lastError().text());
//        msgBox.setStandardButtons(QMessageBox::Close);
//        msgBox.exec();

//        return false;
//    }
//}

//void ProxyModel::sort(int column, Qt::SortOrder order)
//{
//    TableModel *tableModel = static_cast<TableModel *>(sourceModel());
//    tableModel->sort(column, order);
//}
