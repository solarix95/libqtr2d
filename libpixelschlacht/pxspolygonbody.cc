#include "pxspolygonbody.h"

//-------------------------------------------------------------------------------------------------
PxsPolygonBody::PxsPolygonBody(const QPointF &p, PxsZone &zone)
 : PxsBody(p, zone)
{
}

//-------------------------------------------------------------------------------------------------
void PxsPolygonBody::setPolygons(const PxsPolygonBody::Polygons &polygons)
{
    mPolygons     = polygons;
    mBoundingTopLeft = mBoundingBottomRight = QPointF();
    if (mPolygons.isEmpty())
        return;

    // Update Bounding Rect..
    QPointF topLeft, bottomRight;
    topLeft = bottomRight = mPolygons.first().points.first();
    foreach (const Polygon &polygon, mPolygons) {
        foreach(const QPointF &point, polygon.points) {
            if (point.x() < topLeft.x())
                topLeft.setX(point.x());
            if (point.y() > topLeft.y())
                topLeft.setY(point.y());
            if (point.x() > bottomRight.x())
                bottomRight.setX(point.x());
            if (point.y() < bottomRight.y())
                bottomRight.setY(point.y());
        }
    }

    mBoundingTopLeft     = topLeft;
    mBoundingBottomRight = bottomRight;
}

//-------------------------------------------------------------------------------------------------
QRectF PxsPolygonBody::boundingRect() const
{
    return QRectF(pos() + mBoundingTopLeft, pos() + mBoundingBottomRight);
}

//-------------------------------------------------------------------------------------------------
void PxsPolygonBody::renderModelCentered(QPainter &p) const
{
    foreach (const Polygon &polygon, mPolygons) {
        p.setPen(polygon.pen);
        p.setBrush(polygon.brush);
        p.drawPolygon(polygon.points.constData(),polygon.points.count());
    }
}
