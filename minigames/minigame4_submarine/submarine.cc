#include <QDebug>
#include "submarine.h"
#include "bubble.h"

#define LENGTH 10
#define ORANGE      QColor("#FFA500")
#define DARK_ORANGE QColor("#FD6A02")

//-------------------------------------------------------------------------------------------------
Submarine::Submarine(const QPointF &p, PxsZone &zone)
 : PxsPolygonBody(p,zone)
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
    return PxsPolygonBody::move(speed);
}

//-------------------------------------------------------------------------------------------------
void Submarine::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space) {
        mAcceleration = 0.1;
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
    PxsPolygonBody::renderModelCentered(p);

}


//-------------------------------------------------------------------------------------------------
void Submarine::accelerate(double speed)
{
    float currentSpeed = velocity().length();
    currentSpeed += mAcceleration*speed;
    if (currentSpeed <= 0)
        currentSpeed = 0;
    if (currentSpeed > 2)
        currentSpeed = 2;
    QPointF v(0,1);
    QMatrix   m;
    m.rotate(angle());
    v = (v*m)*currentSpeed;
    velocity() = QVector2D(v.x(), v.y());
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


