#include "Yddx.h"
#include <QDebug>




Yddx::Yddx(QWidget *parent) :
        KXmlGuiWindow(parent)
        
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


