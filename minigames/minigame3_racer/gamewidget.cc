#include "gamewidget.h"

//-------------------------------------------------------------------------------------------------
GameWidget::GameWidget(QWidget *parent) : Qtr2dWidget(parent)
{
    mCam1.setZone(&mZone);
    mCam2.setZone(&mZone);

    mCam1.lookTo(QPointF(2500,2500));

    mCam1.setAspectMode(Qtr2dCamera::AutoHeigh);
    mCam2.setAspectMode(Qtr2dCamera::AutoWidth);

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

    Qtr2dWidget::keyPressEvent(event);
}
