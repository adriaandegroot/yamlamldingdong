#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Job.h"
#include "YamlUtils.h"

#include "ChoiceGroup.h"

#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    if ( argc == 2 )
    {
        bool ok = true;
        QVariantMap map = CalamaresUtils::loadYaml( argv[1], &ok );
        if ( ok )
        {
            Job j;
            j.setConfigurationMap( map );
            j.debug();

            //ChoiceGroup cg;
            
            return 0;
        }
        else
        {
            std::cerr << "Could not load " << argv[1] << std::endl;
            return 1;
        }


    }
        
    std::cerr << "Usage: " << argv[0] << " <filename>\n\n"
        << "Parses YAML document <filename> and does stuff with it.\n";
        
    
    return app.exec();
}
