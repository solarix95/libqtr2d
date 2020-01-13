#ifndef RACER_H
#define RACER_H

#include "pxspolygonbody.h"
#include <QTimer>

class Submarine : public PxsPolygonBody
{
    Q_OBJECT
public:
    Submarine(const QPointF &p, PxsZone &zone);

    virtual bool move(double speed) override;
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;

protected:
    virtual void renderModelCentered(QPainter &p) const override;
    virtual void accelerate(double speed) override;
    virtual void onCollision(PxsBody *other) override;

private slots:
    void bubble();

private:

    float  mSinkAngle;
    QTimer mBubbleTimer;
};


#endif // SPACESHIP_H
