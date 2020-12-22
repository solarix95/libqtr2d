#ifndef PXSGRAVITYLIST_H
#define PXSGRAVITYLIST_H

#include "qtr2dbasetypes.h"
#include "qtr2dgravity.h"

class Qtr2dGravityList : public Qtr2dGravity
{
public:
    Qtr2dGravityList(const PxsForces &forces);
    Qtr2dGravityList(const PxsForce &force);
    virtual void process(PxsBodies &bodies, PxsParticles &particles) override;

    inline PxsForces &forces() { return mForces; }

private:

    PxsForces mForces;

};

#endif // PXSGRAVITYLIST_H
