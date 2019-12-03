#ifndef TANK_H
#define TANK_H

#include <QVector2D>
#include "pxspolygonbody.h"

class Tank : public PxsPolygonBody
{
public:
    Tank(const QPointF &p, const QVector2D &velocity, PxsZone &zone);

protected:
    virtual void collideWith(PxsBody *other) override;
};

#endif
