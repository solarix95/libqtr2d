#ifndef PXSBRUSHBACKGROUND_H
#define PXSBRUSHBACKGROUND_H

#include <QBrush>
#include "pxsbackground.h"

class PxsBrushBackground : public PxsBackground
{
public:
    PxsBrushBackground(const QBrush &brush);

protected:
    virtual void renderBkgnd(QPainter &p, const QRectF &window);

private:
    QBrush mBrush;
};

#endif // PXSBRUSHBACKGROUND_H
