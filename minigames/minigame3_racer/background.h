#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "pxsbackground.h"
#include <QList>

class Background : public PxsBackground
{
public:
    Background(int w, int h, int count);

protected:
    virtual void renderBkgnd(QPainter &p, const QRectF &window);

private:
    enum Type {
        Clover,
        BlueFlower,
        PinkFlower
    };

    struct Star {
        Type    type;
        QPointF pos;
    };

    QList<Star>  mStars;

};

#endif
