#include "cameraform.h"
#include "endlessspace.h"
#include "ui_cameraform.h"
#include "pxscamerashakeeffect.h"
#include "pxsdebugbackground.h"

//-------------------------------------------------------------------------------------------------
CameraForm::CameraForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CameraForm)
{
    ui->setupUi(this);
    mCamera.setZone(&mZone);
    mCamera.lookTo(QPointF(200,150));
    ui->pxswidget->setCamera(&mCamera);

    connect(ui->btnShake, SIGNAL(clicked(bool)), this, SLOT(shakeIt()));

    mCamera.setAntialiasingEnabled(true);
    mCamera.setAspectMode(PxsCamera::AutoWidth);
    mZone.appendBackground(new Endlessspace(400,300,70));
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
    mCamera.appendEffect(new PxsCameraShakeEffect(2,2,0,0,2000));
}
