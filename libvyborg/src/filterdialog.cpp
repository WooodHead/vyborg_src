#include <QtWidgets>
#include <QtSql>

#include "filterdialog.h"


VyborgFilterDialog::VyborgFilterDialog(QSortFilterProxyModel *proxy, QWidget *parent)
    : QDialog(parent)
{
    proxy_ = proxy;

    caseSensitivityCheckBox = new QCheckBox(trUtf8("Case sensitive filtering"));

    patternLineEdit = new QLineEdit;
    QLabel *patternLabel = new QLabel(trUtf8("&Filter pattern"));
    patternLabel->setBuddy(patternLineEdit);

    syntaxComboBox = new QComboBox;
    syntaxComboBox->addItem(trUtf8("Regular Expression"), QRegExp::RegExp);
    syntaxComboBox->addItem(trUtf8("Wildcard"), QRegExp::Wildcard);
    syntaxComboBox->addItem(trUtf8("Fixed String"), QRegExp::FixedString);
    QLabel *syntaxLabel = new QLabel(trUtf8("Filter syntax"));
    syntaxLabel->setBuddy(syntaxComboBox);

    columnComboBox = new QComboBox;
    QLabel *columnLabel = new QLabel(trUtf8("Filter column"));
    columnLabel->setBuddy(columnComboBox);


    filterButton = new QPushButton(trUtf8("Filter"));
    filterButton->setEnabled(false);
    QPushButton *closeButton  = new QPushButton(trUtf8("Close"));


    connect(patternLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(filterRegExpChanged()));

    connect(filterButton, SIGNAL(clicked()),
            SLOT(filter()));
    connect(closeButton, SIGNAL(clicked()),
            SLOT(close()));


    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(patternLabel, 0, 0);  gridLayout->addWidget(patternLineEdit, 0, 1);
    gridLayout->addWidget(columnLabel,  1, 0);  gridLayout->addWidget(columnComboBox,  1, 1);
    gridLayout->addWidget(syntaxLabel,  2, 0);  gridLayout->addWidget(syntaxComboBox,  2, 1);
    gridLayout->addWidget(caseSensitivityCheckBox, 3, 0, 1, 2);

    QGroupBox *groupBox = new QGroupBox(this);
    groupBox->setLayout(gridLayout);


    QVBoxLayout *buttonLayout = new QVBoxLayout;
    buttonLayout->addWidget(filterButton);
    buttonLayout->addWidget(closeButton);
    buttonLayout->addStretch();


    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(groupBox);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
}

void VyborgFilterDialog::addColumn(const QString &columnText, const int columnData)
{
    columnComboBox->addItem(columnText, columnData);
}

void VyborgFilterDialog::filterRegExpChanged()
{
    patternLineEdit->text().isEmpty() ? filterButton->setEnabled(false) :
                                        filterButton->setEnabled(true);
}

void VyborgFilterDialog::filter()
{
    int col = columnComboBox->currentData().toInt();
    QRegExp::PatternSyntax syntax = QRegExp::PatternSyntax(syntaxComboBox->itemData(syntaxComboBox->currentIndex()).toInt());
    Qt::CaseSensitivity cs = caseSensitivityCheckBox->isChecked() ? Qt::CaseSensitive :
                                                                    Qt::CaseInsensitive;
    QString text = patternLineEdit->text();
    QRegExp rx(text, cs, syntax);

    proxy_->setFilterKeyColumn(col);
    proxy_->setFilterRegExp(rx);
}

void VyborgFilterDialog::close()
{
    done(QDialog::Rejected);
}
