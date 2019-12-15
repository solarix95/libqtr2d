#ifndef ASTEROID_H
#define ASTEROID_H

#include <QVector2D>
#include "pxspolygonbody.h"

class Asteroid : public PxsPolygonBody
{
public:
    Asteroid(const QPointF &p, const QVector2D &velocity, PxsZone &zone);

protected:
    virtual void onCollision(PxsBody *other) override;
};

#endif // ASTEROID_H
