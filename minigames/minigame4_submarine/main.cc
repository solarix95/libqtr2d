
#include <QApplication>
#include "gamewidget.h"

//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    GameWidget w;
    w.show();
    w.resize(1400,800);

    return app.exec();
}
