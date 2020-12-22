#ifndef SPACE_ZONE_H
#define SPACE_ZONE_H

#include "qtr2dzone.h"

class Spacezone : public Qtr2dZone
{
    Q_OBJECT
public:
    Spacezone();
    virtual ~Spacezone();

    virtual void init() override;
    virtual void createExplosion(const QPointF &pos, float force) override;
};

#endif
