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

#ifndef YDD_CHOICEGROUP_H
#define YDD_CHOICEGROUP_H


#include <QVariantMap>
#include <QString>

class ChoiceGroup

{
public:
    
    ChoiceGroup();    
    ChoiceGroup(const QVariantMap&);
    QString m_name;
    QString m_item;
    QString m_icon;
    QString m_package;

/** Constructors/accessors for individual parameters
 * 
 */
    bool valid() const { return m_isValid; }
    QString title() const { return m_title; }
    QString variable() const { return m_variable; }
    QVariantList m_items;
    
private:
    bool m_isValid;
    QString m_title;
    QString m_variable;
    void validateItems(QVariantMap& map);
    QString getStringValue(QVariantMap map, QString key);
   
    // and a list of vector of ChoiceItems
    // This now makes perfect sense... it's QList<T>, but T is a ChoiceItem
    // instead of something "ordinary" like a QVariant
    // ... but I can't figure out how to return the value
    //QList<ChoiceItem> m_items;

} ;

#endif
