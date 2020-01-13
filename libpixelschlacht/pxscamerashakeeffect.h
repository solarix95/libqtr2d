#ifndef PXSCAMERASHAKEEFFECT_H
#define PXSCAMERASHAKEEFFECT_H

#include "pxscameraeffect.h"

class PxsCameraShakeEffect : public PxsCameraEffect
{
public:
    PxsCameraShakeEffect(float ax, float ay, float az, float rot, int durationMs);

    virtual void process(QMatrix &matrix, const QRectF &window) override;

private:
    float progress() const; // 1.0 -> 0.0

    float mAx;
    float mAy;
    float mAz;
    float mRotation;
    int   mDuration;

    QTime mTimer;
};

#endif // PXSCAMERASHAKEEFFECT_H
