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
    c.setAlphaF(qMax(1-mTime.elapsed()/(float)mLivetimeMs,0.0f));
    return c;
}

//-------------------------------------------------------------------------------------------------
float PxsParticle::transparency() const
{
    return 0;

}
