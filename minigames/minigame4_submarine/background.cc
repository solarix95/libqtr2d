#include "background.h"
#include "pxszone.h"
#include <QLinearGradient>
//-------------------------------------------------------------------------------------------------
Background::Background(GameMap *map)
 : mMap(map)
{
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

    for (int i=0; i<mMap->rects().count(); i++) {
        if (!window.intersects(mMap->rects()[i]))
            continue;
        p.setBrush(mMap->colors()[i]);
        p.drawRect(mMap->rects()[i]);
    }
}
