#include <QtWidgets>

#include "mapperdialog.h"
#include "declarations.h"
#include "imagewidget.h"


MapperDialog::MapperDialog(QSortFilterProxyModel *proxy, QWidget *parent)
    : VyborgMapperDialog(proxy, parent)
{
    createPrivateWidgets();
    layoutPrivateWidgets();
    updatePrivateWidgets();
}

void MapperDialog::createPrivateWidgets()
{
    flag = new ImageWidget;
    gerb = new ImageWidget;

    isoNumSpinBox = new QSpinBox;
    isoNumSpinBox->setMinimum(0);
    isoNumSpinBox->setMaximum(1000);

    nameEdit           = new QLineEdit;
    nameAbridgedEdit   = new QLineEdit;
    nameRuEdit         = new QLineEdit;
    nameAbridgedRuEdit = new QLineEdit;
    iso2Edit           = new QLineEdit;
    iso3Edit           = new QLineEdit;
    noteEdit           = new QLineEdit;
    noteRuEdit         = new QLineEdit;


    mapper_->addMapping(nameEdit,           country_name);
    mapper_->addMapping(nameAbridgedEdit,   country_nameAbridged);
    mapper_->addMapping(nameRuEdit,         country_nameRu);
    mapper_->addMapping(nameAbridgedRuEdit, country_nameAbridgedRu);
    mapper_->addMapping(isoNumSpinBox,      country_iso3166_num);
    mapper_->addMapping(iso2Edit,           country_iso3166_2);
    mapper_->addMapping(iso3Edit,           country_iso3166_3);
    mapper_->addMapping(noteEdit,           country_note);
    mapper_->addMapping(noteRuEdit,         country_noteRu);
//    mapper_->addMapping(flag,               country_nameAbridged, "fileName");
}

void MapperDialog::layoutPrivateWidgets()
{
    QGroupBox *flagGroupBox = new QGroupBox;
    QHBoxLayout *flagLayout = new QHBoxLayout;
    flagLayout->addWidget(flag);
    flagLayout->addWidget(gerb);
    flagGroupBox->setLayout(flagLayout);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(trUtf8("C&ountry"),                                      nameEdit);
    formLayout->addRow(trUtf8("Co&untry (abridged name)"),                      nameAbridgedEdit);
    formLayout->addRow(trUtf8("&Страна"),                                       nameRuEdit);
    formLayout->addRow(trUtf8("C&трана (сокращенное название)"),                nameAbridgedRuEdit);
    formLayout->addRow(trUtf8("ISO 3166-1 Numeric Code (UN M49 Numeric Code)"), isoNumSpinBox);
    formLayout->addRow(trUtf8("ISO 3166-1 ALPHA-2 Code"),                       iso2Edit);
    formLayout->addRow(trUtf8("ISO 3166-1 ALPHA-3 Code"),                       iso3Edit);
    formLayout->addRow(trUtf8("No&te"),                                         noteEdit);
    formLayout->addRow(trUtf8("&Примечание"),                                   noteRuEdit);

    QGridLayout *grid = new QGridLayout;
    grid->addWidget(flagGroupBox, 0, 0);
    grid->addLayout(formLayout, 1, 0);

    privateWidgetsLayout->addLayout(grid);
}

void MapperDialog::updatePrivateWidgets()
{
    if (dirty_ == true) {
        isoNumSpinBox->setReadOnly(false);

        flag->setEnabled(true);

        nameEdit->setReadOnly(false);
        nameAbridgedEdit->setReadOnly(false);
        nameRuEdit->setReadOnly(false);
        nameAbridgedRuEdit->setReadOnly(false);
        iso2Edit->setReadOnly(false);
        iso3Edit->setReadOnly(false);
        noteEdit->setReadOnly(false);
        noteRuEdit->setReadOnly(false);

        nameEdit->setFocus();
    } else {
        isoNumSpinBox->setReadOnly(true);

        flag->setEnabled(false);

        nameEdit->setReadOnly(true);
        nameAbridgedEdit->setReadOnly(true);
        nameRuEdit->setReadOnly(true);
        nameAbridgedRuEdit->setReadOnly(true);
        iso2Edit->setReadOnly(true);
        iso3Edit->setReadOnly(true);
        noteEdit->setReadOnly(true);
        noteRuEdit->setReadOnly(true);
    }
}
