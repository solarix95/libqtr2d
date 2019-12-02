#ifndef PXSDEBUGBACKGROUND_H
#define PXSDEBUGBACKGROUND_H

#include "pxsbackground.h"

class PxsDebugBackground : public PxsBackground
{
public:
    PxsDebugBackground(QColor color, int raster, float penSize);

  protected:
    virtual void renderBkgnd(QPainter &p);

private:
    QColor mColor;
    int    mRaster;
    float  mPenSize;

};

#endif // PXSDEBUGBACKGROUND_H
