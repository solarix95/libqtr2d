#ifndef SIMPLEBODY_H
#define SIMPLEBODY_H

#include "pxspolygonbody.h"

class Spaceship : public PxsPolygonBody
{
public:
    Spaceship(const QPointF &p, PxsZone &zone);

    virtual bool move(double speed) override;
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;

protected:
    virtual void renderModelCentered(QPainter &p) const override;

private:
    int mFireState; // 0 off, 1 low, 2 high
};


#endif // SIMPLEBODY_H
