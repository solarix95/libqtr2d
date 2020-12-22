#include "swirl.h"
#include "submarine.h"
#include "qtr2dzone.h"
#include "qtr2dcamerarotateeffect.h"
#include <QDebug>

#define RADIUS 10

//-------------------------------------------------------------------------------------------------
Swirl::Swirl(const QPointF &p, Qtr2dZone &zone)
 : Qtr2dBody(p,zone)
 , mCurrent(NULL)
{
    mCollisionRadius = RADIUS;
    setAngle(qrand() % 360);
    setSpin(5*(qrand() % 10)/10.0);
}

//-------------------------------------------------------------------------------------------------
bool Swirl::move(double speed)
{
    setAngle(angle() + spin()*speed);
    return false;
}

//-------------------------------------------------------------------------------------------------
QRectF Swirl::boundingRect() const
{
    QRectF r(-RADIUS,RADIUS,RADIUS*2, -RADIUS*2);
    r.translate(pos());
    return r;
}

//-------------------------------------------------------------------------------------------------
void Swirl::onCollision(Qtr2dBody *pdy)
{
    if (mCurrent)
        return;

    if (dynamic_cast<Submarine*>(pdy) == NULL) // don't react on fishes...!!
        return;

    Qtr2dCameraRotateEffect *eff;
    mCurrent = eff = new Qtr2dCameraRotateEffect(3000);
    connect(mCurrent, SIGNAL(destroyed(QObject*)), this, SLOT(effectDestroyed(QObject*)));
    emit zone().requestCameraEffect(eff);
}

//-------------------------------------------------------------------------------------------------
void Swirl::renderModelCentered(QPainter &p) const
{
    p.setPen(QPen(Qt::blue, 0.3));
    for (int i = 0; i<3*360; i += 5) {
        p.setOpacity(1-i/(3*360.0));
        p.drawPoint(QPointF(0,i/50.0));
        p.rotate(5);
    }
    // p.drawEllipse(QPointF(0,0),RADIUS,RADIUS);
}

//-------------------------------------------------------------------------------------------------
void Swirl::effectDestroyed(QObject *effect)
{
    mCurrent = NULL;
}
