#include <QDebug>
#include "pxswidget.h"
#include "pxscamera.h"
#include "pxszone.h"

//-------------------------------------------------------------------------------------------------
PxsWidget::PxsWidget(QWidget *parent)
 : QWidget(parent)
 , mCamera(NULL)
{
}

//-------------------------------------------------------------------------------------------------
PxsWidget::PxsWidget(PxsCamera *camera, QWidget *parent)
    : QWidget(parent)
    , mCamera(NULL)
{
    setCamera(camera);
}

//-------------------------------------------------------------------------------------------------
void PxsWidget::paintEvent(QPaintEvent*)
{
    QPainter p(this);

    if (!mCamera) {
        p.fillRect(rect(), Qt::black);
        return;
    }

    mCamera->render(p);
}

//-------------------------------------------------------------------------------------------------
void PxsWidget::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
}

//-------------------------------------------------------------------------------------------------
void PxsWidget::keyPressEvent(QKeyEvent *event)
{
    if (mCamera)
        mCamera->keyPressEvent(event);
    QWidget::keyPressEvent(event);
}

//-------------------------------------------------------------------------------------------------
void PxsWidget::keyReleaseEvent(QKeyEvent *event)
{
    if (mCamera)
        mCamera->keyReleaseEvent(event);
    QWidget::keyReleaseEvent(event);
}

//-------------------------------------------------------------------------------------------------
void PxsWidget::setCamera(PxsCamera *camera)
{
    mCamera = camera;
    if (!mCamera)
        return;

    connect(mCamera, SIGNAL(updateRequest()), this, SLOT(update()), Qt::UniqueConnection);
    mCamera->setProjectionRect(rect());
}

//-------------------------------------------------------------------------------------------------
void PxsWidget::resizeEvent(QResizeEvent*)
{
    if (mCamera)
        mCamera->setProjectionRect(rect());
}
