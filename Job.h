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

#include <QVariantMap>

/** @brief Dummy class
 * 
 * This just exists to have a place to put setConfigurationMap(),
 * corresponding to what Calamares jobs have.
 */
class Job
{
public:
    Job();
    
    /** @brief Fill up the job's configuration with groups.
     */
    void setConfigurationMap( const QVariantMap& );
    
    /** @brief Debugging-aid: dump the configuration. */
    void debug() const;
    
private:
    // a list of vector of ChoiceGroups
    
} ;
