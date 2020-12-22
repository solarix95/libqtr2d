#ifndef SWIRL_H
#define SWIRL_H

#include "qtr2dbody.h"

class Swirl : public Qtr2dBody
{
    Q_OBJECT
public:
    Swirl(const QPointF &p, Qtr2dZone &zone);

    virtual bool move(double speed) override;
    virtual QRectF boundingRect() const override;

protected:
    virtual void onCollision(Qtr2dBody *pdy) override;
    virtual void renderModelCentered(QPainter &p) const override;

private slots:
    void effectDestroyed(QObject *effect);

private:
    QObject *mCurrent;
};

#endif // SWIRL_H
