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
#include <QList>
#include <QString>
#include <QDebug>
#include <QMapIterator>


// This class is temporary at the moment, just for the sake of opening and
// listing the contents of the QVariantMap.

ListQVM::ListQVM(QVariantMap q) :
    m_keys(),
    m_qvm()
{

    getKeys(q);

}


void ListQVM::getKeys(QVariantMap& map) {

    QVariantList theChoices = map["choices"].toList();

   for (auto tm : theChoices) {
       
       QVariantMap topMap = tm.toMap();
     
        QMapIterator<QString, QVariant> choice(topMap);
            while (choice.hasNext()) {
                choice.next();
                
                // skip "items" as we're going to pull them as a separate list
                if (choice.key() == "items") {
                    continue;
                }                
                qDebug() << choice.key() << ": " << choice.value().toString();
                
            }
        
        qDebug() << "items:";
        QVariantList itemList = topMap["items"].toList();
        for (auto im : itemList) {
             qDebug() << " -"; 
             QVariantMap itemMap = im.toMap();
             QMapIterator<QString, QVariant> item(itemMap);
                while (item.hasNext()) {
                item.next();
                qDebug() << "  " << item.key() << ": " << item.value().toString();
                
            }
        }
       
       // visual break between "choices"
       qDebug() << "---------";
    
    }
}




