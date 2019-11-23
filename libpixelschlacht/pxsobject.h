#ifndef PXS_OBJECT_H
#define PXS_OBJECT_H

#include <QPainter>
#include <QObject>
#include <QPointF>
#include <QList>
#include <QVector2D>

class PxsObject : public QObject
{
    Q_OBJECT
public:
    explicit PxsObject(const QPointF &p, QObject *parent = nullptr);

    void   render(QPainter &p) const;

    inline const   QPointF  &pos() const      { return mPos;      }
    inline const QVector2D  &velocity() const { return mVelocity; }
    inline float            angle() const     { return mAngle; }
    inline float            distanceTo(const PxsObject &oth) const { return (mPos-oth.mPos).manhattanLength(); }

    virtual bool   move(double speed);
    virtual QRectF boundingRect() const = 0;

protected:
    virtual void renderModelCentered(QPainter &p) const = 0;

    QPointF   mPos;
    QVector2D mVelocity;
    float     mAngle; // current angle
    float     mSpin;  // angle per interval
};

typedef QList<PxsObject*> PxsObjects;

#endif // SPACEOBJECT_H
