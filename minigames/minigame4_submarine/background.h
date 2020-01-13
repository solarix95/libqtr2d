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

    virtual bool testCollision(PxsObject *bdy) const override;

protected:
    virtual void renderBkgnd(QPainter &p, const QRectF &window) override;

private:
    bool  testPos(const QPointF &pos) const;

    GameMap  *mMap;
};

#endif
