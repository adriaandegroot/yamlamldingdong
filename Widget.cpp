#include "Widget.h"
#include <QDebug>

Widget::Widget(QObject *parent) :
        QObject(parent)
{
}

QString Widget::userName()
{
    return m_userName;
}

void Widget::setUserName(const QString &userName)
{
    if (userName == m_userName)
        return;

    m_userName = userName;
    emit userNameChanged();
}


