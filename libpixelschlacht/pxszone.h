#ifndef PXS_ZONE_H
#define PXS_ZONE_H

#include <QObject>
#include <QList>
#include <QTime>
#include <QSizeF>
#include "pxsbody.h"

class PxsZone : public QObject
{
    Q_OBJECT
public:
    explicit PxsZone(QObject *parent = nullptr);

    virtual void init() = 0; // create bodies, setup game, ...

    inline const PxsBodies &bodies() const    { return mBodies;    }
    inline QSize            fieldSize() const { return mFieldSize; }
    inline int              fps() const       { return mLastFps;   }

signals:
    void updateRequest();
    void fieldSizeChanged();

public slots:

protected:
    // Basic Setup
    inline void setFieldSize(const QSize &s) { mFieldSize = s; emit fieldSizeChanged(); emit updateRequest(); }

    // Creation of new Bodies
    virtual void registerBody(PxsBody *bdy);

private slots:
    void bodyDestroyed(QObject *bdy);
    void heartBeat();
    void process(double time);

private:
    void updateGravity();

    PxsBodies  mBodies;
    QSize      mFieldSize;
    QTime      mGameInterval;
    int        mLastFps;
};

#endif
