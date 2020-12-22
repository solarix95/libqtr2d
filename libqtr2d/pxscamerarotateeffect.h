#ifndef PXSCAMERAROTATEEFFECT_H
#define PXSCAMERAROTATEEFFECT_H

#include "pxscameraeffect.h"

class PxsCameraRotateEffect : public PxsCameraEffect
{
public:
    PxsCameraRotateEffect(int durationMs);

    virtual void process(QMatrix &matrix, const QRectF &window) override;

private:
    QTime mTime;
    int   mDurationMs;
};

#endif // PXSCAMERAROTATEEFFECT_H
