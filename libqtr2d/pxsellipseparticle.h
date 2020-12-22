#ifndef PXSELLIPSEPARTICLE_H
#define PXSELLIPSEPARTICLE_H

#include "pxsparticle.h"

class PxsEllipseParticle : public PxsParticle
{
public:
    PxsEllipseParticle(const QPointF &p, const QVector2D &direction, PxsZone &zone, const QColor &c, int livetimeMs, float radius);

protected:
    virtual void renderModelCentered(QPainter &p) const;

protected:
    float mRadius;

};

#endif // PXSELLIPSEPARTICLE_H
