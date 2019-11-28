#ifndef PXSPARTICLE_H
#define PXSPARTICLE_H

#include <QTime>
#include "pxsobject.h"

class PxsParticle : public PxsObject
{
public:
    PxsParticle(const QPointF &p, const QVector2D &dir, PxsZone &zone, const QColor &color, int livetimeMs);

    virtual bool move(double speed) override;
    virtual QRectF boundingRect() const override;

protected:
    QColor color() const;
    float  transparency() const;

private:
    QColor mColor;
    int    mLivetimeMs;
    QTime  mTime;
};

typedef QList<PxsParticle*> PxsParticles;

#endif // PXSPARTICLE_H
