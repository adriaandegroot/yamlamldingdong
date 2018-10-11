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

class QWidget;

#include <QString>
#include <QVariantMap>

 // grab the value of (k) from map (m), otherwise return zilch, which will trigger an error
    static QString getStringValue(const QVariantMap& m, const QString& k)
    {
        if (m.contains(k)) {
            return m[k].toString();
        } else {
            return QString();
        }
    }

/** @brief Data class for a group of related choices
 * 
 * Created from a variant map which is extracted from YAML.
 */

class ChoiceGroup

{

public:
    
    ChoiceGroup();
    
    ChoiceGroup(const QVariantMap&);
    
private:
    QString m_title;
    QString m_variable;
    
    // and a list of vector of ChoiceItems
} ;
