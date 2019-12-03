#ifndef GAME_ZONE_H
#define GAME_ZONE_H

#include "pxszone.h"

class GameZone : public PxsZone
{
    Q_OBJECT
public:
    GameZone();
    virtual ~GameZone();

    virtual void init() override;
    virtual void createExplosion(const QPointF &pos, float force) override;
};

#endif
