#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "qtr2dbackground.h"
#include <QList>

class Background : public Qtr2dBackground
{
public:
    Background();

protected:
    virtual void renderBkgnd(QPainter &p);

};

#endif
