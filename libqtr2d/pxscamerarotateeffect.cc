#include <QDebug>
#include "pxscamerarotateeffect.h"

PxsCameraRotateEffect::PxsCameraRotateEffect(int durationMs)
{
    mDurationMs = durationMs;
    mTime.start();
}

void PxsCameraRotateEffect::process(QMatrix &matrix, const QRectF &window)
{
    float progress = mTime.elapsed()/(float)mDurationMs;
    matrix.translate(window.center().x(), window.center().y());
    matrix.rotate(progress*360);
    matrix.translate(-window.center().x(), -window.center().y());
    if (mTime.elapsed() > mDurationMs)
        deleteLater();
}
