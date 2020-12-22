#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "qtr2dbackground.h"
#include "gamemap.h"
#include <QList>

class Background : public Qtr2dBackground
{
public:
    Background(GameMap *map);

    inline void setMap(GameMap *map) { mMap = map; }

    virtual bool testCollision(Qtr2dObject *bdy) const override;

protected:
    virtual void renderBkgnd(QPainter &p, const QRectF &window) override;

private:
    bool  testPos(const QPointF &pos) const;

    GameMap  *mMap;
};

#endif
