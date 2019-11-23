#include <QDebug>
#include "spaceship.h"

#define LENGTH 10

//-------------------------------------------------------------------------------------------------
Spaceship::Spaceship(const QPointF &p, const QList<PxsBody *> &friends)
 : PxsPolygonBody(p,friends)
 , mFireState(0)
{
    mSpin = 1;

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

//-------------------------------------------------------------------------------------------------
bool Spaceship::move(double speed)
{
    if (mFireState)
        mFireState = mFireState == 1 ? 2:1;
    return PxsPolygonBody::move(speed);
}

//-------------------------------------------------------------------------------------------------
void Spaceship::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space) {
        mAcceleration = 0.01;
        mFireState = 1;
    }

    if (event->key() == Qt::Key_Left) {
        mSpin += 0.04;
    }
    if (event->key() == Qt::Key_Right) {
        mSpin -= 0.04;
    }
}

//-------------------------------------------------------------------------------------------------
void Spaceship::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space) {
        mAcceleration = 0;
        mFireState = 0;
    }


}

//-------------------------------------------------------------------------------------------------
void Spaceship::renderModelCentered(QPainter &p) const
{
    if (mFireState) {
        p.save();
        p.translate(0,-3);
        p.scale(1,mFireState == 1 ? 0.7:1.0);
        p.setPen(Qt::yellow);
        p.setBrush(Qt::yellow);
        p.drawEllipse(QPointF(0,0),2,3);
        p.restore();
    }
    PxsPolygonBody::renderModelCentered(p);
}

