#ifndef SWIRL_H
#define SWIRL_H

#include "pxsbody.h"

class Swirl : public PxsBody
{
    Q_OBJECT
public:
    Swirl(const QPointF &p, PxsZone &zone);

    virtual bool move(double speed) override;
    virtual QRectF boundingRect() const override;

protected:
    virtual void onCollision(PxsBody *pdy) override;
    virtual void renderModelCentered(QPainter &p) const override;

private slots:
    void effectDestroyed(QObject *effect);

private:
    QObject *mCurrent;
};

#endif // SWIRL_H
