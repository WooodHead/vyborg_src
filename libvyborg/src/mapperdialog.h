#ifndef VYBORGMAPPERDIALOG_H
#define VYBORGMAPPERDIALOG_H

#include <QDialog>

class VyborgMapperControlButtonBox;
class VyborgNavigationButtonBox;

QT_BEGIN_NAMESPACE
class QSqlTableModel;
class QDataWidgetMapper;
class QVBoxLayout;
QT_END_NAMESPACE

class VyborgMapperDialog : public QDialog
{
    Q_OBJECT

public:
    VyborgMapperDialog(QSqlTableModel *model, QWidget *parent = 0);

    void setCurrentRow(int row);

    void setDirty(bool dirty);
    bool isDirty() const;

    QDataWidgetMapper* mapper();
    QVBoxLayout* layout();

protected:
//    virtual void createPrivateWidgets() = 0 Q_DECL_OVERRIDE;
//    virtual void layoutPrivateWidgets() = 0 Q_DECL_OVERRIDE;
//    virtual void updatePrivateWidgets() = 0 Q_DECL_OVERRIDE;
    virtual void createPrivateWidgets() = 0;
    virtual void layoutPrivateWidgets() = 0;
    virtual void updatePrivateWidgets() = 0;

public slots:
    void add();
    void remove();
    void edit();
    void submit();
    void revert();
    void close();

private:
    bool dirty() const;
    void updateOuterWidgets();

private:
    VyborgMapperControlButtonBox *m_controlButtonBox;
    VyborgNavigationButtonBox *m_navButtonBox;
    QVBoxLayout *m_privateWidgetsLayout;
    QSqlTableModel *m_model;
    QDataWidgetMapper *m_mapper;

    bool m_dirty;
};

#endif // VYBORGMAPPERDIALOG_H
