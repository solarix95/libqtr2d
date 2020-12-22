#include "pxsgravitylist.h"

//-------------------------------------------------------------------------------------------------
PxsGravityList::PxsGravityList(const PxsForces &forces)
 : mForces(forces)
{
}

//-------------------------------------------------------------------------------------------------
PxsGravityList::PxsGravityList(const PxsForce &force)
 : mForces(PxsForces() << force)
{
}

void PxsGravityList::process(PxsBodies &bodies, PxsParticles &)
{
    if (mForces.isEmpty())
        return;
    for (int i=0; i<bodies.count(); i++) {
        foreach (const PxsForce &f, mForces) {
            bodies.at(i)->addGravity(f);
        }
    }
}
