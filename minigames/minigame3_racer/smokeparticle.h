#ifndef SMOKEPARTICLE_H
#define SMOKEPARTICLE_H

#include "pxsellipseparticle.h"

class SmokeParticle : public PxsEllipseParticle
{
public:
    SmokeParticle(const QPointF &p, const QVector2D &direction, PxsZone &zone, const QColor &c, int livetimeMs, float radius);

    virtual bool move(double speed) override;

private:
    float mStartRadius;
};

#endif // SMOKEPARTICLE_H
