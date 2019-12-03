#ifndef UFO_H
#define UFO_H

#include <QVector2D>
#include "pxspolygonbody.h"

class Ufo : public PxsPolygonBody
{
public:
    Ufo(const QPointF &p, const QVector2D &velocity, PxsZone &zone);

protected:
    virtual void collideWith(PxsBody *other) override;
};

#endif
