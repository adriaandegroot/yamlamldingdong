/*
 *  Copyright (C) 2018 Scott Harvey <scott@spharvey.me>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef LISTQVM_H
#define LISTQVM_H

#include <QVariantMap>
#include <QVariantList>
#include <QString>

/* This class is temporary, just for the sake of listing the contents
* of the QVariantMap
*/

/* Take in a QVariantMap @qvm and begin extracting its contents
 */

class ListQVM
{

public:

 /* Constructor: takes a QVariantMap as initialization parameter.
 */
    ListQVM(QVariantMap q);

 /* First pass at learning to extract keys.
  * I know this should be done by reference,
  * but I'm struggling there and will revamp
  * on my next pass.
  */
    void getKeys(QVariantMap &map);

    QVariantList m_keys;

    QVariantMap m_qvm;

private:



};

#endif // LISTQVM_H
