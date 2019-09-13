#include "Qt_GUI/headers/backend.h"

Text1::Text1(QObject *parent) :
        QObject(parent) {
}

QString Text1::userName() {
    return m_userName;
}

void Text1::setUserName(const QString &userName) {
    if (userName == m_userName)
        return;

    m_userName = userName;

    qDebug() << "userName Changed to: " << m_userName;
}
