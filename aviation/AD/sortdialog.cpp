#include <QtWidgets>

#include "sortdialog.h"


SortDialog::SortDialog(QWidget *parent)
    : QDialog(parent)
{
    m_comboBox = new QComboBox;

    QPushButton *sortButton = new QPushButton(trUtf8("Сортировать"));

    connect(sortButton, SIGNAL(clicked()),
            this, SLOT(sort()));

    QDialogButtonBox *buttonBox = new QDialogButtonBox(Qt::Horizontal);
    buttonBox->addButton(sortButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(QDialogButtonBox::Close);

    connect(buttonBox, SIGNAL(rejected()),
            this, SLOT(close()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(m_comboBox);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle("Сортировать");
}

void SortDialog::addValues(const QStringList &labels, const QList<int> &values)
{
    for (int i = 0; i < values.length(); i++) {
        m_comboBox->addItem(labels.at(i), values.at(i));
    }
}

void SortDialog::sort()
{
    int value = m_comboBox->currentData().toInt();
    done(value);
}
