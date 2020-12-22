#ifndef ASTEROID_H
#define ASTEROID_H

#include <QVector2D>
#include "qtr2dpolygonbody.h"

class Asteroid : public Qtr2dPolygonBody
{
public:
    Asteroid(const QPointF &p, const QVector2D &velocity, Qtr2dZone &zone);

protected:
    virtual void onCollision(Qtr2dBody *other) override;

};

#endif // ASTEROID_H
