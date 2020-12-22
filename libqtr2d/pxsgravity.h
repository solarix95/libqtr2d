#ifndef PXSGRAVITY_H
#define PXSGRAVITY_H

#include "pxsbody.h"
#include "pxsparticle.h"

class PxsGravity
{
public:
    virtual ~PxsGravity();
    virtual void process(PxsBodies &bodies, PxsParticles &particles) = 0;
};

#endif // PXSGRAVITY_H
