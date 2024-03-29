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

ChoiceItem::ChoiceItem() :
    m_isValid( false )
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
    // Data fixups -- handle incomplete data where we can fill in some bits
	if (m_name.isEmpty()) m_name=m_item;

	// Data validation
	if (m_item.isEmpty()) m_isValid=false;
	if (m_name.isEmpty()) m_isValid=false;
    
    //No need to examine icon or package, as they are optional
    
    // this doesn't really belong in the constructor (does it?)
    // but it's temmporary and will go away
    debugChoiceItem();
    
}
    
void ChoiceItem::debugChoiceItem() {
    qDebug() << "    item: " << m_item;
    qDebug() << "    icon: " << m_icon;
    qDebug() << " package: " << m_package;
    qDebug() << "    name: " << m_name;
    
}
