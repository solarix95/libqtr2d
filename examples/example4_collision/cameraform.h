#ifndef CAMERAFORM_H
#define CAMERAFORM_H

#include <QWidget>
#include "spacezone.h"
#include "qtr2dcamera.h"

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

    Qtr2dCamera  mCamera;
    Spacezone  mZone;
};

#endif // CAMERAFORM_H
