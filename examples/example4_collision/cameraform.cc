#include "cameraform.h"
#include "ui_cameraform.h"
#include "pxsdebugbackground.h"
#include "pxscamerashakeeffect.h"

//-------------------------------------------------------------------------------------------------
CameraForm::CameraForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CameraForm)
{
    ui->setupUi(this);
    mCamera.setZone(&mZone);
    mCamera.lookTo(QPointF(100,50));
    ui->pxswidget->setCamera(&mCamera);

    connect(ui->btnShake, SIGNAL(clicked(bool)), this, SLOT(shakeIt()));
    connect(ui->chkAntialias, SIGNAL(clicked(bool)), &mCamera, SLOT(setAntialiasingEnabled(bool)));

    mCamera.setAspectMode(PxsCamera::AutoWidth);
    mZone.appendBackground(new PxsDebugBackground(Qt::white,10,0.3));
    mZone.init();

    ui->pxswidget->setFocusPolicy(Qt::ClickFocus);
    ui->pxswidget->setFocus();
}

//-------------------------------------------------------------------------------------------------
CameraForm::~CameraForm()
{
    delete ui;
}

//-------------------------------------------------------------------------------------------------
void CameraForm::shakeIt()
{
    mCamera.appendEffect(new PxsCameraShakeEffect(2,2,0,1,2000));
}
