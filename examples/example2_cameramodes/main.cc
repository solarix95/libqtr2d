
#include <QApplication>
#include "qtr2dwidget.h"
#include "qtr2dcamera.h"
#include "simplezone.h"
#include "cameraform.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    CameraForm form;
    form.show();

    return app.exec();
}
