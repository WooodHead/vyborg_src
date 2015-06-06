#include <QtWidgets>
#include <QtSql>

#include "mapperdialog.h"
#include "declarations.h"
#include "relationaltablemodel.h"

#include "geomdelegate.h"
#include "coordwidget.h"


MapperDialog::MapperDialog(RelationalTableModel *model, int indx, QWidget *parent)
    : QDialog(parent)
{
    m_model = model;

    m_mapper = new QDataWidgetMapper;
    m_mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    m_mapper->setModel(m_model);
//    m_mapper->setItemDelegate(new GeomDelegate);
    m_mapper->setItemDelegate(new QSqlRelationalDelegate(m_mapper));


    QLabel *lLabel = new QLabel(trUtf8("Название"));
    QLineEdit *leLabel = new QLineEdit;
    QLineEdit *leName = new QLineEdit;
    QHBoxLayout *hbox1 = new QHBoxLayout;
    hbox1->addWidget(leLabel);
    hbox1->addWidget(leName);

    QLabel *lType = new QLabel(trUtf8("Тип"));
    QComboBox *cbType = new QComboBox;
    QSqlTableModel *modelType = m_model->relationModel(col_type);
    cbType->setModel(modelType);
    cbType->setModelColumn(modelType->fieldIndex("type"));
    QComboBox *cbStatus = new QComboBox;
    QSqlTableModel *modelStatus = m_model->relationModel(col_status);
    cbStatus->setModel(modelStatus);
    cbStatus->setModelColumn(modelStatus->fieldIndex("status"));
    QHBoxLayout *hbox2 = new QHBoxLayout;
    hbox2->addWidget(cbType);
    hbox2->addWidget(cbStatus);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(lLabel, hbox1);
    formLayout->addRow(lType, hbox2);


    CoordWidget *latCoordWidget = new CoordWidget;
    CoordWidget *lonCoordWidget = new CoordWidget;

    formLayout->addRow(new QLabel(trUtf8("Широта")), latCoordWidget);
    formLayout->addRow(new QLabel(trUtf8("Долгота")), lonCoordWidget);


    QLabel *lSrid = new QLabel(trUtf8("SRID"));
    QComboBox *cbSrid = new QComboBox;
    QSqlTableModel *modelSrid = m_model->relationModel(col_srid);
    cbSrid->setModel(modelSrid);
    cbSrid->setModelColumn(modelSrid->fieldIndex("srid"));
    QHBoxLayout *hboxSrid = new QHBoxLayout;
    hboxSrid->addWidget(lSrid);
    hboxSrid->addWidget(cbSrid);


    QPlainTextEdit *pteNote = new QPlainTextEdit;


    QPushButton *pbToFirst = new QPushButton(trUtf8("First"));
    QPushButton *pbToPrev = new QPushButton(trUtf8("Previous"));
    QPushButton *pbToNext = new QPushButton(trUtf8("Next"));
    QPushButton *pbToLast = new QPushButton(trUtf8("Last"));

    connect(pbToFirst, SIGNAL(clicked()),
            m_mapper, SLOT(toFirst()));
    connect(pbToPrev, SIGNAL(clicked()),
            m_mapper, SLOT(toPrevious()));
    connect(pbToNext, SIGNAL(clicked()),
            m_mapper, SLOT(toNext()));
    connect(pbToLast, SIGNAL(clicked()),
            m_mapper, SLOT(toLast()));

    QDialogButtonBox *navbbox = new QDialogButtonBox(Qt::Horizontal);
    navbbox->addButton(pbToFirst, QDialogButtonBox::ActionRole);
    navbbox->addButton(pbToPrev, QDialogButtonBox::ActionRole);
    navbbox->addButton(pbToNext, QDialogButtonBox::ActionRole);
    navbbox->addButton(pbToLast, QDialogButtonBox::ActionRole);


    QPushButton *pbSave = new QPushButton(trUtf8("Save"));
    QPushButton *pbClose = new QPushButton(trUtf8("Close"));

    connect(pbSave, SIGNAL(clicked()),
            this, SLOT(save()));
    connect(pbClose, SIGNAL(clicked()),
            this, SLOT(close()));

    QDialogButtonBox *bbox = new QDialogButtonBox(Qt::Vertical);
    bbox->addButton(pbSave, QDialogButtonBox::ActionRole);
    bbox->addButton(pbClose, QDialogButtonBox::ActionRole);

    QLabel *lSource = new QLabel(trUtf8("Сведения"));
    QComboBox *cbSource = new QComboBox;
    QSqlTableModel *modelSource = m_model->relationModel(col_source);
    cbSource->setModel(modelSource);
    cbSource->setModelColumn(modelSource->fieldIndex("doc"));
    QHBoxLayout *hbox3 = new QHBoxLayout;
    hbox3->addWidget(lSource);
    hbox3->addWidget(cbSource);



    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addLayout(formLayout);
//    vLayout->addWidget(latCoordWidget);
//    vLayout->addWidget(lonCoordWidget);
    vLayout->addWidget(pteNote);
    vLayout->addLayout(hboxSrid);
    vLayout->addLayout(hbox3);
    vLayout->addWidget(navbbox);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(vLayout);
    mainLayout->addWidget(bbox);

    setLayout(mainLayout);


    m_mapper->addMapping(leLabel, col_label);
    m_mapper->addMapping(leName, col_name);
    m_mapper->addMapping(cbType, col_type);
    m_mapper->addMapping(cbStatus, col_status);
    m_mapper->addMapping(latCoordWidget, col_st_x, "coord");
    m_mapper->addMapping(lonCoordWidget, col_st_y, "coord");
    m_mapper->addMapping(pteNote, col_note);
    m_mapper->addMapping(cbSource, col_source);
    m_mapper->addMapping(cbSrid, col_srid);


    m_mapper->setCurrentIndex(indx);
}

void MapperDialog::save()
{
    if (!m_mapper->submit())
        qDebug() << "ERROR: " << m_model->lastError().text();
    if (!m_model->submitAll())
        qDebug() << "ERROR: " << m_model->lastError().text();
}
