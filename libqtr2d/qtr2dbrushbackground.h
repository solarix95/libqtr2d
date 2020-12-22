#ifndef PXSBRUSHBACKGROUND_H
#define PXSBRUSHBACKGROUND_H

#include <QBrush>
#include "qtr2dbackground.h"

class PxsBrushBackground : public Qtr2dBackground
{
public:
    PxsBrushBackground(const QBrush &brush);

protected:
    virtual void renderBkgnd(QPainter &p, const QRectF &window);

private:
    QBrush mBrush;
};

#endif // PXSBRUSHBACKGROUND_H
