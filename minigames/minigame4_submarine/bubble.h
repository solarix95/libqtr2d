#ifndef BUBBLEPARTICLE_H
#define BUBBLEPARTICLE_H

#include "pxsellipseparticle.h"

class Bubble : public PxsEllipseParticle
{
public:
    Bubble(const QPointF &p, const QVector2D &direction, PxsZone &zone, const QColor &c, int livetimeMs, float radius);

    virtual bool move(double speed) override;

private:
    float mStartRadius;
};

#endif
