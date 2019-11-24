#include <QDebug>
#include "asteroid.h"
#include "pxszone.h"

//-------------------------------------------------------------------------------------------------
Asteroid::Asteroid(const QPointF &p, PxsZone &zone)
 : PxsPolygonBody(p, zone)
{
    spin()     = (-10 + qrand()%20)/20.0;
    velocity() = QVector2D((-10 + qrand()%20)/20.0,(-10 + qrand()%20)/20.0);

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
bool Asteroid::move(double speed)
{
    if (!boundingRect().intersects(QRect(QPoint(0,0),zone().fieldSize()))) {
        deleteLater();
    }

    return PxsPolygonBody::move(speed);
}
