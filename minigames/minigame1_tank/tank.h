#ifndef TANK_H
#define TANK_H

#include <QVector2D>
#include "qtr2dpolygonbody.h"

class Tank : public Qtr2dPolygonBody
{
public:
    Tank(const QPointF &p, const QVector2D &velocity, Qtr2dZone &zone);

protected:
    virtual void collideWith(Qtr2dBody *other) override;
};

#endif
