#include "pxsobject.h"
#include <QDebug>

//-------------------------------------------------------------------------------------------------
PxsObject::PxsObject(const QPointF &p, PxsZone &zone)
    : QObject(NULL)
    , mPos(p)
    , mZone(zone)
    , mAngle(0)
    , mSpin(0)
{
}

//-------------------------------------------------------------------------------------------------
void PxsObject::render(QPainter &p) const
{
    p.save();

    p.translate(mPos);
    p.rotate(mAngle);

    renderModelCentered(p);

    p.restore();
}

//-------------------------------------------------------------------------------------------------
bool PxsObject::move(double speed)
{
    if (mSpin)
        mAngle += mSpin*speed;

    if (mVelocity.x())
        mPos.setX(mPos.x() + mVelocity.x());

    if (mVelocity.y())
        mPos.setY(mPos.y() + mVelocity.y());

    emit changed(this);
    return false;
}

/*
//-------------------------------------------------------------------------------------------------
void PxsObject::testCollision()
{
    foreach(SpaceObject *other, mFriends) {
        if (other != this)
            other->testCollision(this);
    }
}

//-------------------------------------------------------------------------------------------------
void PxsObject::testCollision(SpaceObject *other)
{
    Q_ASSERT(this != other);
    if (this->boundingRect().intersects(other->boundingRect())) {
        this->collideWith(other);
        other->collideWith(this);
    }
}

//-------------------------------------------------------------------------------------------------
Forces SpaceObject::collectForces() const
{
    Forces f;
    QMatrix m;
    m.translate(0,mAcceleration);
    m.rotate(mAngle);

    f << Force(m.dx(),m.dy());
    Force next;
    foreach(SpaceObject *other, mFriends) {
        if (other == this)
            continue;
        next = other->gravityTo(this);
        if (!next.isNull())
            f << next;
    }

    return f;
}

//-------------------------------------------------------------------------------------------------
Force SpaceObject::gravityTo(SpaceObject *other) const
{
    Q_ASSERT(this != other);

    QPointF v = other->mPos - this->mPos;
    Force f(v.x(),v.y());
    float d = f.length();
    float g = (other->mMass + this->mMass)/(d*d);

    f.normalize();
    f *= g;
    return f;
}
*/
