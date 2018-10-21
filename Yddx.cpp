#include "Yddx.h"
#include <QQmlApplicationEngine>
#include <QDebug>

Yddx::Yddx(QObject *parent) :
        QObject(parent)
{
        
}

QString Yddx::userName()
{
    return m_userName;
}

void Yddx::setUserName(const QString &userName)
{
    if (userName == m_userName)
        return;

    m_userName = userName;
    emit userNameChanged();
}


