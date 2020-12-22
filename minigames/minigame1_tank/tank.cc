#include <QDebug>

#include "tank.h"
#include "qtr2dzone.h"

//-------------------------------------------------------------------------------------------------
Tank::Tank(const QPointF &p, const QVector2D &v, Qtr2dZone &zone)
 : Qtr2dPolygonBody(p, zone)
{
    spin()     = (-10 + qrand()%20)/20.0;
    velocity() = v;

    setPolygons(Polygons() << Polygon(QPen(Qt::darkGray,0.1),
                                      Qt::gray,
                                      Points() << QPointF(0 , 5)
                                               << QPointF(1 , 4)
                                               << QPointF(3 , 1)
                                               << QPointF(5 , 0)
                                               << QPointF(2 , -3)
                                               << QPointF(0 , -6)
                                               << QPointF(-3, -5)
                                               << QPointF(-5, -1)
                                      << QPointF(-2, 3)));
}

//-------------------------------------------------------------------------------------------------
void Tank::collideWith(Qtr2dBody *other)
{
    zone().createParticles(boundingRect(),velocity(),50,0.3,Qt::gray,5000);
    zone().createExplosion(pos(),5);
    deleteLater();
}

