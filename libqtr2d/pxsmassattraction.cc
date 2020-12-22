#include "pxsmassattraction.h"

void PxsMassAttraction::process(PxsBodies &bodies, PxsParticles &)
{
    PxsForce g;
    for (int i=0; i<bodies.count(); i++) {
        PxsBody *o = bodies.at(i);
        for (int j=i+1; j<bodies.count(); j++) {
            g = bodies[j]->gravityTo(o);
            if (!g.isNull())
                o->addGravity(-g);

            g = o->gravityTo(bodies[j]);
            if (!g.isNull())
                bodies[j]->addGravity(-g);
        }
    }
}
