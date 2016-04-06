#ifndef NODEARRAYTABLEWIDGET_H
#define NODEARRAYTABLEWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QTableView;
class QPushButton;
QT_END_NAMESPACE

class NodeArrayTableModel;

class NodeArrayTableWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString nodepidarr READ nodepidarr WRITE setNodepidarr NOTIFY nodepidarrChanged USER true)

public:
    explicit NodeArrayTableWidget(QWidget *parent = 0);

    void setNodepidarr(const QString &nodepidarr);
    QString nodepidarr() const;

    void setEnabled(bool state);

signals:
    void nodepidarrChanged();

private slots:
    void insertButtonClicked();
    void appendButtonClicked();
    void removeButtonClicked();

private: // functions    
    QList<int> fromString(const QString &string);
    QString toString(QList<int> arr) const;

private:
    // non-Visual elements
    QList<int> m_nodepidarr;
    NodeArrayTableModel *m_model;

    // visual elements
    QTableView *m_view;
    QPushButton *m_insertButton;
    QPushButton *m_appendButton;
    QPushButton *m_removeButton;
};

#endif // NODEARRAYTABLEWIDGET_H
