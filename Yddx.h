#ifndef YDDX_H
#define YDDX_H

#include <QObject>
#include <QString>
#include <KXmlGuiWindow>



class Yddx : public KXmlGuiWindow
{
    Q_OBJECT
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)

public:
    explicit Yddx(QWidget *parent = nullptr);
    ~Yddx();

    QString userName();
    void setUserName(const QString &userName);

signals:
    void userNameChanged();

private:
    QString m_userName;
    
    
};

#endif // YDDX_H
