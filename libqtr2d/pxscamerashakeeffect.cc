#include <QTimer>
#include <QDebug>
#include "pxscamerashakeeffect.h"

inline float randomizeFloat(float v)
{
    return v*((-50 + qrand()%100)/50.0);
}

//-------------------------------------------------------------------------------------------------
PxsCameraShakeEffect::PxsCameraShakeEffect(float ax, float ay, float az, float rot, int durationMs)
    : PxsCameraEffect(30)
    , mAx(ax)
    , mAy(ay)
    , mAz(az)
    , mRotation(rot)
    , mDuration(durationMs)
{
    QTimer *t = new QTimer(this);
    connect(t, SIGNAL(timeout()), this, SLOT(deleteLater()));
    t->start(durationMs);
}

//-------------------------------------------------------------------------------------------------
void PxsCameraShakeEffect::process(QMatrix &matrix, const QRectF &window)
{
    Q_UNUSED(window);
    float prog = progress();
    matrix.translate(randomizeFloat(mAx*prog),
                     randomizeFloat(mAy*prog));

    matrix.rotate(randomizeFloat(mRotation*prog));
}

//-------------------------------------------------------------------------------------------------
float PxsCameraShakeEffect::progress() const
{
    return qMax((mDuration-elapsedMs())/(float)mDuration,0.0f);
}
