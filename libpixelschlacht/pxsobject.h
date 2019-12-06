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
    inline const QVector2D  &velocity() const { return mVelocity; }
    inline float            angle() const     { return mAngle; }
    inline float            distanceTo(const PxsObject &oth) const { return (mPos-oth.mPos).manhattanLength(); }

    virtual bool   move(double speed);
    virtual QRectF boundingRect() const = 0;

signals:
    void changed(PxsObject *obj);

protected:
    virtual void renderModelCentered(QPainter &p) const = 0;
    inline QPointF   &pos()      { return mPos;   }
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
