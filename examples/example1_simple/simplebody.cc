#include <QDebug>
#include "simplebody.h"

#define LENGTH 10

//-------------------------------------------------------------------------------------------------
SimpleBody::SimpleBody(const QPointF &p, Qtr2dZone &zone)
 : Qtr2dBody(p,zone)
{
    spin() = 0.1;
}

//-------------------------------------------------------------------------------------------------
QRectF SimpleBody::boundingRect() const
{
    return QRectF(pos().x()-LENGTH,pos().y()+LENGTH,2*LENGTH,2*LENGTH);
}

//-------------------------------------------------------------------------------------------------
void SimpleBody::renderModelCentered(QPainter &p) const
{
    p.setPen(Qt::white);
    p.drawRect(QRect(-LENGTH,-LENGTH,2*LENGTH,2*LENGTH));
    p.drawLine(-LENGTH,0,LENGTH,0);
    p.drawLine(0,LENGTH,0,-LENGTH);
}
