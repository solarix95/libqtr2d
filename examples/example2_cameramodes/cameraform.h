#ifndef CAMERAFORM_H
#define CAMERAFORM_H

#include <QWidget>
#include "simplezone.h"
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
    SimpleZone mZone;
};

#endif // CAMERAFORM_H
