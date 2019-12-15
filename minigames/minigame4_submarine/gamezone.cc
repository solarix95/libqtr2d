
#include "pxscamerashakeeffect.h"
#include "pxsgravitylist.h"
#include "gamezone.h"
#include "gamemap.h"
#include "background.h"
#include "submarine.h"

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
    setGravity(new PxsGravityList(PxsForce(0,-1)));
    appendBackground(new Background(new GameMap(":/maps/simple.png")));

    mRacer   = registerBody(new Submarine(QPointF(2500,2500),*this), true);
}

//-------------------------------------------------------------------------------------------------
void GameZone::createExplosion(const QPointF &pos, float force)
{
    emit requestCameraEffect(new PxsCameraShakeEffect(5,5,5,0,2000));
}

