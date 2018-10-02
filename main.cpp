/*
 * Copyright 2018, Adriaan de Groot <groot@kde.org>
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

#include <QCoreApplication>

#include "Job.h"
#include "YamlUtils.h"

#include "ListQVM.h"

int main(int argc, char **argv)
{
    QCoreApplication a( argc, argv );

    if ( argc == 2 )
    {
        bool ok = true;
        QVariantMap map = CalamaresUtils::loadYaml( argv[1], &ok );
        if ( ok )
        {
            Job j;
            j.setConfigurationMap( map );
            j.debug();

            ListQVM q(map);

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
        
    return 1;
}
