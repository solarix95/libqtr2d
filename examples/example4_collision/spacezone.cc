
#include "pxscamerashakeeffect.h"
#include "pxsmassattraction.h"
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
    setFieldSize(QSize(200,100));
    setGravity(new PxsMassAttraction());
    registerBody(new Asteroid(QPointF(50,50),QVector2D(0.2,0),*this));
    registerBody(new Asteroid(QPointF(150,50),QVector2D(-0.2,0),*this));
}

//-------------------------------------------------------------------------------------------------
void Spacezone::createExplosion(const QPointF &, float)
{
    emit requestCameraEffect(new PxsCameraShakeEffect(0.5,0.5,0.5,0,1000));
}
