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
   
    qDebug() << "==== Start Next Top-Level ChoiceGroup ====";
    
    qDebug() << "TITLE: " << m_title;
    qDebug() << "VARIABLE: " << m_variable;
    
     if (m_variable.isEmpty()) {
        std::cerr << "*** ERROR: Associated variable is not supplied. Cannot continue. ***";
    }
    
    if (map.contains("items") && map["items"].canConvert<QVariantList>()) {
        QVariantList items = map["items"].toList();

        for (const auto& item : items) {
            qDebug() << "<--- A ChoiceItem within the ChoiceGroup ----> ";
            QVariantMap map_from_item =item.toMap(); 
            
            m_items.append(ChoiceItem(map_from_item));
            
            //** VALIDITY CHECKING **//
            // these validity checks are educated guesses at the moment, without
            // knowing the real requirements and conditions
            m_isValid = true;
            m_name = map_from_item["name"].toString();
            m_item = map_from_item["item"].toString();
            m_icon = map_from_item["icon"].toString();
            m_package = map_from_item["package"].toString();
            
            if (m_name.isEmpty()) {
                m_name = m_item;
            }
            
            // we copied Item to Name and it's still blank - no name!
            if (m_name.isEmpty()) {
                std::cerr << "*** FAILURE: Name and Item are both blank - cannot continue.***\n" << std::endl;
                m_isValid = false;
            }
            
            // use a generic icon if one isn't specified
            if (m_icon.isEmpty()) {
                m_icon = "/usr/share/icons/generic.png";
            }
            
            if (m_package.isEmpty()) {
                std::cerr << "* WARNING - 'Package entry is empty... verify if it is needed.*\n" << std::endl;
            }
            
            
            qDebug() << "   - item: " << m_item;
            qDebug() << "   - icon: " << m_icon;
            qDebug() << "   - package: " << m_package;
            qDebug() << "   - name : " << m_name;
            
            if (!m_isValid) {
                qDebug() << "=-=-=-=-=-=-=-=-=-=-=-=-=-=";
                qDebug() << "This file has invalid data.";
                qDebug() << "=-=-=-=-=-=-=-=-=-=-=-=-=-=";
            }
            
            
            
        }
    
    }

}
