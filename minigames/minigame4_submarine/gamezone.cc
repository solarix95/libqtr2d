
#include "qtr2dcamerashakeeffect.h"
#include "qtr2dgravitylist.h"
#include "gamezone.h"
#include "gamemap.h"
#include "background.h"
#include "submarine.h"
#include "swirl.h"
#include "fish.h"

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
    setGravity(new Qtr2dGravityList(PxsForce(0,-0.01)));

    GameMap *map = new GameMap(":/maps/simple3.png");

    setFieldSize(QSize(map->width()*map->scale(),map->height()*map->scale()));
    appendBackground(new Background(map));

    foreach(QPointF p, map->positionsOf(GameMap::Fishes))
        registerBody(new Fish(p,*this));

    foreach(QPointF p, map->positionsOf(GameMap::Swirl))
        registerBody(new Swirl(p,*this));

    mRacer   = registerBody(new Submarine(map->positionsOf(GameMap::Start).first(),*this), true);



    mMap = map;
}

//-------------------------------------------------------------------------------------------------
void GameZone::createExplosion(const QPointF &pos, float force)
{
    emit requestCameraEffect(new Qtr2dCameraShakeEffect(force,force,force,0,force*200));
}

