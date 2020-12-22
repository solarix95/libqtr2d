#include "bubble.h"

//-------------------------------------------------------------------------------------------------
Bubble::Bubble(const QPointF &p, const QVector2D &direction, Qtr2dZone &zone, const QColor &c, int livetimeMs, float radius)
 : Qtr2dEllipseParticle(p,direction, zone, c, livetimeMs, radius)
 , mStartRadius(radius)
{
}

//-------------------------------------------------------------------------------------------------
bool Bubble::move(double speed)
{
    mRadius = mStartRadius * (1+ 10*progress());
    velocity() += QVector2D(0,0.01);
    return Qtr2dEllipseParticle::move(speed);
}
