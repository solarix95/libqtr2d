#ifndef FISH_H
#define FISH_H

#include "qtr2dbody.h"
#include <QColor>

class Fish : public Qtr2dBody
{
    Q_OBJECT
public:
    Fish(const QPointF &p, Qtr2dZone &zone);

    virtual bool move(double speed) override;
    virtual QRectF boundingRect() const override;

protected:
    virtual void onCollision(Qtr2dBody *pdy) override;
    virtual void renderModelCentered(QPainter &p) const override;

private:
    double mLiveTime;
    QColor mColor;
};

#endif // FISH_H
