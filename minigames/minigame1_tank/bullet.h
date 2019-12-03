#ifndef BULLET_H
#define BULLET_H

#include <QVector2D>
#include "pxspolygonbody.h"

class Bullet : public PxsPolygonBody
{
public:
    Bullet(const QPointF &p, const QVector2D &velocity, PxsZone &zone);

protected:
    virtual void collideWith(PxsBody *other) override;
};

#endif
