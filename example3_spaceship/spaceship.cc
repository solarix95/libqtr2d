#include <QDebug>
#include "spaceship.h"

#define LENGTH 10

//-------------------------------------------------------------------------------------------------
Spaceship::Spaceship(const QPointF &p, const QList<PxsBody *> &friends)
 : PxsPolygonBody(p,friends)
{
    mSpin = 0.3;

    setPolygons(Polygons() << Polygon(QPen(Qt::blue,0.1),
                                      Qt::gray,
                                      Points() << QPointF(-1, 7)
                                               << QPointF( 0, 12)
                                               << QPointF( 1, 7)
                                               << QPointF( 1.5,-3)
                                               << QPointF(-1.5,-3))
                           << Polygon(QPen(Qt::blue,0.1),
                                      Qt::gray,
                                      Points() << QPointF(-1, 5)
                                               << QPointF(-3, 0)
                                               << QPointF(-4, 1)
                                               << QPointF(-4,-3)
                                               << QPointF(-1,-2.5))
                           << Polygon(QPen(Qt::blue,0.1),
                                      Qt::gray,
                                      Points() << QPointF( 1, 5)
                                               << QPointF( 3, 0)
                                               << QPointF( 4, 1)
                                               << QPointF( 4,-3)
                                               << QPointF( 1,-2.5))
                                      );
}

