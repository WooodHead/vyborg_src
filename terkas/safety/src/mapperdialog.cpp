#include <QtWidgets>
#include <QtSql>

#include "mapperdialog.h"
#include "declarations.h"
#include "md_shiftnum.h"


MapperDialog::MapperDialog(QSortFilterProxyModel *proxy, QWidget *parent)
    : VyborgMapperDialog(proxy, parent)
{
    createPrivateWidgets();
    layoutPrivateWidgets();
    updatePrivateWidgets();
}

void MapperDialog::createPrivateWidgets()
{
    dateLineEdit           = new QDateEdit;
    dateLineEdit->setDisplayFormat("dd MMMM yyyy");
    accComboBox            = new QComboBox;
    departmentComboBox     = new QComboBox;
    shiftNum               = new ShiftNum;
    sectorComboBox         = new QComboBox;
    areaLineEdit           = new QLineEdit;
    safetyClassificationComboBox = new QComboBox;
    safetyTypeComboBox           = new QComboBox;
    sposTerkasComboBox     = new QComboBox;
    sposAlphaComboBox      = new QComboBox;
    TCAS1ComboBox          = new QComboBox;
    TCAS2ComboBox          = new QComboBox;
    causeTextEdit          = new QPlainTextEdit;
    factorTextEdit         = new QPlainTextEdit;
    detailsTextEdit        = new QPlainTextEdit;


    QIdentityProxyModel *identityProxy = static_cast<QIdentityProxyModel *>(proxy_->sourceModel());
    QSqlRelationalTableModel *model = static_cast<QSqlRelationalTableModel *>(identityProxy->sourceModel());


    QSqlTableModel *accComboBoxRelModel = model->relationModel(safety_ACC_id);
    accComboBox->setModel(accComboBoxRelModel);
    accComboBox->setModelColumn(accComboBoxRelModel->fieldIndex("name"));

    QSqlTableModel *departmentComboBoxRelModel = model->relationModel(safety_department_id);
    departmentComboBox->setModel(departmentComboBoxRelModel);
    departmentComboBox->setModelColumn(departmentComboBoxRelModel->fieldIndex("name"));

    QSqlTableModel *sectorComboBoxRelModel = model->relationModel(safety_sector_id);
    sectorComboBox->setModel(sectorComboBoxRelModel);
    sectorComboBox->setModelColumn(sectorComboBoxRelModel->fieldIndex("name"));

    QSqlTableModel *safetyClassificationComboBoxRelModel = model->relationModel(safety_safetyClassification_id);
    safetyClassificationComboBox->setModel(safetyClassificationComboBoxRelModel);
    safetyClassificationComboBox->setModelColumn(safetyClassificationComboBoxRelModel->fieldIndex("safetyClassification"));

    QSqlTableModel *safetyTypeComboBoxRelModel = model->relationModel(safety_safetyType_id);
    safetyTypeComboBox->setModel(safetyTypeComboBoxRelModel);
    safetyTypeComboBox->setModelColumn(safetyTypeComboBoxRelModel->fieldIndex("safetyType"));

    QSqlTableModel *sposTerkasComboBoxRelModel = model->relationModel(safety_sposTerkas_id);
    sposTerkasComboBox->setModel(sposTerkasComboBoxRelModel);
    sposTerkasComboBox->setModelColumn(sposTerkasComboBoxRelModel->fieldIndex("description"));

    QSqlTableModel *sposAlphaComboBoxRelModel = model->relationModel(safety_sposAlpha_id);
    sposAlphaComboBox->setModel(sposAlphaComboBoxRelModel);
    sposAlphaComboBox->setModelColumn(sposAlphaComboBoxRelModel->fieldIndex("description"));

    QSqlTableModel *TCAS1ComboBoxRelModel = model->relationModel(safety_TCAS1_id);
    TCAS1ComboBox->setModel(TCAS1ComboBoxRelModel);
    TCAS1ComboBox->setModelColumn(TCAS1ComboBoxRelModel->fieldIndex("description"));

    QSqlTableModel *TCAS2ComboBoxRelModel = model->relationModel(safety_TCAS2_id);
    TCAS2ComboBox->setModel(TCAS2ComboBoxRelModel);
    TCAS2ComboBox->setModelColumn(TCAS2ComboBoxRelModel->fieldIndex("description"));




    mapper_->addMapping(dateLineEdit,           safety_date);
    mapper_->addMapping(accComboBox,            safety_ACC_id);
    mapper_->addMapping(departmentComboBox,     safety_department_id);
    mapper_->addMapping(shiftNum,               safety_shiftNum);
    mapper_->addMapping(sectorComboBox,         safety_sector_id);
    mapper_->addMapping(areaLineEdit,           safety_area);
    mapper_->addMapping(safetyClassificationComboBox, safety_safetyClassification_id);
    mapper_->addMapping(safetyTypeComboBox,           safety_safetyType_id);
    mapper_->addMapping(sposTerkasComboBox,     safety_sposTerkas_id);
    mapper_->addMapping(sposAlphaComboBox,      safety_sposAlpha_id);
    mapper_->addMapping(TCAS1ComboBox,          safety_TCAS1_id);
    mapper_->addMapping(TCAS2ComboBox,          safety_TCAS2_id);
    mapper_->addMapping(causeTextEdit,          safety_cause);
    mapper_->addMapping(factorTextEdit,         safety_factor);
    mapper_->addMapping(detailsTextEdit,        safety_details);
}

void MapperDialog::layoutPrivateWidgets()
{
    QHBoxLayout *subLayout1 = new QHBoxLayout;
    subLayout1->addWidget(dateLineEdit);
    subLayout1->addStretch();

    QHBoxLayout *subLayout2 = new QHBoxLayout;
    subLayout2->addWidget(accComboBox);
    QLabel *label2 = new QLabel(trUtf8("Подразделение"));
    subLayout2->addWidget(label2);
    subLayout2->addWidget(departmentComboBox);
    QLabel *label3 = new QLabel(trUtf8("№ Смены"));
    subLayout2->addWidget(label3);
    subLayout2->addWidget(shiftNum);
    subLayout2->addStretch();

    QHBoxLayout *subLayout21 = new QHBoxLayout;
    subLayout21->addWidget(sectorComboBox);
    QLabel *label21_2 = new QLabel(trUtf8("Район события"));
    subLayout21->addWidget(label21_2);
    subLayout21->addWidget(areaLineEdit);
    subLayout21->addStretch();

    QHBoxLayout *subLayout3 = new QHBoxLayout;
    subLayout3->addWidget(safetyClassificationComboBox);
    QLabel *label4 = new QLabel(trUtf8("Вид события"));
    subLayout3->addWidget(label4);
    subLayout3->addWidget(safetyTypeComboBox);
    subLayout3->addStretch();

    QHBoxLayout *subLayout4 = new QHBoxLayout;
    QLabel *label4_1 = new QLabel(trUtf8("АС 'TERKAS'"));
    subLayout4->addWidget(label4_1);
    subLayout4->addWidget(sposTerkasComboBox);
    QLabel *label4_2 = new QLabel(trUtf8("КСА 'Альфа'"));
    subLayout4->addWidget(label4_2);
    subLayout4->addWidget(sposAlphaComboBox);
    QLabel *label4_3 = new QLabel(trUtf8("TCAS на 1 ВС"));
    subLayout4->addWidget(label4_3);
    subLayout4->addWidget(TCAS1ComboBox);
    QLabel *label4_4 = new QLabel(trUtf8("TCAS на 2 ВС"));
    subLayout4->addWidget(label4_4);
    subLayout4->addWidget(TCAS2ComboBox);
    subLayout4->addStretch();


    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(trUtf8("Дата на момент события"), subLayout1);
    formLayout->addRow(trUtf8("Центр УВД"),              subLayout2);
    formLayout->addRow(trUtf8("Сектор УВД"),             subLayout21);
    formLayout->addRow(trUtf8("Классификация события"),  subLayout3);
    formLayout->addRow(trUtf8("Сигнализация"),           subLayout4);
    formLayout->addRow(trUtf8("Причины события"),        causeTextEdit);
    formLayout->addRow(trUtf8("Факторы события"),        factorTextEdit);
    formLayout->addRow(trUtf8("Подробности"),            detailsTextEdit);


    privateWidgetsLayout->addLayout(formLayout);
}

void MapperDialog::updatePrivateWidgets()
{
    if (dirty_ == true)
    {
        dateLineEdit->setReadOnly(false);
        accComboBox->setEditable(true);
        departmentComboBox->setEditable(true);
        shiftNum->setReadOnly(false);
        areaLineEdit->setReadOnly(false);
        safetyClassificationComboBox->setEditable(true);
        safetyTypeComboBox->setEditable(true);
        sposTerkasComboBox->setEditable(true);
        sposAlphaComboBox->setEditable(true);
        TCAS1ComboBox->setEditable(true);
        TCAS2ComboBox->setEditable(true);
        causeTextEdit->setReadOnly(false);
        factorTextEdit->setReadOnly(false);
        detailsTextEdit->setReadOnly(false);

        dateLineEdit->setFocus();
    }
    else
    {
        dateLineEdit->setReadOnly(true);
        accComboBox->setEditable(false);
        departmentComboBox->setEditable(false);
        shiftNum->setReadOnly(true);
        areaLineEdit->setReadOnly(true);
        safetyClassificationComboBox->setEditable(false);
        safetyTypeComboBox->setEditable(false);
        sposTerkasComboBox->setEditable(false);
        sposAlphaComboBox->setEditable(false);
        TCAS1ComboBox->setEditable(false);
        TCAS2ComboBox->setEditable(false);
        causeTextEdit->setReadOnly(true);
        factorTextEdit->setReadOnly(true);
        detailsTextEdit->setReadOnly(true);
    }
}
