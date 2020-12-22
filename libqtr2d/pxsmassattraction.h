#ifndef PXSMASSATTRACTION_H
#define PXSMASSATTRACTION_H

#include "pxsgravity.h"

class PxsMassAttraction : public PxsGravity
{
public:
    virtual void process(PxsBodies &bodies, PxsParticles &particles);

};

#endif // PXSMASSATTRACTION_H
