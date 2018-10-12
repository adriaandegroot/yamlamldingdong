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

#include "ChoiceItem.h"
#include <QDebug>

ChoiceItem::ChoiceItem()
{
}


ChoiceItem::ChoiceItem(const QVariantMap& map) :

   // I will work on the delegated constructors once I grasp the concept.
   // Right now, it's pure black magic. Although I have some theories.
    
    m_isValid(true),
    m_item(getStringValue(map, "item")),
    m_icon(getStringValue(map, "icon")),
    m_package(getStringValue(map, "package")),
    m_name(getStringValue(map, "name"))
    
{

    // these validity checks are educated guesses at the moment, without
    // knowing the real requirements and conditions
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
        qDebug() << "This file has invalid data. We need to quit somehow, but I'll wait for guidance" \
                 << " on the proper way to go about that.";
    }
    
}


