#include "smokeparticle.h"

//-------------------------------------------------------------------------------------------------
SmokeParticle::SmokeParticle(const QPointF &p, const QVector2D &direction, PxsZone &zone, const QColor &c, int livetimeMs, float radius)
 : PxsEllipseParticle(p,direction, zone, c, livetimeMs, radius)
 , mStartRadius(radius)
{
}

//-------------------------------------------------------------------------------------------------
bool SmokeParticle::move(double speed)
{
    mRadius = mStartRadius * (1+ 10*progress());
    return PxsEllipseParticle::move(speed);
}
