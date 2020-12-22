#ifndef PXSGRAVITYLIST_H
#define PXSGRAVITYLIST_H

#include "pxsbasetypes.h"
#include "pxsgravity.h"

class PxsGravityList : public PxsGravity
{
public:
    PxsGravityList(const PxsForces &forces);
    PxsGravityList(const PxsForce &force);
    virtual void process(PxsBodies &bodies, PxsParticles &particles) override;

    inline PxsForces &forces() { return mForces; }

private:

    PxsForces mForces;

};

#endif // PXSGRAVITYLIST_H
