#include "qtr2dgravitylist.h"

//-------------------------------------------------------------------------------------------------
Qtr2dGravityList::Qtr2dGravityList(const PxsForces &forces)
 : mForces(forces)
{
}

//-------------------------------------------------------------------------------------------------
Qtr2dGravityList::Qtr2dGravityList(const PxsForce &force)
 : mForces(PxsForces() << force)
{
}

void Qtr2dGravityList::process(PxsBodies &bodies, PxsParticles &)
{
    if (mForces.isEmpty())
        return;
    for (int i=0; i<bodies.count(); i++) {
        foreach (const PxsForce &f, mForces) {
            bodies.at(i)->addGravity(f);
        }
    }
}
