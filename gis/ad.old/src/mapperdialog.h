#ifndef MAPPERDIALOG_H
#define MAPPERDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QDataWidgetMapper;
class QTabWidget;
class QLineEdit;
QT_END_NAMESPACE
class ProxyModel;


class MapperDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MapperDialog(QWidget *parent = 0);

    void setProxyModel(ProxyModel *proxyModel);
    void setCurrentIndex(const QModelIndex &index);

private slots:
    void submit();

private:
    QWidget* generalPage();
    QWidget* militaryPage();

    QDataWidgetMapper *m_mapper;
    QTabWidget *m_tabWidget;
    QLineEdit *m_ICAOlineEdit;
    QLineEdit *m_milICAOlineEdit;
    QLineEdit *m_IATAlineEdit;
    QLineEdit *m_mil2letterCodeRuLineEdit;
    QLineEdit *m_cityLineEdit;
    QLineEdit *m_cityRuLineEdit;
    QLineEdit *m_ADlineEdit;
    QLineEdit *m_ADruLineEdit;
    QLineEdit *m_milCSruLineEdit;
    QLineEdit *m_milFRQlineEdit;
    QLineEdit *m_LATlineEdit;
    QLineEdit *m_LONlineEdit;
    QLineEdit *m_VARlineEdit;
    QLineEdit *m_ELEVlineEdit;
    QLineEdit *m_timeZoneLineEdit;
    QLineEdit *m_milBorderLineEdit;
    QLineEdit *m_milBorderFLsLineEdit;
    QLineEdit *m_milEnterExitPointRuLineEdit;
    QLineEdit *m_milTerkasInfoReceiverLineEdit;
    QLineEdit *m_noteLineEdit;
    QLineEdit *m_noteRuLineEdit;
};

#endif // MAPPERDIALOG_H
