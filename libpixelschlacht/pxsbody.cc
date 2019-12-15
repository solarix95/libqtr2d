#include "pxsbody.h"
#include "pxszone.h"
#include <QDebug>

//-------------------------------------------------------------------------------------------------
PxsBody::PxsBody(const QPointF &p, PxsZone &zone)
    : PxsObject(p, zone)
    , mAcceleration(0.0)
    , mMass(0)
    , mCollisionType(RectCollision)
    , mCollisionRadius(0)
{
}

//-------------------------------------------------------------------------------------------------
void PxsBody::addGravity(const PxsForce &f)
{
    mGravity.setX(mGravity.x() + f.x());
    mGravity.setY(mGravity.y() + f.y());
}

//-------------------------------------------------------------------------------------------------
bool PxsBody::move(double speed)
{
    angle() += spin()*speed;

    accelerate(speed);
    velocity().setX(velocity().x() + mGravity.x());
    velocity().setY(velocity().y() + mGravity.y());

    QPointF newPos(pos().x() + velocity().x(),pos().y() + velocity().y());
    if (newPos != pos()) {
        pos() = newPos;
        emit changed(this);
    }

    testCollision();

    mGravity = PxsForce(0,0);
    return false;
}

//-------------------------------------------------------------------------------------------------
QRectF PxsBody::collisionRect() const
{
    return boundingRect();
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
    if (QVector2D(this->pos() - other->pos()).length() > (this->mCollisionRadius + other->mCollisionRadius))
        return;

    // Rect/Rect Collision
    if (this->mCollisionType == RectCollision && other->mCollisionType == RectCollision) {
        if (this->collisionRect().intersects(other->collisionRect()))
            this->collideWith(other);
        return;
    }

    // Radial/Radial
    if (this->mCollisionType == RadialCollision && other->mCollisionType == RadialCollision) {
        this->collideWith(other);
        return;
    }

    // Rect/Radial
    PxsBody *rectBody  = this->mCollisionType == RectCollision ? this : other;
    PxsBody *radialBody = rectBody == this ? other : this;


}

//-------------------------------------------------------------------------------------------------
void PxsBody::collideWith(PxsBody *other)
{
    Q_ASSERT(this != other);
    this->onCollision(other);
    other->onCollision(this);
}

//-------------------------------------------------------------------------------------------------
void PxsBody::onCollision(PxsBody *)
{
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
    if (this == other)
        return PxsForce();

    QPointF v = other->pos() - this->pos();
    PxsForce f(v.x(),v.y());
    float d = f.length();
    float g = this->mMass/(d*d);
    // float g = qMin(this->mMass/(d*d),.5f);
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
    emit changed(this);
}
