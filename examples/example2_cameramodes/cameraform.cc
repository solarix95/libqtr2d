#include "cameraform.h"
#include "ui_cameraform.h"
#include "qtr2dcamerashakeeffect.h"

//-------------------------------------------------------------------------------------------------
CameraForm::CameraForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CameraForm)
{
    ui->setupUi(this);
    mCamera.setZone(&mZone);
    mCamera.lookTo(QPointF(50,50));
    ui->pxswidget->setCamera(&mCamera);

    connect(ui->cbxAspectMode, SIGNAL(activated(int)),&mCamera, SLOT(setAspectMode(int)));
    connect(ui->btnShake, SIGNAL(clicked(bool)), this, SLOT(shakeIt()));
    connect(ui->chkAntialias, SIGNAL(clicked(bool)), &mCamera, SLOT(setAntialiasingEnabled(bool)));
    mZone.init();
}

//-------------------------------------------------------------------------------------------------
CameraForm::~CameraForm()
{
    delete ui;
}

//-------------------------------------------------------------------------------------------------
void CameraForm::shakeIt()
{
    mCamera.appendEffect(new Qtr2dCameraShakeEffect(3,3,0,1,2000));
}
