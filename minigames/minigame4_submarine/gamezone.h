#ifndef GAME_ZONE_H
#define GAME_ZONE_H

#include "qtr2dzone.h"

class GameMap;
class GameZone : public Qtr2dZone
{
    Q_OBJECT
public:
    GameZone();
    virtual ~GameZone();

    void reset();
    virtual void init() override;
    virtual void createExplosion(const QPointF &pos, float force) override;
    inline Qtr2dBody *racer()   { return mRacer;   }

private:
    Qtr2dBody  *mRacer;
    GameMap    *mMap;
};

#endif
