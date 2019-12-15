#include "bubble.h"

//-------------------------------------------------------------------------------------------------
Bubble::Bubble(const QPointF &p, const QVector2D &direction, PxsZone &zone, const QColor &c, int livetimeMs, float radius)
 : PxsEllipseParticle(p,direction, zone, c, livetimeMs, radius)
 , mStartRadius(radius)
{
}

//-------------------------------------------------------------------------------------------------
bool Bubble::move(double speed)
{
    mRadius = mStartRadius * (1+ 10*progress());
    velocity() += QVector2D(0,0.01);
    return PxsEllipseParticle::move(speed);
}
