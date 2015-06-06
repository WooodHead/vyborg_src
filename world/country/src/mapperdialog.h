#ifndef MAPPERDIALOG_H
#define MAPPERDIALOG_H

#include <vyborg.h>

class QLineEdit;
class QSpinBox;
class ImageWidget;


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
    QLineEdit *nameEdit;
    QLineEdit *nameAbridgedEdit;
    QLineEdit *nameRuEdit;
    QLineEdit *nameAbridgedRuEdit;
    QLineEdit *iso2Edit;
    QLineEdit *iso3Edit;
    QLineEdit *noteEdit;
    QLineEdit *noteRuEdit;
    QSpinBox *isoNumSpinBox;
    QPushButton *firstButton;
    QPushButton *previousButton;
    QPushButton *nextButton;
    QPushButton *lastButton;
    QPushButton *editButton;
    QPushButton *submitButton;
    QPushButton *discardButton;
    QPushButton *closeButton;
    ImageWidget *flag;
    ImageWidget *gerb;
};

#endif // MAPPERDIALOG_H
