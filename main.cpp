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
#include <QDebug>
#include <QQmlApplicationEngine>
#include "Job.h"
#include "YamlUtils.h"
#include <QGuiApplication>
#include "ChoiceGroup.h"
#include "Yddx.h"
#include <QtWidgets/QApplication>



int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    if ( argc == 2 )
    {
        bool ok = true;
        QVariantMap map = CalamaresUtils::loadYaml( argv[1], &ok );
        if ( ok ) {
            Job j;
            j.setConfigurationMap(map);
            j.debug();  
            
        
            
            
            return app.exec();
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
