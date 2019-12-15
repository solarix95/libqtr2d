#include "gamewidget.h"

//-------------------------------------------------------------------------------------------------
GameWidget::GameWidget(QWidget *parent) : PxsWidget(parent)
{
    mCam1.setZone(&mZone);
    mCam2.setZone(&mZone);

    mCam1.lookTo(QPointF(800,600));

    mCam1.setAspectMode(PxsCamera::AutoHeigh);
    mCam2.setAspectMode(PxsCamera::AutoWidth);

    mCam1.setAntialiasingEnabled(true);
    mCam2.setAntialiasingEnabled(true);

    setCamera(&mCam1);

    mZone.init();

    mCam1.setWindow(QSize(800,600));
    mCam2.setWindow(QSize(200,200));

    // mCam2.followObject(mZone.racer(), PxsFollowCamera::Options(PxsFollowCamera::FollowPosition | PxsFollowCamera::FollowAngle));
    mCam2.followObject(mZone.racer());
}

//-------------------------------------------------------------------------------------------------
void GameWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_F1)
        setCamera(&mCam1);
    if (event->key() == Qt::Key_F2)
        setCamera(&mCam2);

    PxsWidget::keyPressEvent(event);
}
