//
// Created by riley on 9/12/2019.
//

#ifndef QT_NETCAP_BACKEND_H

#include <QObject>
#include <QString>
#include <QDebug>

class Text1 : public QObject {
Q_OBJECT
    Q_PROPERTY(QString userName
                       READ
                               userName
                       WRITE
                       setUserName)

public:
    explicit Text1(QObject *parent = nullptr);

    QString userName();

    void setUserName(const QString &userName);

private:
    QString m_userName;
};

class DropRateB : public QObject {
    Q_OBJECT
    Q_PROPERTY(int m_dropRate)
public:
    float m_dropRate;

    explicit DropRateB(QObject *parent = nullptr) { m_dropRate = 0; }

    Q_INVOKABLE void setDropRate(float v) {
        m_dropRate = v;
        qDebug() << "drop rate is set to" << v ;
    }
};

extern DropRateB *drp;

#define QT_NETCAP_BACKEND_H

#endif //QT_NETCAP_BACKEND_H
