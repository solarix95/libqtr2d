
#include "qtr2dcamerashakeeffect.h"
#include "gamezone.h"
#include "background.h"
#include "ufo.h"
#include "tank.h"

//-------------------------------------------------------------------------------------------------
GameZone::GameZone()
{
}

//-------------------------------------------------------------------------------------------------
GameZone::~GameZone()
{
}

//-------------------------------------------------------------------------------------------------
void GameZone::init()
{
    setFieldSize(QSize(800,600));
    appendBackground(new Background());

    //registerBody(new Asteroid(QPointF(50,150),QVector2D(0.3,0),*this));
    //registerBody(new Asteroid(QPointF(350,150),QVector2D(-0.3,0),*this));
}

//-------------------------------------------------------------------------------------------------
void GameZone::createExplosion(const QPointF &pos, float force)
{
    emit requestCameraEffect(new Qtr2dCameraShakeEffect(0.5,0.5,0.5,0,1000));
}
