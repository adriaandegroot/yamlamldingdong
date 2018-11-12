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

#include "MainWindow.h"

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

MainWindow::MainWindow() : QMainWindow(nullptr)
{
    QWidget*w = new QWidget(this);
    setCentralWidget(w);
    
    QBoxLayout* layout = new QVBoxLayout;
    w->setLayout(layout);
    
    layout->addWidget(new QLabel(QString("Derp")));
    
    QPushButton* b = new QPushButton(QString("Quit"));
    layout->addWidget(b);
    connect(b, &QPushButton::clicked, this, &MainWindow::quit);
}

MainWindow::~MainWindow()
{
}
