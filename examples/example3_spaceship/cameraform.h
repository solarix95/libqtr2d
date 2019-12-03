#ifndef CAMERAFORM_H
#define CAMERAFORM_H

#include <QWidget>
#include "spacezone.h"
#include "pxscamera.h"

namespace Ui {
class CameraForm;
}

class CameraForm : public QWidget
{
    Q_OBJECT

public:
    explicit CameraForm(QWidget *parent = 0);
    ~CameraForm();

private slots:
    void shakeIt();

private:
    Ui::CameraForm *ui;

    PxsCamera  mCamera;
    Spacezone  mZone;
};

#endif // CAMERAFORM_H
