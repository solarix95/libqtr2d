#ifndef ENDLESSSPACE_H
#define ENDLESSSPACE_H

#include "qtr2dbackground.h"
#include <QList>

class Endlessspace : public Qtr2dBackground
{
public:
    Endlessspace(int w, int h, int count);

protected:
    virtual void renderBkgnd(QPainter &p, const QRectF &window) override;

private:
    enum Type {
        MiniStar,
        BigStar,
        CrossStar
    };

    struct Star {
        Type   type;
        QPoint pos;
    };

    QList<Star>  mStars;
};

#endif // ENDLESSSPACE_H
