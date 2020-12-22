#ifndef BUBBLEPARTICLE_H
#define BUBBLEPARTICLE_H

#include "qtr2dellipseparticle.h"

class Bubble : public Qtr2dEllipseParticle
{
public:
    Bubble(const QPointF &p, const QVector2D &direction, Qtr2dZone &zone, const QColor &c, int livetimeMs, float radius);

    virtual bool move(double speed) override;

private:
    float mStartRadius;
};

#endif
