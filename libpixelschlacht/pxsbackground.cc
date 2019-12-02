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
void PxsBackground::render(QPainter &p)
{
    p.save();
    renderBkgnd(p);
    p.restore();
}

//-------------------------------------------------------------------------------------------------
const PxsZone &PxsBackground::zone() const
{
    Q_ASSERT(mZone);
    return *mZone;
}
