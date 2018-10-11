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
#include "ChoiceItem.h"

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
    
    if (m_icon.isEmpty()) {
        m_icon = "/usr/share/icons/generic.png";
    }
    
    if (m_item.isEmpty()) {
        m_isValid = false;
    }
    
    if (m_package.isEmpty()) {
        m_isValid = false;
    }
}

bool ChoiceItem::isValid() {
    return m_isValid;
}
