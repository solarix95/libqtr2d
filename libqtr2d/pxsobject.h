#ifndef PXS_OBJECT_H
#define PXS_OBJECT_H

#include <QPainter>
#include <QObject>
#include <QPointF>
#include <QList>
#include <QVector2D>

class PxsZone;
class PxsObject : public QObject
{
    Q_OBJECT
public:
    explicit PxsObject(const QPointF &p, PxsZone &zone);

    void   render(QPainter &p) const;

    inline const   QPointF  &pos() const      { return mPos;      }
    inline void              setPos(const QPointF &p) { mPos = p; }
    inline const QVector2D  &velocity() const { return mVelocity; }
    inline void              setVelocity(const QVector2D &v) { mVelocity = v; }
    inline float             angle() const     { return mAngle; }
    inline void              setAngle(float a) { mAngle = a;    }
    inline void              setSpin(float s)  { mSpin  = s;    }
    inline float             distanceTo(const PxsObject &oth) const { return (mPos-oth.mPos).manhattanLength(); }

    virtual bool   move(double speed);
    virtual QRectF boundingRect() const = 0;
    virtual QRectF collisionRect() const;

signals:
    void changed(PxsObject *obj);
    void created(PxsObject *childObj);

protected:
    virtual void renderModelCentered(QPainter &p) const = 0;
    virtual void updatePosition(const QPointF &newPos);

    inline float     &spin()     { return mSpin;  }
    inline float     &angle()    { return mAngle; }
    inline PxsZone   &zone()     { return mZone;  }
    inline QVector2D &velocity() { return mVelocity; }

private:
    QPointF   mPos;
    PxsZone  &mZone;
    QVector2D mVelocity;
    float     mAngle; // current angle
    float     mSpin;
};

typedef QList<PxsObject*> PxsObjects;

#endif // SPACEOBJECT_H
