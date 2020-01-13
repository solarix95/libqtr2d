#ifndef FISH_H
#define FISH_H

#include "pxsbody.h"
#include <QColor>

class Fish : public PxsBody
{
    Q_OBJECT
public:
    Fish(const QPointF &p, PxsZone &zone);

    virtual bool move(double speed) override;
    virtual QRectF boundingRect() const override;

protected:
    virtual void onCollision(PxsBody *pdy) override;
    virtual void renderModelCentered(QPainter &p) const override;

private:
    double mLiveTime;
    QColor mColor;
};

#endif // FISH_H
