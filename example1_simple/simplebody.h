#ifndef SIMPLEBODY_H
#define SIMPLEBODY_H

#include "pxsbody.h"

class SimpleBody : public PxsBody
{
public:
    SimpleBody(const QPointF &p, PxsZone &zone);

    virtual QRectF boundingRect() const override;

protected:
    virtual void renderModelCentered(QPainter &p) const override;
};

#endif // SIMPLEBODY_H
