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
#include <QDebug>

ChoiceGroup::ChoiceGroup()
{
}

ChoiceGroup::ChoiceGroup( const QVariantMap& initMap)
{
    // Extract title & variable
   
    QString m_title = initMap["title"].toString();
    QString m_variable = initMap["variable"].toString();
    
    // Extract list of items
    // *** I know how to extract them; unsure how to store them
}

QString ChoiceGroup::getTitle() {
    return m_title;
}

QString ChoiceGroup::getVariable() {
    return m_variable;
}
