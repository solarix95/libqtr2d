#ifndef GAME_ZONE_H
#define GAME_ZONE_H

#include "qtr2dzone.h"

class GameZone : public Qtr2dZone
{
    Q_OBJECT
public:
    GameZone();
    virtual ~GameZone();

    virtual void init() override;
    virtual void createExplosion(const QPointF &pos, float force) override;

    inline Qtr2dBody *racer()   { return mRacer;   }

private:
    Qtr2dBody  *mRacer;
};

#endif
