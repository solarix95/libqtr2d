#include <QDebug>
#include "racer.h"
#include "smokeparticle.h"

#define LENGTH 10
#define ORANGE      QColor("#FFA500")
#define DARK_ORANGE QColor("#FD6A02")
#define BROWN       QColor("#CD853F")

//-------------------------------------------------------------------------------------------------
Racer::Racer(const QPointF &p, Qtr2dZone &zone)
 : Qtr2dPolygonBody(p,zone)
 , mFireState(0)
 , mWheelPos(0)
 , mSteering(0)
 , mRoofSignalAngle(0)
{
    mCollisionRadius = 12;

    connect(&mSmokeTimer, SIGNAL(timeout()), this, SLOT(smoke()));

    setPolygons(Polygons() << Polygon(QPen(ORANGE,0.1),
                                      ORANGE,
                                      Points() << QPointF(  -3 ,    0)
                                               << QPointF(   3 ,    0)
                                               << QPointF(   3 ,  -11)
                                               << QPointF(  -3 ,  -11))
                           << Polygon(QPen(DARK_ORANGE,0.1),
                                      DARK_ORANGE,
                                      Points() << QPointF(  -2   , -1)
                                               << QPointF(  -2.5 , -1)
                                               << QPointF(  -2.5 , -10)
                                               << QPointF(  -2   , -10))
                           << Polygon(QPen(Qt::gray,0.1),
                                      Qt::white,
                                      Points() << QPointF(  -3 ,     0)
                                               << QPointF(  -3 ,     8)
                                               << QPointF(   3 ,     8)
                                               << QPointF(   3 ,     0))
                           << Polygon(QPen(Qt::white,0.5),
                                      ORANGE,
                                      Points() << QPointF(  -3 ,     8 )
                                               << QPointF(   3 ,     8 )
                                               << QPointF(   3 ,     10)
                                               << QPointF(  -3 ,     10))
                           << Polygon(QPen(BROWN,0.1),
                                      BROWN,
                                      Points() << QPointF(  -3 ,     10 )
                                               << QPointF(   3 ,     10 )
                                               << QPointF(   3 ,     12)
                                               << QPointF(  -3 ,     12))
                );
}

//-------------------------------------------------------------------------------------------------
bool Racer::move(double speed)
{
    mRoofSignalAngle += speed * 3;
    mWheelPos += velocity().length()/3.0 * speed;
    if (mWheelPos >= 2)
        mWheelPos = 0;

    if (velocity().length() > 0)
        angle() += mSteering * speed * 2;
    return Qtr2dPolygonBody::move(speed);
}

//-------------------------------------------------------------------------------------------------
void Racer::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space) {
        mAcceleration = 0.1;
        mFireState = 1;
    }

    if (event->key() == Qt::Key_Left)
        mSteering = 1;

    if (event->key() == Qt::Key_Right)
        mSteering = -1;
}

//-------------------------------------------------------------------------------------------------
void Racer::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space) {
        mAcceleration = -0.02;
        mFireState = 0;
    }
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_Right) {
        mSteering = 0;
    }
}

//-------------------------------------------------------------------------------------------------
void Racer::renderModelCentered(QPainter &p) const
{
    Qtr2dPolygonBody::renderModelCentered(p);

    renderWheel(p, QPointF(-4,-5));
    renderWheel(p, QPointF( 4,-5));
    renderWheel(p, QPointF(-4, 6));
    renderWheel(p, QPointF( 4, 6));

    renderRoofSignal(p);
}

//-------------------------------------------------------------------------------------------------
void Racer::accelerate(double speed)
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

    int smokeInterval = 1000/(10 + currentSpeed * 10);
    if (mSmokeTimer.interval() != smokeInterval) {
        mSmokeTimer.setInterval(smokeInterval);
        if (mSmokeTimer.interval() > 0 && !mSmokeTimer.isActive())
            mSmokeTimer.start();
        if (mSmokeTimer.interval() == 0 && mSmokeTimer.isActive())
            mSmokeTimer.stop();
    }
}

//-------------------------------------------------------------------------------------------------
void Racer::smoke()
{
    QMatrix m;
    m.rotate(angle());
    QPointF relativePos(-2,-12);
    relativePos = relativePos * m;

    for (int i=0; i<5;i++) {
        QVector2D dir = -0.1 * (velocity().normalized()*(50+qrand()%100)/100.0);
        if (dir.length() < 0.01) {
            m.reset();
            m.rotate(angle());
            dir = QVector2D(QPointF(0,-0.1) * m);
        }
        m.reset();
        m.rotate(-40 + qrand()%80);
        dir = QVector2D(dir.toPointF() * m);
        emit created(new SmokeParticle(pos() + relativePos,dir,zone(),Qt::gray,1000,0.2));
    }
}

//-------------------------------------------------------------------------------------------------
void Racer::renderWheel(QPainter &p, const QPointF &pos) const
{
    p.save();
    p.translate(pos);

    p.setPen(QPen(Qt::black,0.1));
    p.setBrush(Qt::gray);
    p.drawRect(QRectF(-1,4,2,-8));

    // p.setWindow(QRect(-1,4,2,-8));

    p.setClipRect(QRect(-1,4,2,-8));
    p.setPen(QPen(Qt::black,0.2));
    p.translate(0,mWheelPos);
    for (int i=0; i<12; i++) {
        p.drawLine(-1,4 -i,1,4 -i);
    }
    p.restore();
}

void Racer::renderRoofSignal(QPainter &p) const
{
    p.save();
    p.translate(0,6);
    p.rotate(mRoofSignalAngle);
    p.setPen(QPen(Qt::white,0.1));
    p.setBrush(Qt::red);
    p.drawPolygon(QPolygonF(QVector<QPointF>() << QPointF(0,0) << QPointF(1.5,1) << QPointF(1.5,-1)));
    p.drawPolygon(QPolygonF(QVector<QPointF>() << QPointF(0,0) << QPointF(-1.5,1) << QPointF(-1.5,-1)));
    p.setPen(QPen(Qt::red,0.3));
    p.setBrush(QBrush());
    p.drawEllipse(QPointF(0,0),1.5,1.5);
    p.restore();
}

