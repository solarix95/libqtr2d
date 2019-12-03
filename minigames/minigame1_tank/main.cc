
#include <QApplication>
#include "pxswidget.h"
#include "pxscamera.h"
#include "gamezone.h"

//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    PxsWidget w;
    PxsCamera c;
    GameZone  z;
    c.setZone(&z);
    c.setWindow(QSize(800,600));
    c.lookTo(QPointF(400,300));
    c.setAntialiasingEnabled(true);

    w.setCamera(&c);
    w.show();

    z.init();
    return app.exec();
}
