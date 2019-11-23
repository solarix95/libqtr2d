#include <QDebug>
#include "simplebody.h"

#define LENGTH 10

//-------------------------------------------------------------------------------------------------
SimpleBody::SimpleBody(const QPointF &p, const QList<PxsBody *> &friends)
 : PxsBody(p,friends)
{
    mSpin = 0.1;
}

//-------------------------------------------------------------------------------------------------
QRectF SimpleBody::boundingRect() const
{
    return QRectF(mPos.x()-10,mPos.y()+10,20,20);
}

//-------------------------------------------------------------------------------------------------
void SimpleBody::renderModelCentered(QPainter &p) const
{
    p.setPen(Qt::white);
    p.drawLine(-LENGTH,0,LENGTH,0);
    p.drawLine(0,LENGTH,0,-LENGTH);
}
