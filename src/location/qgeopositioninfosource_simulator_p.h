/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the Qt Mobility Components.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QGEOPOSITIONINFOSOURCESIMULATOR_H
#define QGEOPOSITIONINFOSOURCESIMULATOR_H

#include "qgeopositioninfosource.h"
#include "qgeopositioninfo.h"
#include "qlocationdata_simulator_p.h"

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE
class QTimer;

class QGeoPositionInfoSourceSimulator : public QGeoPositionInfoSource
{
    Q_OBJECT
public:
    QGeoPositionInfoSourceSimulator(QObject *parent = 0);
    ~QGeoPositionInfoSourceSimulator();

    QGeoPositionInfo lastKnownPosition(bool fromSatellitePositioningMethodsOnly = false) const;
    PositioningMethods supportedPositioningMethods() const;

    void setUpdateInterval(int msec);
    int minimumUpdateInterval() const;

public Q_SLOTS:
    void startUpdates();
    void stopUpdates();

    void requestUpdate(int timeout = 0);

private slots:
    void updatePosition();
private:
    Q_DISABLE_COPY(QGeoPositionInfoSourceSimulator);
    QTimer *timer;
    QTimer *requestTimer;
    QGeoPositionInfo lastPosition;
};

QT_END_NAMESPACE

#endif // QGEOPOSITIONINFOSOURCESIMULATOR_H
