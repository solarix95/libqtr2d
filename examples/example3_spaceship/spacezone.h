#ifndef SPACE_ZONE_H
#define SPACE_ZONE_H

#include "pxszone.h"

class Spacezone : public PxsZone
{
    Q_OBJECT
public:
    Spacezone();
    virtual ~Spacezone();

    virtual void init();

protected:
    virtual void renderBackground(QPainter &p, const QRectF &window);

private slots:
    void createAsteroid();
};

#endif
