#ifndef SHIFTNUMSECTORSGROUPPICKERWIDGET_H
#define SHIFTNUMSECTORSGROUPPICKERWIDGET_H

#include <QWidget>

namespace Ui {
class ShiftNumSectorsGroupPickerWidget;
}


class ShiftNumSectorsGroupPickerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ShiftNumSectorsGroupPickerWidget(QWidget *parent = 0);
    ~ShiftNumSectorsGroupPickerWidget();

    void setShiftNum(const int shiftNum);
    int shiftNum() const;
    void setSectorsGroup(const int sectorsGroup);
    int sectorsGroup() const;

signals:
    void shiftNumChanged(int shiftNum);
    void sectorsGroupChanged(int sectorsGroup);

private slots:
    void on_shiftNumComboBox_currentIndexChanged(int index);

    void on_sectorsGroupComboBox_currentIndexChanged(int index);

private:
    Ui::ShiftNumSectorsGroupPickerWidget *ui;

    int m_shiftNum;
    int m_sectorsGroup;
};

#endif // SHIFTNUMSECTORSGROUPPICKERWIDGET_H
