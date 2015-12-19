#include <QtWidgets>

#include "filterdialog.h"


FilterDialog::FilterDialog(QWidget *parent)
    : QDialog(parent)
{
    m_comboBox = new QComboBox;
    m_lineEdit = new QLineEdit;

    QPushButton *filterButton = new QPushButton(trUtf8("Поиск"));

    connect(filterButton, SIGNAL(clicked()),
            this, SLOT(filter()));
    connect(filterButton, SIGNAL(clicked()),
            this, SLOT(accept()));

    m_csCheckBox = new QCheckBox("Case sensitive");

    QDialogButtonBox *buttonBox = new QDialogButtonBox(Qt::Horizontal);
    buttonBox->addButton(filterButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(QDialogButtonBox::Close);

    connect(buttonBox, SIGNAL(rejected()),
            this, SLOT(reject()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(m_comboBox);
    mainLayout->addWidget(m_lineEdit);
    mainLayout->addWidget(m_csCheckBox);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(trUtf8("Поиск"));
}

void FilterDialog::addValues(const QStringList &labels, const QList<int> &values)
{
    for (int i = 0; i < values.length(); i++) {
        m_comboBox->addItem(labels.at(i), values.at(i));
    }
}

int FilterDialog::column() const
{
    int col = m_comboBox->currentData().toInt();
    return col;
}

QString FilterDialog::pattern() const
{
    QString pattern = m_lineEdit->text();
    if (!pattern.isEmpty()) {
        return pattern;
    }

    return QString();
}

Qt::CaseSensitivity FilterDialog::cs() const
{
    return m_csCheckBox->isChecked() ? Qt::CaseSensitive :
                                       Qt::CaseInsensitive;
}

void FilterDialog::filter()
{
    int value = m_comboBox->currentData().toInt();
}
