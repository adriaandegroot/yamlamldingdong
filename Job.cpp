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
#include "Job.h"
#include "ChoiceGroup.h"

#include <iostream>
#include <QDebug>

Job::Job()
{
}

void
Job::setConfigurationMap( const QVariantMap& map )
{
    
    QVariantList choiceList = map["choices"].toList();

    for (auto it : choiceList) {
        
        QVariantMap itMap = it.toMap();
        
        ChoiceGroup c(itMap);
        
        if (!c.valid()) {
            std::cerr << "\n";
            std::cerr << "***\n";
            std::cerr << "* An invalid ChoiceGroup was found in the input file.\n";
            std::cerr << "* We should probably fail gracefully here.\n";
            std::cerr << "***\n\n";
        }
        
    }
    
    qDebug() << "==== Next 'entry' within ChoiceGroup ====";
    
}

void
Job::debug() const
{
    std::cerr << "Job configuration:\n";
    
    // TODO: actually print debugging
    
    // TODO: Maybe most of the current qDebug calls will end up here?
    
    
}
