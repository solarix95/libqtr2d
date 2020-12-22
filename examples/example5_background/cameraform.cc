#include "cameraform.h"
#include "endlessspace.h"
#include "ui_cameraform.h"
#include "qtr2dcamerashakeeffect.h"
#include "qtr2ddebugbackground.h"

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
    mCamera.setAspectMode(Qtr2dCamera::AutoWidth);
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
    mCamera.appendEffect(new Qtr2dCameraShakeEffect(2,2,0,0,2000));
}
