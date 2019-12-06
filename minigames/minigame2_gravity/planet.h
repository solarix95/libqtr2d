#ifndef PLANET_H
#define PLANET_H

#include "pxsbody.h"

class Planet : public PxsBody
{
public:
    Planet(const QPointF &p, PxsZone &zone);

    virtual QRectF   boundingRect() const;

protected:
    virtual void renderModelCentered(QPainter &p) const;

};

#endif // PLANET_H
