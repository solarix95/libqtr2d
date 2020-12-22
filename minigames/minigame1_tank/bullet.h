#ifndef BULLET_H
#define BULLET_H

#include <QVector2D>
#include "qtr2dpolygonbody.h"

class Bullet : public Qtr2dPolygonBody
{
public:
    Bullet(const QPointF &p, const QVector2D &velocity, Qtr2dZone &zone);

protected:
    virtual void collideWith(Qtr2dBody *other) override;
};

#endif
