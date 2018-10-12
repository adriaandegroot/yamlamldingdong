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
#include <iostream>
#include "ChoiceGroup.h"
#include "ChoiceItem.h"
#include <QDebug>

// invalid constructor (so why do we include it?)
ChoiceGroup::ChoiceGroup()
{
}                                                                                                                               

ChoiceGroup::ChoiceGroup(const QVariantMap& map) :

    m_title(getStringValue(map, "title")),
    m_variable(getStringValue(map, "variable"))
    
   
    
{
   
    qDebug() << "TITLE: " << m_title;
    qDebug() << "VARIABLE: " << m_variable;
    
     if (m_variable.isEmpty()) {
        std::cerr << "*** ERROR: Associated variable is not supplied. Cannot continue. ***";
        qDebug() << "Need to quit somehow -- can't use this data.";
    }
    
    if (map.contains("items") && map["items"].canConvert<QVariantList>()) {
        QVariantList items = map["items"].toList();

        for (const auto& item : items) {
            
            QVariantMap map_from_item =item.toMap(); 
            
            // "append" was here in the email... append to what?
            // the ChoiceItem is several data types in one...?
            ChoiceItem foo = ChoiceItem(map_from_item);
            
            qDebug() << "<--- Next entry in this choice group ----> ";
            
        }
    
    }

}


    
