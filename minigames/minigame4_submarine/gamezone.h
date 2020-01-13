#ifndef GAME_ZONE_H
#define GAME_ZONE_H

#include "pxszone.h"

class GameMap;
class GameZone : public PxsZone
{
    Q_OBJECT
public:
    GameZone();
    virtual ~GameZone();

    void reset();
    virtual void init() override;
    virtual void createExplosion(const QPointF &pos, float force) override;
    inline PxsBody *racer()   { return mRacer;   }

private:
    PxsBody  *mRacer;
    GameMap  *mMap;
};

#endif
