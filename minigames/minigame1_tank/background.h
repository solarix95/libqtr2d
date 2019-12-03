#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "pxsbackground.h"
#include <QList>

class Background : public PxsBackground
{
public:
    Background();

protected:
    virtual void renderBkgnd(QPainter &p);

};

#endif
