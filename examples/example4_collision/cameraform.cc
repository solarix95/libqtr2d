#include "cameraform.h"
#include "ui_cameraform.h"
#include "qtr2ddebugbackground.h"
#include "qtr2dcamerashakeeffect.h"

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

    mCamera.setAspectMode(Qtr2dCamera::AutoWidth);
    mZone.appendBackground(new Qtr2dDebugBackground(Qt::white,10,0.3));
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
    mCamera.appendEffect(new Qtr2dCameraShakeEffect(2,2,0,1,2000));
}
