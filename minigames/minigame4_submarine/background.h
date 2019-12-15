#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "pxsbackground.h"
#include "gamemap.h"
#include <QList>

class Background : public PxsBackground
{
public:
    Background(GameMap *map);

    inline void setMap(GameMap *map) { mMap = map; }

protected:
    virtual void renderBkgnd(QPainter &p, const QRectF &window);

private:
    GameMap  *mMap;
};

#endif
