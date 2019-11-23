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

    // User events
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);


signals:
    void updateRequest();
    void fieldSizeChanged();

public slots:

protected:
    // Basic Setup
    inline void setFieldSize(const QSize &s) { mFieldSize = s; emit fieldSizeChanged(); emit updateRequest(); }

    // Creation of new Bodies
    virtual void registerBody(PxsBody *bdy, bool isInputBody = false);

private slots:
    void bodyDestroyed(QObject *bdy);
    void heartBeat();
    void process(double time);

private:
    void updateGravity();

    PxsBodies  mBodies;
    PxsBody   *mInputBody;
    QSize      mFieldSize;
    QTime      mGameInterval;
    int        mLastFps;
};

#endif
