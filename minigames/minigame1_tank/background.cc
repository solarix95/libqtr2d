#include "background.h"
#include "qtr2dzone.h"

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
