#ifndef ASTEROID_H
#define ASTEROID_H

#include "qtr2dpolygonbody.h"

class Asteroid : public Qtr2dPolygonBody
{
public:
    Asteroid(const QPointF &p, Qtr2dZone &zone);

    virtual bool     move(double speed);
};

#endif // ASTEROID_H
