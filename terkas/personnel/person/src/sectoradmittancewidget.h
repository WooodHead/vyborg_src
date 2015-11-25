#ifndef SECTORADMITTANCEWIDGET_H
#define SECTORADMITTANCEWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QCheckBox;
QT_END_NAMESPACE

class SectorAdmittanceWidget : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QString array READ array WRITE setArray USER true)

public:
    explicit SectorAdmittanceWidget(QWidget *parent = 0);

public Q_SLOTS:
    void setArray(const QString & array);
    QString array() const;

private:
    // Visual elements
    QCheckBox *m_checkG2;
    QCheckBox *m_checkG3;
    QCheckBox *m_checkG4;
    QCheckBox *m_checkG5;
    QCheckBox *m_checkG6;
    QCheckBox *m_checkS1;
    QCheckBox *m_checkL1;
    QCheckBox *m_checkZ1;
    QCheckBox *m_checkZ2;
    QCheckBox *m_checkK1;
    QCheckBox *m_checkK2;
    QCheckBox *m_checkH1;
    QCheckBox *m_checkH2;
    QCheckBox *m_checkV1;
    QCheckBox *m_checkP1;
    QCheckBox *m_checkP2;
    QCheckBox *m_checkV2;
    QCheckBox *m_checkV3;
    QCheckBox *m_checkV4;
    QCheckBox *m_checkA1;
    QCheckBox *m_checkA2;
    QCheckBox *m_checkA3;
    QCheckBox *m_checkA5;

    // Non-visual elements
    QString m_array;
};

#endif // SECTORADMITTANCEWIDGET_H
