/*
 * Copyright 2018, Adriaan de Groot <groot@kde.org>
 *                 Scott Harvey <scott@spharvey.me> 
 * 
 * This file is part of YAMLAMLDINGDONG (hereafter YDD).
 * 
 *   YDD is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   YDD is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with YDD. If not, see <http://www.gnu.org/licenses/>.
 * 
 *   SPDX-License-Identifier: GPLv3+
 */

/* main.cpp
 * 
 * Run the program with a single argument (a filename) to parse that YAML 
 * file and do stuff with it.
 */

#include <iostream>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

#include "Job.h"
#include "YamlUtils.h"

#include "ChoiceGroup.h"
#include "BackEnd.h"



int main(int argc, char **argv)
{
    QGuiApplication a(argc, argv);

    qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0, "BackEnd");


    QQmlApplicationEngine engine;
    //engine.load(QUrl("qrc:/main.qml"));
    engine.load(QUrl::fromLocalFile("../main.qml"));



    qDebug() << argv[1];

    if ( argc == 2 )
    {
        bool ok = true;
        QVariantMap map = CalamaresUtils::loadYaml( argv[1], &ok );
        if ( ok ) {
            Job j;
            j.setConfigurationMap(map);
            j.debug();

            //ChoiceGroup cg;



            return a.exec();
        }

        {
            std::cerr << "Could not load " << argv[1] << std::endl;
            return 1;
        }





    }
        
    std::cerr << "Usage: " << argv[0] << " <filename>\n\n"
        << "Parses YAML document <filename> and does stuff with it.\n";
        
    return 1;


}
