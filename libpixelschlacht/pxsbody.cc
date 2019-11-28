#include "pxsbody.h"
#include "pxszone.h"
#include <QDebug>

//-------------------------------------------------------------------------------------------------
PxsBody::PxsBody(const QPointF &p, PxsZone &zone)
    : PxsObject(p, zone)
    , mAcceleration(0.0)
    , mMass(0)
{
}

//-------------------------------------------------------------------------------------------------
void PxsBody::addGravity(const PxsForce &f)
{
    mGravity << f;
}

//-------------------------------------------------------------------------------------------------
bool PxsBody::move(double speed)
{
    angle() += spin()*speed;

    accelerate(speed);
    pos().setX(pos().x() + velocity().x());
    pos().setY(pos().y() + velocity().y());

    testCollision();

    mGravity.clear();
    return false;
}

//-------------------------------------------------------------------------------------------------
void PxsBody::testCollision()
{
    foreach(PxsBody *other, zone().bodies()) {
        if (other != this)
            other->testCollision(this);
    }
}

//-------------------------------------------------------------------------------------------------
void PxsBody::testCollision(PxsBody *other)
{
    Q_ASSERT(this != other);
    if (this->boundingRect().intersects(other->boundingRect())) {
        this->collideWith(other);
        other->collideWith(this);
    }
}

//-------------------------------------------------------------------------------------------------
void PxsBody::collideWith(PxsBody *other)
{
    Q_ASSERT(this != other);
    // deleteLater();
}

//-------------------------------------------------------------------------------------------------
PxsForce PxsBody::collectForces() const
{
    /*
    PxsForces f;
    QMatrix m;
    m.translate(0,mAcceleration);
    m.rotate(mAngle);

    f << PxsForce(m.dx(),m.dy());
    */
    PxsForce next;
    return next;
    /*
    foreach(PxsBody *other, mFriends) {
        if (other == this)
            continue;
        next = other->gravityTo(this);
        if (!next.isNull())
            f << next;
    }

    return f;
    */
}

//-------------------------------------------------------------------------------------------------
PxsForce PxsBody::gravityTo(PxsBody *other) const
{
    Q_ASSERT(this != other);

    QPointF v = other->pos() - this->pos();
    PxsForce f(v.x(),v.y());
    float d = f.length();
    float g = (other->mMass + this->mMass)/(d*d);

    f.normalize();
    f *= g;
    return f;
}

//-------------------------------------------------------------------------------------------------
void PxsBody::keyPressEvent(QKeyEvent*)
{
}

//-------------------------------------------------------------------------------------------------
void PxsBody::keyReleaseEvent(QKeyEvent *)
{
}

//-------------------------------------------------------------------------------------------------
void PxsBody::accelerate(double speed)
{
    if (!mAcceleration)
        return;
    QMatrix m;
    m.rotate(angle());
    QPointF acc(0,mAcceleration*speed);
    acc = acc * m;

    velocity().setX(velocity().x() + acc.x());
    velocity().setY(velocity().y() + acc.y());
}
