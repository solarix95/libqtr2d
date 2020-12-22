#include "pxsparticle.h"

//-------------------------------------------------------------------------------------------------
PxsParticle::PxsParticle(const QPointF &p, const QVector2D &dir, PxsZone &zone, const QColor &color, int livetimeMs)
 : PxsObject(p, zone)
 , mColor(color)
 , mLivetimeMs(livetimeMs)
{
    velocity() = dir;
    mTime.start();
}

//-------------------------------------------------------------------------------------------------
bool PxsParticle::move(double speed)
{
    if (mTime.elapsed() >= mLivetimeMs)
        deleteLater();
    return PxsObject::move(speed);
}

//-------------------------------------------------------------------------------------------------
QRectF PxsParticle::boundingRect() const
{
    return QRectF();
}

//-------------------------------------------------------------------------------------------------
QColor PxsParticle::color() const
{
    QColor c = mColor;
    c.setAlphaF(1-progress());
    return c;
}

//-------------------------------------------------------------------------------------------------
float PxsParticle::progress() const
{
    return qMin(mTime.elapsed()/(float)mLivetimeMs,1.0f);
}

//-------------------------------------------------------------------------------------------------
float PxsParticle::transparency() const
{
    return 0;

}
