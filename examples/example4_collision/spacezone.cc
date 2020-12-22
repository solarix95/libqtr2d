
#include "qtr2dcamerashakeeffect.h"
#include "qtr2dmassattraction.h"
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
    setGravity(new Qtr2dMassAttraction());
    registerBody(new Asteroid(QPointF(50,50),QVector2D(0.2,0),*this));
    registerBody(new Asteroid(QPointF(150,50),QVector2D(-0.2,0),*this));
}

//-------------------------------------------------------------------------------------------------
void Spacezone::createExplosion(const QPointF &, float)
{
    emit requestCameraEffect(new Qtr2dCameraShakeEffect(0.5,0.5,0.5,0,1000));
}
