#include "background.h"
#include "pxszone.h"

//-------------------------------------------------------------------------------------------------
Background::Background(int w, int h, int count)
{
    for (int i=0; i<count; i++) {
        Star s;
        s.pos  = QPointF(qrand()%w, qrand()%h);
        if (qrand()%10)
            s.type = Clover;
        else if (qrand()%2)
            s.type = BlueFlower;
        else
            s.type = PinkFlower;

        mStars << s;
    }
}
//-------------------------------------------------------------------------------------------------
void Background::renderBkgnd(QPainter &p)
{
    p.setBrush(QColor(0,100,0));
    p.drawRect(zone().fieldRect());

    foreach(const Star &s, mStars) {
        switch(s.type) {
        case Clover: {
            p.setPen(QPen(QColor(0,110,0),0.3));
            p.setBrush(QColor(0,120,0));
            p.drawEllipse(s.pos,3,3);
        } break;
        case BlueFlower: {
            p.setPen(QPen(Qt::blue,0.3));
            p.setBrush(Qt::blue);
            p.drawEllipse(s.pos,1,1);
        } break;
        case PinkFlower: {
            p.setPen(QPen(Qt::red,0.3));
            p.setBrush(Qt::red);
            p.drawEllipse(s.pos,1,0.5);
        } break;
        }
    }
}
