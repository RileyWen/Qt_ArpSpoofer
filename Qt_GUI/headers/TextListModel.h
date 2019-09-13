#ifndef QT_NETCAP_TEXTLISTMODEL_H
#define QT_NETCAP_TEXTLISTMODEL_H

#include <QAbstractListModel>
#include <QVector>
#include <QString>

class TextListModel : public QAbstractListModel {
Q_OBJECT

public:
    explicit TextListModel(QObject *parent = nullptr);

    QVector<QString> items() const;

public slots:
    void appendItem(QString);

private:
    QVector<QString> m_items;
};

#endif //QT_NETCAP_TEXTLISTMODEL_H
