#include <QDebug>
#include "pxsellipseparticle.h"

//-------------------------------------------------------------------------------------------------
PxsEllipseParticle::PxsEllipseParticle(const QPointF &p, const QVector2D &dir, PxsZone &zone, const QColor &c, int livetimeMs, float radius)
 : PxsParticle(p, dir, zone, c, livetimeMs*0.5 + (qrand()%livetimeMs))
 , mRadius(radius)
{
}

//-------------------------------------------------------------------------------------------------
void PxsEllipseParticle::renderModelCentered(QPainter &p) const
{
    p.setPen(QPen(color(),0));
    p.setBrush(color());
    p.drawEllipse(QPointF(0,0),mRadius,mRadius);
}
