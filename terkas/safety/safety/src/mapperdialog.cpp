#include <QtWidgets>

#include "mapperdialog.h"
#include "declarations.h"
#include "mapperdelegate.h"

MapperDialog::MapperDialog(QSqlTableModel *model, QWidget *parent)
    : VyborgMapperDialog(model, parent)
{
    createPrivateWidgets();
    layoutPrivateWidgets();
    updatePrivateWidgets();
}

void MapperDialog::createPrivateWidgets()
{
    m_dateEdit            = new QDateEdit;
    m_dateEdit->setDisplayFormat("yyyy MMMM dd");

    m_shiftEdit = new QLineEdit;
    m_locationEdit = new QLineEdit;
    m_causeEdit = new QTextEdit;
    m_factorEdit = new QTextEdit;
    m_detailsEdit = new QTextEdit;
    m_sectorEdit = new QLineEdit;
    m_accCombo = new QComboBox;
    m_classificationCombo = new QComboBox;
    m_typeCombo = new QComboBox;
    m_terkasCombo = new QComboBox;
    m_alphaCombo = new QComboBox;
    m_tcas1Combo = new QComboBox;
    m_tcas2Combo = new QComboBox;

    QDataWidgetMapper* m_mapper = mapper();
    m_mapper->addMapping(m_dateEdit,            safety_date);
    m_mapper->addMapping(m_shiftEdit,           safety_shift);
    m_mapper->addMapping(m_locationEdit,        safety_location);
    m_mapper->addMapping(m_causeEdit,           safety_cause);
    m_mapper->addMapping(m_factorEdit,          safety_factor);
    m_mapper->addMapping(m_detailsEdit,         safety_details);
    m_mapper->addMapping(m_sectorEdit,          safety_sector_id);
    m_mapper->addMapping(m_accCombo,            safety_acc);
    m_mapper->addMapping(m_classificationCombo, safety_classification);
    m_mapper->addMapping(m_typeCombo,           safety_type);
    m_mapper->addMapping(m_terkasCombo,         safety_terkas);
    m_mapper->addMapping(m_alphaCombo,          safety_alpha);
    m_mapper->addMapping(m_tcas1Combo,          safety_tcas1);
    m_mapper->addMapping(m_tcas2Combo,          safety_tcas2);
    m_mapper->setItemDelegate(new MapperDelegate);
}

void MapperDialog::layoutPrivateWidgets()
{
    QLabel *dateLabel = new QLabel(trUtf8("Дата события:"));
    dateLabel->setBuddy(m_dateEdit);

    QLabel *shiftLabel = new QLabel(trUtf8("Shift:"));
    shiftLabel->setBuddy(m_shiftEdit);

    QLabel *locationLabel = new QLabel(trUtf8("Location:"));
    locationLabel->setBuddy(m_locationEdit);

    QLabel *causeLabel = new QLabel(trUtf8("Cause:"));
    causeLabel->setBuddy(m_causeEdit);

    QLabel *factorLabel = new QLabel(trUtf8("Factor:"));
    factorLabel->setBuddy(m_factorEdit);

    QLabel *detailsLabel = new QLabel(trUtf8("Details:"));
    detailsLabel->setBuddy(m_detailsEdit);

    QLabel *sectorLabel = new QLabel(trUtf8("Sector:"));
    sectorLabel->setBuddy(m_sectorEdit);

    QLabel *accLabel = new QLabel(trUtf8("ACC:"));
    accLabel->setBuddy(m_accCombo);

    QLabel *classificationLabel = new QLabel(trUtf8("Classification:"));
    classificationLabel->setBuddy(m_classificationCombo);

    QLabel *typeLabel = new QLabel(trUtf8("Type:"));
    typeLabel->setBuddy(m_typeCombo);

    QLabel *terkasLabel = new QLabel(trUtf8("СПОС TERKAS:"));
    terkasLabel->setBuddy(m_terkasCombo);

    QLabel *alphaLabel = new QLabel(trUtf8("СПОС ALPHA:"));
    alphaLabel->setBuddy(m_alphaCombo);

    QLabel *tcas1Label = new QLabel(trUtf8("TCAS 1 ВС:"));
    tcas1Label->setBuddy(m_tcas1Combo);

    QLabel *tcas2Label = new QLabel(trUtf8("TCAS 2 ВС:"));
    tcas2Label->setBuddy(m_tcas2Combo);


    QHBoxLayout *dateLocationLayout = new QHBoxLayout;
    dateLocationLayout->addWidget(dateLabel);
    dateLocationLayout->addWidget(m_dateEdit);
    dateLocationLayout->addWidget(locationLabel);
    dateLocationLayout->addWidget(m_locationEdit);

    QHBoxLayout *accSectorShiftLayout = new QHBoxLayout;
    accSectorShiftLayout->addWidget(accLabel);
    accSectorShiftLayout->addWidget(m_accCombo);
    accSectorShiftLayout->addWidget(sectorLabel);
    accSectorShiftLayout->addWidget(m_sectorEdit);
    accSectorShiftLayout->addWidget(shiftLabel);
    accSectorShiftLayout->addWidget(m_shiftEdit);

    QHBoxLayout *atcSposLayout = new QHBoxLayout;
    atcSposLayout->addWidget(terkasLabel);
    atcSposLayout->addWidget(m_terkasCombo);
    atcSposLayout->addWidget(alphaLabel);
    atcSposLayout->addWidget(m_alphaCombo);

    QHBoxLayout *tcasLayout = new QHBoxLayout;
    tcasLayout->addWidget(tcas1Label);
    tcasLayout->addWidget(m_tcas1Combo);
    tcasLayout->addWidget(tcas2Label);
    tcasLayout->addWidget(m_tcas2Combo);


    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addLayout(dateLocationLayout,   0, 0, 1, 2);
    gridLayout->addLayout(accSectorShiftLayout, 1, 0, 1, 2);
    gridLayout->addWidget(classificationLabel,  2, 0, 1, 1);    gridLayout->addWidget(m_classificationCombo,  2, 1, 1, 1);
    gridLayout->addWidget(typeLabel,            3, 0, 1, 1);    gridLayout->addWidget(m_typeCombo,            3, 1, 1, 1);
    gridLayout->addLayout(atcSposLayout,        4, 0, 1, 2);
    gridLayout->addLayout(tcasLayout,           5, 0, 1, 2);
    gridLayout->addWidget(causeLabel,           6, 0, 1, 1);    gridLayout->addWidget(m_causeEdit,            6, 1, 1, 1);
    gridLayout->addWidget(factorLabel,          7, 0, 1, 1);    gridLayout->addWidget(m_factorEdit,           7, 1, 1, 1);
    gridLayout->addWidget(detailsLabel,         8, 0, 1, 1);    gridLayout->addWidget(m_detailsEdit,          8, 1, 1, 1);

    QVBoxLayout *privateWidgetsLayout = layout();
    privateWidgetsLayout->addLayout(gridLayout);
}

void MapperDialog::updatePrivateWidgets()
{
    if (state() == Normal) {
        m_dateEdit->setReadOnly(true);
        m_shiftEdit->setReadOnly(true);
        m_locationEdit->setReadOnly(true);
        m_causeEdit->setReadOnly(true);
        m_factorEdit->setReadOnly(true);
        m_detailsEdit->setReadOnly(true);
        m_sectorEdit->setReadOnly(true);
        m_accCombo->setEditable(false);
        m_classificationCombo->setEditable(false);
        m_typeCombo->setEditable(false);
        m_terkasCombo->setEditable(false);
        m_alphaCombo->setEditable(false);
        m_tcas1Combo->setEditable(false);
        m_tcas2Combo->setEditable(false);
    } else {
        m_dateEdit->setReadOnly(false);
        m_shiftEdit->setReadOnly(false);
        m_locationEdit->setReadOnly(false);
        m_causeEdit->setReadOnly(false);
        m_factorEdit->setReadOnly(false);
        m_detailsEdit->setReadOnly(false);
        m_sectorEdit->setReadOnly(false);
        m_accCombo->setEditable(true);
        m_classificationCombo->setEditable(true);
        m_typeCombo->setEditable(true);
        m_terkasCombo->setEditable(true);
        m_alphaCombo->setEditable(true);
        m_tcas1Combo->setEditable(true);
        m_tcas2Combo->setEditable(true);

        m_dateEdit->setFocus();
    }
}
