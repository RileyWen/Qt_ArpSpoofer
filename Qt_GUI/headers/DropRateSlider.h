//
// Created by riley on 9/12/2019.
//

#ifndef QT_NETCAP_BACKEND_H
#define QT_NETCAP_BACKEND_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QStringListModel>

extern QStringListModel *slmodel;

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

class DropRateSlider : public QObject {
    Q_OBJECT
    Q_PROPERTY(int m_dropRate)
public:
    float m_dropRate;

    explicit DropRateSlider(QObject *parent = nullptr) { m_dropRate = 0; }

    Q_INVOKABLE void setDropRate(float v) {
        m_dropRate = v;
        qDebug() << "drop rate is set to" << v ;

        if (slmodel->insertRow(slmodel->rowCount())) {
            QModelIndex index = slmodel->index(slmodel->rowCount() - 1, 0);
            slmodel->setData(index, "value:" + QString::number(v));
        }
    }
};



#endif //QT_NETCAP_BACKEND_H
