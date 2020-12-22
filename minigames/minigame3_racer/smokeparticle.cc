#include "smokeparticle.h"

//-------------------------------------------------------------------------------------------------
SmokeParticle::SmokeParticle(const QPointF &p, const QVector2D &direction, Qtr2dZone &zone, const QColor &c, int livetimeMs, float radius)
 : Qtr2dEllipseParticle(p,direction, zone, c, livetimeMs, radius)
 , mStartRadius(radius)
{
}

//-------------------------------------------------------------------------------------------------
bool SmokeParticle::move(double speed)
{
    mRadius = mStartRadius * (1+ 10*progress());
    return Qtr2dEllipseParticle::move(speed);
}
