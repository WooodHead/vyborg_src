#ifndef MAPPERDIALOG_H
#define MAPPERDIALOG_H

#include <vyborg.h>

class ShiftNum;
class QDateEdit;
class QComboBox;
class QLineEdit;
class QPlainTextEdit;
class QGridLayout;


class MapperDialog : public VyborgMapperDialog
{
    Q_OBJECT


public:
    MapperDialog(QSortFilterProxyModel *proxy, QWidget *parent = 0);

protected:
    virtual void createPrivateWidgets();
    virtual void layoutPrivateWidgets();
    virtual void updatePrivateWidgets();

private:
    QDateEdit *dateLineEdit;
    QComboBox *accComboBox;
    QComboBox *departmentComboBox;
    ShiftNum *shiftNum;
    QComboBox *sectorComboBox;
    QLineEdit *areaLineEdit;
    QComboBox *safetyClassificationComboBox;
    QComboBox *safetyTypeComboBox;
    QComboBox *sposTerkasComboBox;
    QComboBox *sposAlphaComboBox;
    QComboBox *TCAS1ComboBox;
    QComboBox *TCAS2ComboBox;
    QPlainTextEdit *causeTextEdit;
    QPlainTextEdit *factorTextEdit;
    QPlainTextEdit *detailsTextEdit;
    QGridLayout *gridLayout;
};

#endif // MAPPERDIALOG_H
