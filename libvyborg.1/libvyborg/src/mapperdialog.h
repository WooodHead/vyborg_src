#ifndef VYBORGMAPPERDIALOG_H
#define VYBORGMAPPERDIALOG_H

#include <QDialog>

class VyborgMapperControlButtonBox;
class VyborgNavigationButtonBox;

QT_BEGIN_NAMESPACE
class QSqlRelationalTableModel;
class QDataWidgetMapper;
class QVBoxLayout;
QT_END_NAMESPACE

class VyborgMapperDialog : public QDialog
{
    Q_OBJECT

public:
    VyborgMapperDialog(QSqlRelationalTableModel *model, QWidget *parent = 0);

    void setCurrentRow(int row);
    void setDirty(bool dirty);
    bool isDirty() const;

    QDataWidgetMapper* mapper();
    QVBoxLayout* layout();

protected:
    virtual void createPrivateWidgets() = 0 Q_DECL_OVERRIDE;
    virtual void layoutPrivateWidgets() = 0 Q_DECL_OVERRIDE;
    virtual void updatePrivateWidgets() = 0 Q_DECL_OVERRIDE;

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
    QSqlRelationalTableModel *m_model;
    QDataWidgetMapper *m_mapper;

    bool m_dirty;
};

#endif // VYBORGMAPPERDIALOG_H
