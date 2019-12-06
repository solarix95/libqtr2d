#ifndef PXS_BODY_H
#define PXS_BODY_H

#include <QPainter>
#include <QObject>
#include <QPointF>
#include <QList>
#include <QVector2D>
#include "pxsobject.h"

typedef QVector2D        PxsForce;
typedef QList<QVector2D> PxsForces;

class PxsBody : public PxsObject
{
    Q_OBJECT
public:
    explicit PxsBody(const QPointF &p, PxsZone &zone);

    virtual void     addGravity(const PxsForce &f);
    virtual bool     move(double speed);
    virtual QRectF   boundingRect() const = 0;
    virtual PxsForce gravityTo(PxsBody *other) const;

    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);

signals:

public slots:

protected:
    virtual void accelerate(double speed);
    virtual void testCollision();
    virtual void testCollision(PxsBody *other);
    virtual void collideWith(PxsBody *other);
    virtual PxsForce collectForces() const;

    PxsForce  mGravity;
    float     mAcceleration;
    float     mMass;
};

typedef QList<PxsBody*> PxsBodies;

#endif
