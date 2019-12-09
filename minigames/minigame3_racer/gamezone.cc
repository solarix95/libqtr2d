
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
    setFieldSize(QSize(1600,1200));
    appendBackground(new Background(1600,1200,600));

    mRacer   = registerBody(new Racer(QPointF(600,600),*this), true);
}

//-------------------------------------------------------------------------------------------------
void GameZone::createExplosion(const QPointF &pos, float force)
{
    emit requestCameraEffect(new PxsCameraShakeEffect(5,5,5,0,2000));
}

