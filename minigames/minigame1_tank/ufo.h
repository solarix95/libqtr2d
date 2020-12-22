#ifndef UFO_H
#define UFO_H

#include <QVector2D>
#include "qtr2dpolygonbody.h"

class Ufo : public Qtr2dPolygonBody
{
public:
    Ufo(const QPointF &p, const QVector2D &velocity, Qtr2dZone &zone);

protected:
    virtual void collideWith(Qtr2dBody *other) override;
};

#endif
