#ifndef PXSPOLYGONBODY_H
#define PXSPOLYGONBODY_H

#include <QVector>
#include <QPointF>
#include <QBrush>
#include <QPen>
#include "pxsbody.h"


class PxsPolygonBody : public PxsBody
{
public:
    typedef QVector<QPointF> Points;
    struct Polygon {
        QPen             pen;
        QBrush           brush;
        Points           points;
        Polygon(QPen p, QBrush b, const Points &pts)
            : pen(p), brush(b), points(pts) {}
    };
    typedef QList<Polygon> Polygons;

    PxsPolygonBody(const QPointF &p, PxsZone &zone);

    void setPolygons(const Polygons &polygons);
    virtual QRectF   boundingRect() const override;

protected:
    virtual void renderModelCentered(QPainter &p) const override;

private:
    Polygons    mPolygons;
    QPointF     mBoundingTopLeft;
    QPointF     mBoundingBottomRight;
};

#endif // PXSPOLYGONBODY_H
