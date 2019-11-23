#include "pxsbody.h"
#include <QDebug>

//-------------------------------------------------------------------------------------------------
PxsBody::PxsBody(const QPointF &p, const QList<PxsBody*> &friends)
    : PxsObject(p, NULL)
    , mMass(0)
    , mFriends(friends)
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
    mAngle += mSpin*speed;

    mPos.setX(mPos.x() + mVelocity.x());
    mPos.setY(mPos.y() + mVelocity.y());

    testCollision();

    mGravity.clear();
    return false;
}

//-------------------------------------------------------------------------------------------------
void PxsBody::testCollision()
{
    foreach(PxsBody *other, mFriends) {
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
    // return boundingRect().intersects(other->boundingRect());
}

//-------------------------------------------------------------------------------------------------
PxsForce PxsBody::collectForces() const
{
    PxsForces f;
    QMatrix m;
    m.translate(0,mAcceleration);
    m.rotate(mAngle);

    f << PxsForce(m.dx(),m.dy());
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

    QPointF v = other->mPos - this->mPos;
    PxsForce f(v.x(),v.y());
    float d = f.length();
    float g = (other->mMass + this->mMass)/(d*d);

    f.normalize();
    f *= g;
    return f;
}
