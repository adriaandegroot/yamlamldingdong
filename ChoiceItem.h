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
#ifndef YDD_CHOICEITEM_H
#define YDD_CHOICEITEM_H

class QWidget;

#include <QVariantMap>
#include <QString>

// Grab the value of (k) from map (m), otherwise return an empty string, 
// which will trigger an error later. Since this is used all over,
// give it a full definition in every translation unit but try to keep
// it inline.
static inline QString getStringValue(const QVariantMap& m, const QString& k)
{
    if (m.contains(k)) {
        return m[k].toString();
    } else {
        return QString();
    }
}

/** @brief Data class for a single choice item
 * 
 * Created from a variant map which is extracted from YAML.
 * An item has an id, and a handful of optional attributes.
 * An item may be invalid (e.g. the id is missing). The
 * default constructor constructs an invalid item.
 */
class ChoiceItem
{
public:
    ChoiceItem();
    ChoiceItem( const QVariantMap& );
    
    bool isValid() const { return m_isValid; }
    
    // TODO: accessors for the other fields
    
private:
    bool m_isValid;
    QString m_item;
    QString m_icon;
    QString m_package;
    QString m_name;
    QString m_title;
} ;

#endif
