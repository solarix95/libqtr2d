#include "background.h"
#include "qtr2dzone.h"
#include "qtr2dbody.h"
#include <QLinearGradient>
#include <QDebug>

//-------------------------------------------------------------------------------------------------
Background::Background(GameMap *map)
 : mMap(map)
{
}

//-------------------------------------------------------------------------------------------------
bool Background::testCollision(Qtr2dObject *bdy) const
{
    QRectF colRect = bdy->collisionRect();

    if (testPos(colRect.topLeft())   ||
        testPos(colRect.topRight())  ||
        testPos(colRect.bottomLeft())||
        testPos(colRect.bottomRight()))
    {
        return true;
    }

    return false;
}

//-------------------------------------------------------------------------------------------------
void Background::renderBkgnd(QPainter &p, const QRectF &window)
{
    QLinearGradient gr(QPointF(0,0),QPointF(0,5000));
    gr.setColorAt(0,Qt::darkBlue);
    gr.setColorAt(0.1,Qt::darkBlue);
    gr.setColorAt(0.9,Qt::cyan);
    gr.setColorAt(1,Qt::cyan);

    p.setBrush(QBrush(gr));
    p.drawRect(zone().fieldRect());

    if (!mMap)
        return;

    QPoint fromP = mMap->map(window.topLeft());
    QPoint toP   = mMap->map(window.bottomRight());

    int rendered = 0;
    for (int y = fromP.y()-1; y <= toP.y(); y++) {
        for (int x = fromP.x()-1; x <= toP.x(); x++) {
            if (y < 0 || y >= mMap->height())
                continue;
            if (x < 0 || x >= mMap->width())
                continue;
            if (!mMap->color(x,y))
                continue;
            p.setBrush(*mMap->color(x,y));
            p.drawRect(x*mMap->scale(), y*mMap->scale(), mMap->scale(), mMap->scale());
            rendered++;
        }
    }
}

//-------------------------------------------------------------------------------------------------
bool Background::testPos(const QPointF &pos) const
{
    QPoint mapPos = mMap->map(pos);

    if (mapPos.x() < 0 || mapPos.x() >= mMap->width())
        return false;
    if (mapPos.y() < 0 || mapPos.y() >= mMap->height())
        return false;
    if (!mMap->color(mapPos.x(),mapPos.y()))
        return false;

    return true;
}
