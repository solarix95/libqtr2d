#include "endlessspace.h"

//-------------------------------------------------------------------------------------------------
Endlessspace::Endlessspace(int w, int h, int count)
{
    for (int i=0; i<count; i++) {
        Star s;
        s.pos  = QPoint(qrand()%w, qrand()%h);
        if (qrand()%10)
            s.type = MiniStar;
        else if (qrand()%2)
            s.type = BigStar;
        else
            s.type = CrossStar;

        mStars << s;
    }
}

//-------------------------------------------------------------------------------------------------
void Endlessspace::renderBkgnd(QPainter &p, const QRectF &window)
{
    p.setBrush(Qt::black);
    p.setPen(Qt::black);
    p.drawRect(window);

    p.setBrush(Qt::white);
    foreach(const Star &s, mStars) {
        switch(s.type) {
        case MiniStar: {
            p.setPen(QPen(Qt::white,0.3));
            p.drawPoint(s.pos);
        } break;
        case BigStar: {
            p.setPen(QPen(Qt::yellow,0.3));
            p.drawEllipse(QRectF(s.pos.x(),s.pos.y(),0.5,0.5));
        } break;
        case CrossStar: {
            p.setPen(QPen(Qt::blue,0.3));
            p.drawLine(s.pos.x(), s.pos.y()-1,s.pos.x(), s.pos.y()+1);
            p.drawLine(s.pos.x()-1, s.pos.y(),s.pos.x()+1, s.pos.y());
        } break;
        }
    }
}
