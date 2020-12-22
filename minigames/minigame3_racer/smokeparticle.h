#ifndef SMOKEPARTICLE_H
#define SMOKEPARTICLE_H

#include "qtr2dellipseparticle.h"

class SmokeParticle : public Qtr2dEllipseParticle
{
public:
    SmokeParticle(const QPointF &p, const QVector2D &direction, Qtr2dZone &zone, const QColor &c, int livetimeMs, float radius);

    virtual bool move(double speed) override;

private:
    float mStartRadius;
};

#endif // SMOKEPARTICLE_H
