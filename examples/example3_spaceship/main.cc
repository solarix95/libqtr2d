
#include <QApplication>
#include "cameraform.h"

//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    CameraForm form;
    form.show();

    return app.exec();
}
