#include <QDebug>

#include "bullet.h"
#include "pxszone.h"

//-------------------------------------------------------------------------------------------------
Bullet::Bullet(const QPointF &p, const QVector2D &v, PxsZone &zone)
 : PxsPolygonBody(p, zone)
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
void Bullet::collideWith(PxsBody *other)
{
    zone().createParticles(boundingRect(),velocity(),50,0.3,Qt::gray,5000);
    zone().createExplosion(pos(),5);
    deleteLater();
}

