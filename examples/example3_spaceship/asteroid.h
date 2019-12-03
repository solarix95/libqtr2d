#ifndef ASTEROID_H
#define ASTEROID_H

#include "pxspolygonbody.h"

class Asteroid : public PxsPolygonBody
{
public:
    Asteroid(const QPointF &p, PxsZone &zone);

    virtual bool     move(double speed);
};

#endif // ASTEROID_H
