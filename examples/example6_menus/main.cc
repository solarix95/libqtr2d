
#include <QApplication>
#include <qtr2dwidget.h>
#include <qtr2doptionmenu.h>
#include <qtr2dsimplemenustyle.h>

//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Qtr2dWidget w;

    Qtr2dSimpleMenuStyle menuStyle(10,QPen(Qt::red,2),QBrush(Qt::white));
    Qtr2dOptionMenu *menu = new Qtr2dOptionMenu(menuStyle, { Qtr2dMenuOption("hello",w.font()), Qtr2dMenuOption("world",w.font())});

    w.setMenu(menu);

    w.show();
    return app.exec();
}
