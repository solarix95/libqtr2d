
#include <QApplication>
#include "qtr2dwidget.h"
#include "qtr2dcamera.h"
#include "simplezone.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    SimpleZone zone;
    Qtr2dCamera  cam(&zone);
    Qtr2dWidget  w(&cam);

    zone.init();

    cam.lookTo(QPointF(50,50)); // Center of "SimpleObject"
    w.show();

    return app.exec();
}
