#include "gamewidget.h"

//-------------------------------------------------------------------------------------------------
GameWidget::GameWidget(QWidget *parent) : PxsWidget(parent)
{
    mCam1.setZone(&mZone);
    mCam2.setZone(&mZone);
    mCam3.setZone(&mZone);


    mCam1.lookTo(QPointF(800,600));

    mCam1.setAspectMode(PxsCamera::AutoHeigh);
    mCam2.setAspectMode(PxsCamera::AutoWidth);
    mCam3.setAspectMode(PxsCamera::AutoWidth);

    mCam1.setAntialiasingEnabled(true);
    mCam2.setAntialiasingEnabled(true);
    mCam3.setAntialiasingEnabled(true);

    setCamera(&mCam1);

    mZone.init();

    mCam1.setWindow(QSize(800,600));
    mCam2.setWindow(QSize(200,200));
    mCam3.setWindow(QSize(300,300));

    mCam2.followObject(mZone.ship());
    mCam3.followObject(mZone.planet());
}

//-------------------------------------------------------------------------------------------------
void GameWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_F1)
        setCamera(&mCam1);
    if (event->key() == Qt::Key_F2)
        setCamera(&mCam2);
    if (event->key() == Qt::Key_F3)
        setCamera(&mCam3);

    PxsWidget::keyPressEvent(event);
}
