#ifndef PXS_ZONE_H
#define PXS_ZONE_H

#include <QObject>
#include <QList>
#include <QTime>
#include <QSizeF>
#include <QPainter>
#include "pxsbody.h"
#include "pxsparticle.h"

class PxsCameraEffect;
class PxsBackground;

class PxsZone : public QObject
{
    Q_OBJECT
public:
    explicit PxsZone(QObject *parent = nullptr);
    virtual ~PxsZone();

    void render(QPainter &p);

    virtual void init() = 0; // create bodies, setup game, ...

    inline const PxsBodies    &bodies() const     { return mBodies;     }
    inline const PxsParticles &particles() const  { return mParticles;  }
    inline const QSize        &fieldSize() const  { return mFieldSize;  }
    inline QRect               fieldRect() const  { return QRect(0,0,mFieldSize.width(),mFieldSize.height()); }
    inline int                 fps() const        { return mLastFps;    }

    // User events
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);

    // Particle Factories
    virtual void createParticles(const QRectF &rect, const QVector2D &dir, int count, float radius, QColor c, int durationMs);
    virtual void createExplosion(const QPointF &pos, float force);

    virtual void appendBackground(PxsBackground *bk);

signals:
    void updateRequest();
    void fieldSizeChanged();
    void requestCameraEffect(PxsCameraEffect*);

public slots:

protected:
    // Basic Setup
    inline void setFieldSize(const QSize &s) { mFieldSize = s; emit fieldSizeChanged(); emit updateRequest(); }

    // Creation of new Bodies
    virtual void registerBody(PxsBody *bdy, bool isInputBody = false);

    virtual void renderBackground(QPainter &p);
    virtual void renderPlayers(QPainter &p);

private slots:
    void bodyDestroyed(QObject *bdy);
    void particleDestroyed(QObject *bdy);
    void heartBeat();
    void process(double time);

private:
    void updateGravity();

    PxsBodies      mBodies;
    PxsBody       *mInputBody;
    PxsParticles   mParticles;
    PxsBackground *mBackground;

    QSize          mFieldSize;
    QTime          mGameInterval;
    int            mLastFps;
};

#endif
