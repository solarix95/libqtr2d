
#include <QApplication>
#include "pxswidget.h"
#include "pxscamera.h"
#include "simplezone.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    SimpleZone zone;
    PxsCamera  cam(&zone);
    PxsWidget  w(&cam);

    zone.init();

    cam.lookTo(QPointF(50,50)); // Center of "SimpleObject"
    w.show();

    return app.exec();
}
