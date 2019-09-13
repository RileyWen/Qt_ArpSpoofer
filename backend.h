//
// Created by riley on 9/12/2019.
//

#ifndef QT_NETCAP_BACKEND_H

#include <QObject>
#include <QString>
#include <QDebug>

class BackEnd : public QObject
{
Q_OBJECT
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)

public:
    explicit BackEnd(QObject *parent = nullptr);

    QString userName();
    void setUserName(const QString &userName);

signals:
    void userNameChanged();

private:
    QString m_userName;
};

#define QT_NETCAP_BACKEND_H

#endif //QT_NETCAP_BACKEND_H
