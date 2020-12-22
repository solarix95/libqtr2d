#include <QDebug>
#include "qtr2dzone.h"
#include "submarine.h"
#include "bubble.h"

#define LENGTH 10
#define ORANGE      QColor("#FFA500")
#define DARK_ORANGE QColor("#FD6A02")

//-------------------------------------------------------------------------------------------------
Submarine::Submarine(const QPointF &p, Qtr2dZone &zone)
 : Qtr2dPolygonBody(p,zone)
{
    mCollisionRadius = 9;

    connect(&mBubbleTimer, SIGNAL(timeout()), this, SLOT(bubble()));

    setPolygons(Polygons() << Polygon(QPen(ORANGE,0.1),
                                      ORANGE,
                                      Points() << QPointF( -7  ,   -4)
                                               << QPointF( -9  ,   -2)
                                               << QPointF( -9  ,   -1)
                                               << QPointF(  7  ,   -1)
                                               << QPointF(  7  ,   -2)
                                               << QPointF(  5  ,   -4))
                           << Polygon(QPen(Qt::yellow,0.1),
                                      Qt::yellow,
                                      Points() << QPointF( -9  ,   -1)
                                               << QPointF( -9  ,    3)
                                               << QPointF( -8.5,    3)
                                               << QPointF( -6  ,  2.5)
                                               << QPointF( -5  ,    4)
                                               << QPointF( -1  ,    4)
                                               << QPointF(  1  ,    6)
                                               << QPointF(  3  ,    6)
                                               << QPointF(  4  ,    4)
                                               << QPointF(  6 ,     3)
                                               << QPointF(  7  ,    2)
                                               << QPointF(  7  ,   -1)
                                      )

                );
    mBubbleTimer.start(25);
}

//-------------------------------------------------------------------------------------------------
bool Submarine::move(double speed)
{
    //if (velocity().length() > 0)
    //    angle() += mSteering * speed * 2;
    // velocity() += QVector2D(0,-2 * speed);
    angle() = (velocity().y() + 0.2) * 30 * speed;
    return Qtr2dPolygonBody::move(speed);
}

//-------------------------------------------------------------------------------------------------
void Submarine::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space) {
        if (mAcceleration > 0)
            return;

        mAcceleration = 0.1;
        velocity() = QVector2D(1,0);
    }
}

//-------------------------------------------------------------------------------------------------
void Submarine::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space) {
        mAcceleration = -0.02;
    }
}

//-------------------------------------------------------------------------------------------------
void Submarine::renderModelCentered(QPainter &p) const
{
    Qtr2dPolygonBody::renderModelCentered(p);
}

//-------------------------------------------------------------------------------------------------
void Submarine::accelerate(double speed)
{
    float vy = mAcceleration > 0 ? 0.2f : qMax(velocity().y(),-0.5f);
    float vx = qMin(qMax(velocity().x()+float(mAcceleration*speed),0.0f),1.0f);
    velocity() = QVector2D(vx,vy);
}

//-------------------------------------------------------------------------------------------------
void Submarine::onCollision(Qtr2dBody *other)
{
    if (!other) {
        // updatePosition(pos() + QPointF(0,50));

        zone().createExplosion(pos(),2);
        updatePosition(QPointF(pos().x() - 10*velocity().x(), pos().y() - 10*velocity().y()));
        velocity() = QVector2D(0,0);
    }
}

//-------------------------------------------------------------------------------------------------
void Submarine::bubble()
{
    if (mAcceleration <= 0)
        return;

    QMatrix m;
    m.rotate(angle());
    QPointF relativePos(-10,0);
    relativePos = relativePos * m;

    for (int i=0; i<5;i++) {
        QVector2D dir = QVector2D(-1,0); // 50+qrand()%100)/100.0);
        m.reset();
        m.rotate(-10 + qrand()%20);
        dir = QVector2D(dir.toPointF() * m);
        emit created(new Bubble(pos() + relativePos,dir,zone(),Qt::blue,2000,0.06));
    }
}


