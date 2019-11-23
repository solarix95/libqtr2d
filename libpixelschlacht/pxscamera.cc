#include <QDebug>
#include "pxscamera.h"
#include "pxszone.h"
#include "pxscameraeffect.h"

//-------------------------------------------------------------------------------------------------
PxsCamera::PxsCamera(PxsZone *zone, QObject *parent)
    : QObject(parent)
    , mZone(NULL)
    , mCenter(0,0)
    , mAspectMode(IgnoreAspectRatio)
    , mAntialiasingEnabled(false)
{
    setZone(zone);
}

//-------------------------------------------------------------------------------------------------
void PxsCamera::setProjectionRect(const QRect &projection)
{
    mProjectionRect = projection;
    setupWorldMatrix();
}

//-------------------------------------------------------------------------------------------------
void PxsCamera::setZone(PxsZone *zone)
{
    Q_ASSERT(!mZone);
    if (!zone)
        return;

    mZone = zone;
    setWindow(mZone->fieldSize());
    connect(mZone, SIGNAL(updateRequest()), this, SIGNAL(updateRequest()));
    connect(mZone, SIGNAL(fieldSizeChanged()), this, SLOT(onFieldSizeChange()));
}

//-------------------------------------------------------------------------------------------------
void PxsCamera::lookTo(const QPointF &center)
{
    mCenter = center;
    setupWorldMatrix();
}

//-------------------------------------------------------------------------------------------------
void PxsCamera::setWindow(const QSize &zoneRect)
{
    mWindowRect = zoneRect;
    setupWorldMatrix();
    emit updateRequest();
}

//-------------------------------------------------------------------------------------------------
void PxsCamera::appendEffect(PxsCameraEffect *e)
{
    connect(e, SIGNAL(destroyed(QObject*)), this, SLOT(effectDestroyed(QObject*)));
    connect(e, SIGNAL(updateRequest()), this, SLOT(setupWorldMatrix()));
    mEffects << e;
}

//-------------------------------------------------------------------------------------------------
void PxsCamera::render(QPainter &p)
{
    if (!mZone)
        return;

    p.save();

    if (mAntialiasingEnabled)
        p.setRenderHint(QPainter::Antialiasing,true);
    p.setMatrix(mMatrix);

    const PxsBodies &bodies = mZone->bodies();
    foreach(PxsBody *bdy, bodies)
        bdy->render(p);

    p.restore();
}

//-------------------------------------------------------------------------------------------------
QPointF PxsCamera::center() const
{
    return mCenter;
}

//-------------------------------------------------------------------------------------------------
void PxsCamera::keyPressEvent(QKeyEvent *event)
{
    if (mZone)
        mZone->keyPressEvent(event);
}

//-------------------------------------------------------------------------------------------------
void PxsCamera::keyReleaseEvent(QKeyEvent *event)
{
    if (mZone)
        mZone->keyReleaseEvent(event);
}

//-------------------------------------------------------------------------------------------------
void PxsCamera::setAspectMode(int mode)
{
    Q_ASSERT(mode >= IgnoreAspectRatio);
    Q_ASSERT(mode <= AutoHeigh);

    mAspectMode = (AspectRatioMode)mode;
    setupWorldMatrix();
}

//-------------------------------------------------------------------------------------------------
void PxsCamera::setAntialiasingEnabled(bool enabled)
{
    mAntialiasingEnabled = enabled;
    emit updateRequest();
}

//-------------------------------------------------------------------------------------------------
void PxsCamera::onFieldSizeChange()
{
    setWindow(mZone->fieldSize());
}

//-------------------------------------------------------------------------------------------------
void PxsCamera::effectDestroyed(QObject *effect)
{
    mEffects.removeAll((PxsCameraEffect*)effect);
}

//-------------------------------------------------------------------------------------------------
void PxsCamera::setupWorldMatrix()
{
    switch(mAspectMode) {
    case IgnoreAspectRatio: {
        setupFullscreenMatrix(mProjectionRect,mWindowRect);
    } break;
    case FitToScreen: {

    } break;
    case AutoHeigh: {
        QSize windowRect = mWindowRect;
        windowRect.setHeight(mWindowRect.width()*(mProjectionRect.height()/(qreal)mProjectionRect.width()));
        setupFullscreenMatrix(mProjectionRect,windowRect);
    } break;
    case AutoWidth: {
        QSize windowRect = mWindowRect;
        windowRect.setWidth(mWindowRect.height()*(mProjectionRect.width()/(qreal)mProjectionRect.height()));
        setupFullscreenMatrix(mProjectionRect,windowRect);
    } break;
    default: Q_ASSERT(0 && "not implemented");
    }

    foreach(PxsCameraEffect *effect, mEffects)
        effect->process(mMatrix);

    emit updateRequest();
}

//-------------------------------------------------------------------------------------------------
void PxsCamera::setupFullscreenMatrix(const QRect &projectionRect, const QSize &windowRect)
{
    // Screen Coordinates
    mMatrix.reset();
    mMatrix.translate(projectionRect.x(), projectionRect.y());
    mMatrix.translate(0,projectionRect.height());
    qreal dx = projectionRect.width()/(qreal)windowRect.width();
    qreal dy = projectionRect.height()/(qreal)windowRect.height();
    mMatrix.scale(dx,-dy);

    // from now, we have to use logicacoordinatesl ..!
    QPointF moveVector = QPointF(windowRect.width()/2.0,windowRect.height()/2)-center();
    mMatrix.translate(moveVector.x(), moveVector.y());
    // p.setClipRect(0,0,windowRect.width(),windowRect.height());
}
