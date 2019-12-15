#ifndef RACER_H
#define RACER_H

#include "pxspolygonbody.h"
#include <QTimer>

class Racer : public PxsPolygonBody
{
    Q_OBJECT
public:
    Racer(const QPointF &p, PxsZone &zone);

    virtual bool move(double speed) override;
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;

protected:
    virtual void renderModelCentered(QPainter &p) const override;
    virtual void accelerate(double speed) override;

private slots:
    void smoke();

private:
    void renderWheel(QPainter &p, const QPointF &pos) const;
    void renderRoofSignal(QPainter &p) const;


    int    mFireState; // 0 off, 1 low, 2 high
    float  mWheelPos;
    float  mSteering;
    float  mRoofSignalAngle;
    QTimer mSmokeTimer;
};


#endif // SPACESHIP_H
