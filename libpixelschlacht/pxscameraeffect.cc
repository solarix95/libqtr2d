#include <QTimer>
#include "pxscameraeffect.h"

//-------------------------------------------------------------------------------------------------
PxsCameraEffect::PxsCameraEffect(int fps)
{
    QTimer *t = new QTimer(this);
    connect(t, SIGNAL(timeout()), this, SLOT(update()));
    t->start(1000/fps);
    mTime.start();
}

//-------------------------------------------------------------------------------------------------
void PxsCameraEffect::update()
{
    emit updateRequest();
}

//-------------------------------------------------------------------------------------------------
int PxsCameraEffect::elapsedMs() const
{
    return mTime.elapsed();
}
