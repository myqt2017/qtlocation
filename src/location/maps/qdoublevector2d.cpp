/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtGui module of the Qt Toolkit.
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

#include "qdoublevector2d_p.h"
#include "qdoublevector3d_p.h"
#include <QtCore/qdebug.h>
#include <QtCore/qmath.h>

QT_BEGIN_NAMESPACE

QDoubleVector2D::QDoubleVector2D(const QDoubleVector3D& vector)
{
    xp = vector.xp;
    yp = vector.yp;
}

double QDoubleVector2D::length() const
{
    return qSqrt(xp * xp + yp * yp);
}

double QDoubleVector2D::lengthSquared() const
{
    return xp * xp + yp * yp;
}

QDoubleVector2D QDoubleVector2D::normalized() const
{
    // Need some extra precision if the length is very small.
    double len = double(xp) * double(xp) +
                 double(yp) * double(yp);
    if (qFuzzyIsNull(len - 1.0))
        return *this;
    else if (!qFuzzyIsNull(len))
        return *this / qSqrt(len);
    else
        return QDoubleVector2D();
}

void QDoubleVector2D::normalize()
{
    // Need some extra precision if the length is very small.
    double len = double(xp) * double(xp) +
                 double(yp) * double(yp);
    if (qFuzzyIsNull(len - 1.0) || qFuzzyIsNull(len))
        return;

    len = qSqrt(len);

    xp /= len;
    yp /= len;
}

double QDoubleVector2D::dotProduct(const QDoubleVector2D& v1, const QDoubleVector2D& v2)
{
    return v1.xp * v2.xp + v1.yp * v2.yp;
}

QDoubleVector3D QDoubleVector2D::toVector3D() const
{
    return QDoubleVector3D(xp, yp, 0.0);
}

#ifndef QT_NO_DEBUG_STREAM

QDebug operator<<(QDebug dbg, const QDoubleVector2D &vector)
{
    dbg.nospace() << "QDoubleVector2D(" << vector.x() << ", " << vector.y() << ')';
    return dbg.space();
}

#endif

#ifndef QT_NO_DATASTREAM

QDataStream &operator<<(QDataStream &stream, const QDoubleVector2D &vector)
{
    stream << double(vector.x()) << double(vector.y());
    return stream;
}

QDataStream &operator>>(QDataStream &stream, QDoubleVector2D &vector)
{
    double x, y;
    stream >> x;
    stream >> y;
    vector.setX(double(x));
    vector.setY(double(y));
    return stream;
}

#endif // QT_NO_DATASTREAM

QT_END_NAMESPACE