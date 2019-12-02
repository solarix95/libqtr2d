#ifndef SPACE_ZONE_H
#define SPACE_ZONE_H

#include "pxszone.h"

class Spacezone : public PxsZone
{
    Q_OBJECT
public:
    Spacezone();
    virtual ~Spacezone();

    virtual void init() override;
    virtual void createExplosion(const QPointF &pos, float force) override;
};

#endif
