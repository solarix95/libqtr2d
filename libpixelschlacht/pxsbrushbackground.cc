#include "pxsbrushbackground.h"

//-------------------------------------------------------------------------------------------------
PxsBrushBackground::PxsBrushBackground(const QBrush &brush)
 : mBrush(brush)
{
}

//-------------------------------------------------------------------------------------------------
void PxsBrushBackground::renderBkgnd(QPainter &p, const QRectF &window)
{
    p.setBrush(mBrush);
    p.drawRect(window);
}

