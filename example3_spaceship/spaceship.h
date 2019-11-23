#ifndef SIMPLEBODY_H
#define SIMPLEBODY_H

#include "pxspolygonbody.h"

class Spaceship : public PxsPolygonBody
{
public:
    Spaceship(const QPointF &p, const QList<PxsBody*> &friends);
};

#endif // SIMPLEBODY_H
