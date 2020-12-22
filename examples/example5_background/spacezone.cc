
#include "qtr2dcamerashakeeffect.h"
#include "spacezone.h"
#include "asteroid.h"

//-------------------------------------------------------------------------------------------------
Spacezone::Spacezone()
{
}

Spacezone::~Spacezone()
{
}

//-------------------------------------------------------------------------------------------------
void Spacezone::init()
{
    setFieldSize(QSize(400,300));
    registerBody(new Asteroid(QPointF(50,150),QVector2D(0.3,0),*this));
    registerBody(new Asteroid(QPointF(350,150),QVector2D(-0.3,0),*this));
}

//-------------------------------------------------------------------------------------------------
void Spacezone::createExplosion(const QPointF &pos, float force)
{
    emit requestCameraEffect(new Qtr2dCameraShakeEffect(0.5,0.5,0.5,0,1000));
}
