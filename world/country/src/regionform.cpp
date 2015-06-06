#include <QtGui>
#include <QtSql>

#include "countryform.h"

RegionForm::RegionForm(int regionId, QWidget *parent) :
    QDialog(parent)
{
    codeEdit = new QLineEdit;
    QLabel *codeLabel = new QLabel(trUtf8("R&egion Code:"));
    codeLabel->setBuddy(codeEdit);

    nameEdit = new QLineEdit;
    QLabel *nameLabel = new QLabel(trUtf8("&Region Name:"));
    nameLabel->setBuddy(nameEdit);

    nameRuEdit = new QLineEdit;
    QLabel *nameRuLabel = new QLabel(trUtf8("&Название региона:"));
    nameRuLabel->setBuddy(nameRuEdit);

    QComboBox *countryCombo = new QComboBox;
    QLabel *countryLabel = new QLabel(trUtf8("C&ountry:"));
    countryLabel->setBuddy(countryCombo);

    QPushButton *firstButton = new QPushButton(trUtf8("<< &First"));
    QPushButton *previousButton = new QPushButton(trUtf8("< &Previous"));
    QPushButton *nextButton = new QPushButton(trUtf8("&Next >"));
    QPushButton *lastButton = new QPushButton(trUtf8("&Last >>"));

    QPushButton *addButton = new QPushButton(trUtf8("&Add"));
    QPushButton *deleteButton = new QPushButton(trUtf8("&Delete"));
    QPushButton *closeButton = new QPushButton(trUtf8("&Close"));

    QDialogButtonBox *buttonBox = new QDialogButtonBox;
    buttonBox->addButton(addButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(deleteButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(closeButton, QDialogButtonBox::AcceptRole);

    model = new QSqlRelationalTableModel(this);
    model->setTable("country_ICAOregion");
    model->setRelation(country_id,
                       QSqlRelation("country", "id", "name"));
    model->setSort(code, Qt::AscendingOrder);
    model->select();

    QSqlTableModel *relationModel = model->relationModel(country_id);
    relationModel->setSort(relationModel->fieldIndex("name"), Qt::AscendingOrder);
    countryCombo->setModel(relationModel);
    countryCombo->setModelColumn(relationModel->fieldIndex("name"));

    mapper = new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
    mapper->setModel(model);
    mapper->setItemDelegate(new QSqlRelationalDelegate(this));
    mapper->addMapping(codeEdit, code);
    mapper->addMapping(nameEdit, name);
    mapper->addMapping(nameRuEdit, name_ru);
    mapper->addMapping(countryCombo, country_id);

    if (regionId != -1) {
        for (int row = 0; row < model->rowCount(); row++) {
            QSqlRecord record = model->record(row);
            if (record.value(id).toInt() == regionId) {
                mapper->setCurrentIndex(row);
                break;
            }
        }
    } else {
        mapper->toFirst();
    }

    connect(firstButton, SIGNAL(clicked()),
            mapper, SLOT(toFirst()));
    connect(previousButton, SIGNAL(clicked()),
            mapper, SLOT(toPrevious()));
    connect(nextButton, SIGNAL(clicked()),
            mapper, SLOT(toNext()));
    connect(lastButton, SIGNAL(clicked()),
            mapper, SLOT(toLast()));
    connect(addButton, SIGNAL(clicked()),
            this, SLOT(addRegion()));
    connect(deleteButton, SIGNAL(clicked()),
            this, SLOT(deleteRegion()));
    connect(closeButton, SIGNAL(clicked()),
            this, SLOT(accept()));

    QHBoxLayout *topButtonLayout = new QHBoxLayout;
    topButtonLayout->setContentsMargins(20, 0, 20, 5);
    topButtonLayout->addStretch();
    topButtonLayout->addWidget(firstButton);
    topButtonLayout->addWidget(previousButton);
    topButtonLayout->addWidget(nextButton);
    topButtonLayout->addWidget(lastButton);
    topButtonLayout->addStretch();

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addLayout(topButtonLayout, 0, 0, 1, 3);
    mainLayout->addWidget(codeLabel, 1, 0);    mainLayout->addWidget(codeEdit, 1, 1);
    mainLayout->addWidget(nameLabel, 2, 0);    mainLayout->addWidget(nameEdit, 2, 1, 1, 2);
    mainLayout->addWidget(nameRuLabel, 3, 0);  mainLayout->addWidget(nameRuEdit, 3, 1, 1, 2);
    mainLayout->addWidget(countryLabel, 4, 0); mainLayout->addWidget(countryCombo, 4, 1, 1, 2);
    mainLayout->addWidget(buttonBox, 5, 0, 1, 3);
    mainLayout->setRowMinimumHeight(6, 10);
    mainLayout->setRowStretch(6, 1);
    mainLayout->setColumnStretch(2, 1);
    setLayout(mainLayout);

    if (id == -1)
        nextButton->setFocus();
    else
        codeEdit->setFocus();

    setWindowTitle(trUtf8("Edit Region"));
}

void RegionForm::done(int result)
{
    mapper->submit();
    QDialog::done(result);
}

void RegionForm::addRegion()
{
    int row = mapper->currentIndex();
    mapper->submit();
    model->insertRow(row);
    mapper->setCurrentIndex(row);

    codeEdit->clear();
    nameEdit->clear();
    nameRuEdit->clear();
    nameEdit->setFocus();
}

void RegionForm::deleteRegion()
{
    int row = mapper->currentIndex();
    model->removeRow(row);
    mapper->submit();
    mapper->setCurrentIndex(qMin(row, model->rowCount() - 1));
}
