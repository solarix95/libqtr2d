#include "background.h"
#include "pxszone.h"

//-------------------------------------------------------------------------------------------------
Background::Background()
{
}

//-------------------------------------------------------------------------------------------------
void Background::renderBkgnd(QPainter &p)
{
    p.setBrush(Qt::cyan);
    p.drawRect(zone().fieldRect());
}
