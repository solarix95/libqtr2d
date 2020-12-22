#include <QDebug>
#include "fish.h"
#include <math.h>

Fish::Fish(const QPointF &p, Qtr2dZone &zone)
 : Qtr2dBody(p,zone)
{
    mCollisionRadius = 20;
    mLiveTime = 0;
    setVelocity(QVector2D(qrand() % 2 ? 1:-1,0));
    mColor = (QList<QColor>() << Qt::red << Qt::gray << Qt::yellow)[qrand() % 3];
}

bool Fish::move(double speed)
{
    mLiveTime += speed/10;
    setPos(pos() + QPointF(velocity().x(),velocity().y()));
    setAngle(10*sin(mLiveTime));
    testCollision();
    return false;
}

QRectF Fish::boundingRect() const
{
    QRectF r(-10,5,20,-10);
    r.translate(pos());
    return r;
}

void Fish::onCollision(Qtr2dBody *pdy)
{
    if (pdy && (qrand()%20))
        return;
    setVelocity(QVector2D(velocity().x() * -1, 0));
}

void Fish::renderModelCentered(QPainter &p) const
{
    p.scale(velocity().x(),1);
    p.translate(0,angle()/5);
    p.setBrush(mColor);
    p.setPen(QPen(mColor,0.1));
    p.drawEllipse(QPointF(-2,0),5,2.5);
    p.drawPolygon(QPolygonF(QVector<QPointF>() << QPointF(0,0) << QPointF(-8,2.5) << QPointF(-8,-2.5)));
    p.setBrush(Qt::black);
    p.drawEllipse(QPointF(2,0),0.5,0.5);
}
