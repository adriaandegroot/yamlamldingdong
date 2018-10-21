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

   
    m_isValid(true),
    m_title(getStringValue(map, "title")),
    m_variable(getStringValue(map, "variable"))
    
    
{
   
    qDebug() << "==== Start Next Top-Level ChoiceGroup ====";
    
    qDebug() << "TITLE: " << m_title;
    qDebug() << "VARIABLE: " << m_variable;
    
    QVariantList items;
    
    if (map.contains("items") && map["items"].canConvert<QVariantList>()) {
        items = map["items"].toList();
    }
        
    qDebug() << "ITEMS: " << items;    
        
    
        
    
    


        for (const auto& item : items) {
            qDebug() << "<--- A ChoiceItem within the ChoiceGroup ----> ";
            QVariantMap map_from_item =item.toMap(); 
            
            validateItems(map_from_item);
            
        }
     /*
        for (const auto& choice : m_items) {
            if (!choice.isValid()) {
                qDebug() << "### This ChoiceGroup is declared invalid due to an invalid ChoiceItem ###";
                m_isValid = false;
        }
     */
    
   
    // Validation checks - in the wrong place? Can't check if "items" is empty,
    // they need a chance to get filled - right?
   // if (m_title.isEmpty()) {
   //     m_isValid = false;
   // }
    
   // if (m_items.isEmpty()) {
   //     m_isValid = false;
   // }
   
}

void ChoiceGroup::validateItems(QVariantMap& map) 
{

    m_isValid = true;
    m_item = getStringValue(map, "item");
    m_icon = getStringValue(map, "icon");
    m_package = getStringValue(map, "package");
    m_name = getStringValue(map, "name");
      
    // Data fixups -- handle incomplete data where we can fill in some bits
	if (m_name.isEmpty()) m_name=m_item;

	// Data validation
	if (m_item.isEmpty()) m_isValid=false;
	if (m_name.isEmpty()) m_isValid=false;
    
    
        qDebug() << "NAME " << m_name;
        qDebug() << "ITEM " << m_item;
        qDebug() << "ICON " << m_icon;
        qDebug() << "PKG  " << m_package;
}

QString ChoiceGroup::getStringValue(QVariantMap map, QString key) 
{
    if (map.contains(key)) {
        return map[key].toString();
    } else {
        return QString();
    }
}
