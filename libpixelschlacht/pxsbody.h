#ifndef PXS_BODY_H
#define PXS_BODY_H

#include <QPainter>
#include <QObject>
#include <QPointF>
#include <QKeyEvent>
#include <QList>
#include <QVector2D>
#include "pxsobject.h"
#include "pxsbasetypes.h"

class PxsBody : public PxsObject
{
    Q_OBJECT
public:
    explicit PxsBody(const QPointF &p, PxsZone &zone);

    virtual void     addGravity(const PxsForce &f);
    virtual bool     move(double speed);
    virtual PxsForce gravityTo(PxsBody *other) const;

    // Input Events
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);

signals:

public slots:

protected:
    virtual void accelerate(double speed);
    virtual void testCollision();
    virtual void testCollision(PxsBody *other);

    void collideWith(PxsBody *other);
    virtual void onCollision(PxsBody *other);

    virtual PxsForce collectForces() const;

    PxsForce  mGravity;
    float     mAcceleration;
    float     mMass;

    enum CollisionType {
        RectCollision,
        RadialCollision,
    };

    CollisionType mCollisionType;
    float         mCollisionRadius;
};

typedef QList<PxsBody*> PxsBodies;

#endif
