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

#include "ListQVM.h"

#include <QVariantMap>
#include <QVariantList>
#include <QString>
#include <QDebug>

// This class is temporary at the moment, just for the sake of opening and
// listing the contents of the QVariantMap.

ListQVM::ListQVM(QVariantMap q) :
    m_keys(),
    m_qvm()
{

    getKeys(q);

}


void ListQVM::getKeys(QVariantMap& map) {

    QVariant top =  map["contents"].toList()[0];

    qDebug() << top.toString();


}
