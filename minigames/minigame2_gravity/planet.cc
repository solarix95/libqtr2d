#include <QDebug>
#include "planet.h"

#define RADIUS 50

Planet::Planet(const QPointF &p, PxsZone &zone)
 : PxsBody(p,zone)
{
    mMass = 100;
    spin() = 0.3;
}

QRectF Planet::boundingRect() const
{
    QRectF r(0,0,RADIUS,RADIUS);
    r.translate(pos());
    return r;
}

void Planet::renderModelCentered(QPainter &p) const
{
    p.setPen(QColor(30,0,0));
    p.setBrush(QColor(50,0,0));
    p.drawEllipse(QPointF(0,0),RADIUS,RADIUS);

    p.setPen(QColor(45,0,0));
    p.setBrush(QColor(45,0,0));
    p.drawEllipse(QPointF(RADIUS/2,RADIUS/2),RADIUS/4,RADIUS/5);
    p.drawEllipse(QPointF(0,RADIUS/3),RADIUS/3,RADIUS/3);
    p.drawEllipse(QPointF(RADIUS/3,0),RADIUS/4,RADIUS/4);
}
