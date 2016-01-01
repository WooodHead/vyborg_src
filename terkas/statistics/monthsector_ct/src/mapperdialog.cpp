#include <QtWidgets>

#include "mapperdialog.h"
#include "declarations.h"


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
    m_dateEdit->setDisplayFormat("yyyy MMMM");

    m_a5edit = new QLineEdit;
    m_a6edit = new QLineEdit;
    m_v1edit = new QLineEdit;
    m_v2edit = new QLineEdit;
    m_v3edit = new QLineEdit;
    m_v4edit = new QLineEdit;
    m_g2edit = new QLineEdit;
    m_g3edit = new QLineEdit;
    m_g4edit = new QLineEdit;
    m_g5edit = new QLineEdit;
    m_g6edit = new QLineEdit;
    m_z1edit = new QLineEdit;
    m_z2edit = new QLineEdit;
    m_k1edit = new QLineEdit;
    m_k2edit = new QLineEdit;
    m_l1edit = new QLineEdit;
    m_p1edit = new QLineEdit;
    m_p2edit = new QLineEdit;
    m_s1edit = new QLineEdit;
    m_h1edit = new QLineEdit;
    m_h2edit = new QLineEdit;

    QDataWidgetMapper* m_mapper = mapper();
    m_mapper->addMapping(m_dateEdit, monthsector_ct_date);
    m_mapper->addMapping(m_a5edit,   monthsector_ct_a5);
    m_mapper->addMapping(m_a6edit,   monthsector_ct_a6);
    m_mapper->addMapping(m_v1edit,   monthsector_ct_v1);
    m_mapper->addMapping(m_v2edit,   monthsector_ct_v2);
    m_mapper->addMapping(m_v3edit,   monthsector_ct_v3);
    m_mapper->addMapping(m_v4edit,   monthsector_ct_v4);
    m_mapper->addMapping(m_g2edit,   monthsector_ct_g2);
    m_mapper->addMapping(m_g3edit,   monthsector_ct_g3);
    m_mapper->addMapping(m_g4edit,   monthsector_ct_g4);
    m_mapper->addMapping(m_g5edit,   monthsector_ct_g5);
    m_mapper->addMapping(m_g6edit,   monthsector_ct_g6);
    m_mapper->addMapping(m_z1edit,   monthsector_ct_z1);
    m_mapper->addMapping(m_z2edit,   monthsector_ct_z2);
    m_mapper->addMapping(m_k1edit,   monthsector_ct_k1);
    m_mapper->addMapping(m_k2edit,   monthsector_ct_k2);
    m_mapper->addMapping(m_l1edit,   monthsector_ct_l1);
    m_mapper->addMapping(m_p1edit,   monthsector_ct_p1);
    m_mapper->addMapping(m_p2edit,   monthsector_ct_p2);
    m_mapper->addMapping(m_s1edit,   monthsector_ct_s1);
    m_mapper->addMapping(m_h1edit,   monthsector_ct_h1);
    m_mapper->addMapping(m_h2edit,   monthsector_ct_h2);
}

void MapperDialog::layoutPrivateWidgets()
{
    QLabel *dateLabel = new QLabel(trUtf8("Year and month:"));
    dateLabel->setBuddy(m_dateEdit);

    QLabel *a5label = new QLabel(trUtf8("А5:"));
    a5label->setBuddy(m_a5edit);

    QLabel *a6label = new QLabel(trUtf8("А6:"));
    a6label->setBuddy(m_a6edit);

    QLabel *v1label = new QLabel(trUtf8("В1:"));
    v1label->setBuddy(m_v1edit);

    QLabel *v2label = new QLabel(trUtf8("В2:"));
    v2label->setBuddy(m_v2edit);

    QLabel *v3label = new QLabel(trUtf8("В3:"));
    v3label->setBuddy(m_v3edit);

    QLabel *v4label = new QLabel(trUtf8("В4:"));
    v4label->setBuddy(m_v4edit);

    QLabel *g2label = new QLabel(trUtf8("Г2:"));
    g2label->setBuddy(m_g2edit);

    QLabel *g3label = new QLabel(trUtf8("Г3:"));
    g3label->setBuddy(m_g3edit);

    QLabel *g4label = new QLabel(trUtf8("Г4:"));
    g4label->setBuddy(m_g4edit);

    QLabel *g5label = new QLabel(trUtf8("Г5:"));
    g5label->setBuddy(m_g5edit);

    QLabel *g6label = new QLabel(trUtf8("Г6:"));
    g6label->setBuddy(m_g6edit);

    QLabel *z1label = new QLabel(trUtf8("З1:"));
    z1label->setBuddy(m_z1edit);

    QLabel *z2label = new QLabel(trUtf8("З2:"));
    z2label->setBuddy(m_z2edit);

    QLabel *k1label = new QLabel(trUtf8("К1:"));
    k1label->setBuddy(m_k1edit);

    QLabel *k2label = new QLabel(trUtf8("К2:"));
    k2label->setBuddy(m_k2edit);

    QLabel *l1label = new QLabel(trUtf8("Л1:"));
    l1label->setBuddy(m_l1edit);

    QLabel *p1label = new QLabel(trUtf8("П1:"));
    p1label->setBuddy(m_p1edit);

    QLabel *p2label = new QLabel(trUtf8("П2:"));
    p2label->setBuddy(m_p2edit);

    QLabel *s1label = new QLabel(trUtf8("С1:"));
    s1label->setBuddy(m_s1edit);

    QLabel *h1label = new QLabel(trUtf8("Х1:"));
    h1label->setBuddy(m_h1edit);

    QLabel *h2label = new QLabel(trUtf8("Х2:"));
    h2label->setBuddy(m_h2edit);



    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(dateLabel,  0, 0, 1, 1);    gridLayout->addWidget(m_dateEdit,  0, 1, 1, 1);
    gridLayout->addWidget(a5label,    1, 0, 1, 1);    gridLayout->addWidget(m_a5edit,    1, 1, 1, 1);
    gridLayout->addWidget(a6label,    2, 0, 1, 1);    gridLayout->addWidget(m_a6edit,    2, 1, 1, 1);
    gridLayout->addWidget(v1label,    3, 0, 1, 1);    gridLayout->addWidget(m_v1edit,    3, 1, 1, 1);
    gridLayout->addWidget(v2label,    4, 0, 1, 1);    gridLayout->addWidget(m_v2edit,    4, 1, 1, 1);
    gridLayout->addWidget(v3label,    5, 0, 1, 1);    gridLayout->addWidget(m_v3edit,    5, 1, 1, 1);
    gridLayout->addWidget(v4label,    6, 0, 1, 1);    gridLayout->addWidget(m_v4edit,    6, 1, 1, 1);
    gridLayout->addWidget(g2label,    7, 0, 1, 1);    gridLayout->addWidget(m_g2edit,    7, 1, 1, 1);
    gridLayout->addWidget(g3label,    8, 0, 1, 1);    gridLayout->addWidget(m_g3edit,    8, 1, 1, 1);
    gridLayout->addWidget(g4label,    9, 0, 1, 1);    gridLayout->addWidget(m_g4edit,    9, 1, 1, 1);
    gridLayout->addWidget(g5label,   10, 0, 1, 1);    gridLayout->addWidget(m_g5edit,   11, 1, 1, 1);
    gridLayout->addWidget(g6label,   11, 0, 1, 1);    gridLayout->addWidget(m_g6edit,   12, 1, 1, 1);
    gridLayout->addWidget(z1label,   12, 0, 1, 1);    gridLayout->addWidget(m_z1edit,   13, 1, 1, 1);
    gridLayout->addWidget(z2label,   13, 0, 1, 1);    gridLayout->addWidget(m_z2edit,   14, 1, 1, 1);
    gridLayout->addWidget(k1label,   14, 0, 1, 1);    gridLayout->addWidget(m_k1edit,   15, 1, 1, 1);
    gridLayout->addWidget(k2label,   15, 0, 1, 1);    gridLayout->addWidget(m_k2edit,   16, 1, 1, 1);
    gridLayout->addWidget(l1label,   16, 0, 1, 1);    gridLayout->addWidget(m_l1edit,   17, 1, 1, 1);
    gridLayout->addWidget(p1label,   17, 0, 1, 1);    gridLayout->addWidget(m_p1edit,   18, 1, 1, 1);
    gridLayout->addWidget(p2label,   18, 0, 1, 1);    gridLayout->addWidget(m_p2edit,   19, 1, 1, 1);
    gridLayout->addWidget(s1label,   19, 0, 1, 1);    gridLayout->addWidget(m_s1edit,   20, 1, 1, 1);
    gridLayout->addWidget(h1label,   20, 0, 1, 1);    gridLayout->addWidget(m_h1edit,   21, 1, 1, 1);
    gridLayout->addWidget(h2label,   21, 0, 1, 1);    gridLayout->addWidget(m_h2edit,   22, 1, 1, 1);

    QVBoxLayout *privateWidgetsLayout = layout();
    privateWidgetsLayout->addLayout(gridLayout);
}

void MapperDialog::updatePrivateWidgets()
{
    if (isDirty()) {
        m_dateEdit->setReadOnly(false);
        m_a5edit->setReadOnly(false);
        m_a6edit->setReadOnly(false);
        m_v1edit->setReadOnly(false);
        m_v2edit->setReadOnly(false);
        m_v3edit->setReadOnly(false);
        m_v4edit->setReadOnly(false);
        m_g2edit->setReadOnly(false);
        m_g3edit->setReadOnly(false);
        m_g4edit->setReadOnly(false);
        m_g5edit->setReadOnly(false);
        m_g6edit->setReadOnly(false);
        m_z1edit->setReadOnly(false);
        m_z2edit->setReadOnly(false);
        m_k1edit->setReadOnly(false);
        m_k2edit->setReadOnly(false);
        m_l1edit->setReadOnly(false);
        m_p1edit->setReadOnly(false);
        m_p2edit->setReadOnly(false);
        m_s1edit->setReadOnly(false);
        m_h1edit->setReadOnly(false);
        m_h2edit->setReadOnly(false);

        m_dateEdit->setFocus();
    } else {
        m_dateEdit->setReadOnly(true);
        m_a5edit->setReadOnly(true);
        m_a6edit->setReadOnly(true);
        m_v1edit->setReadOnly(true);
        m_v2edit->setReadOnly(true);
        m_v3edit->setReadOnly(true);
        m_v4edit->setReadOnly(true);
        m_g2edit->setReadOnly(true);
        m_g3edit->setReadOnly(true);
        m_g4edit->setReadOnly(true);
        m_g5edit->setReadOnly(true);
        m_g6edit->setReadOnly(true);
        m_z1edit->setReadOnly(true);
        m_z2edit->setReadOnly(true);
        m_k1edit->setReadOnly(true);
        m_k2edit->setReadOnly(true);
        m_l1edit->setReadOnly(true);
        m_p1edit->setReadOnly(true);
        m_p2edit->setReadOnly(true);
        m_s1edit->setReadOnly(true);
        m_h1edit->setReadOnly(true);
        m_h2edit->setReadOnly(true);
    }
}
