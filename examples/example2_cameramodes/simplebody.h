#ifndef SIMPLEBODY_H
#define SIMPLEBODY_H

#include "qtr2dbody.h"

class SimpleBody : public Qtr2dBody
{
public:
    SimpleBody(const QPointF &p, Qtr2dZone &zone);

    virtual QRectF boundingRect() const override;

protected:
    virtual void renderModelCentered(QPainter &p) const override;
};

#endif // SIMPLEBODY_H
