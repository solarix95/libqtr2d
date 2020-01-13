
#include "pxscamerashakeeffect.h"
#include "pxsgravitylist.h"
#include "gamezone.h"
#include "gamemap.h"
#include "background.h"
#include "submarine.h"
#include "swirl.h"

//-------------------------------------------------------------------------------------------------
GameZone::GameZone()
 : mRacer(NULL)
 , mMap(NULL)
{
}

//-------------------------------------------------------------------------------------------------
GameZone::~GameZone()
{
}

//-------------------------------------------------------------------------------------------------
void GameZone::reset()
{
    mRacer->setPos(mMap->positionsOf(GameMap::Start).first());
}

//-------------------------------------------------------------------------------------------------
void GameZone::init()
{
    setGravity(new PxsGravityList(PxsForce(0,-0.01)));

    GameMap *map = new GameMap(":/maps/simple3.png");

    setFieldSize(QSize(map->width()*map->scale(),map->height()*map->scale()));
    appendBackground(new Background(map));

    mRacer   = registerBody(new Submarine(map->positionsOf(GameMap::Start).first(),*this), true);

    foreach(QPointF p, map->positionsOf(GameMap::Swirl))
        registerBody(new Swirl(p,*this));

    mMap = map;
}

//-------------------------------------------------------------------------------------------------
void GameZone::createExplosion(const QPointF &pos, float force)
{
    emit requestCameraEffect(new PxsCameraShakeEffect(force,force,force,0,force*200));
}

