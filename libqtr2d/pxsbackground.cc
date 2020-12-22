#include "pxsbackground.h"

//-------------------------------------------------------------------------------------------------
PxsBackground::PxsBackground()
 : mZone(NULL)
{
}

//-------------------------------------------------------------------------------------------------
void PxsBackground::setZone(const PxsZone *zone)
{
    mZone = zone;
    Q_ASSERT(mZone);
}

//-------------------------------------------------------------------------------------------------
bool PxsBackground::testCollision(PxsObject *) const
{
    return false;
}

//-------------------------------------------------------------------------------------------------
void PxsBackground::render(QPainter &p, const QRectF &window)
{
    p.save();
    renderBkgnd(p, window);
    p.restore();
}

//-------------------------------------------------------------------------------------------------
const PxsZone &PxsBackground::zone() const
{
    Q_ASSERT(mZone);
    return *mZone;
}
