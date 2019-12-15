
#include "pxscamerashakeeffect.h"
#include "gamezone.h"
#include "background.h"
#include "racer.h"

//-------------------------------------------------------------------------------------------------
GameZone::GameZone()
 : mRacer(NULL)
{
}

//-------------------------------------------------------------------------------------------------
GameZone::~GameZone()
{
}

//-------------------------------------------------------------------------------------------------
void GameZone::init()
{
    setFieldSize(QSize(5000,5000));
    appendBackground(new Background(5000,5000,3000));

    mRacer   = registerBody(new Racer(QPointF(2500,2500),*this), true);
}

//-------------------------------------------------------------------------------------------------
void GameZone::createExplosion(const QPointF &pos, float force)
{
    emit requestCameraEffect(new PxsCameraShakeEffect(5,5,5,0,2000));
}

