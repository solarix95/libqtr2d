
#include <QTimer>
#include <QTime>
#include "pxszone.h"
#include "pxsbody.h"

#define GAME_INTERVAL (1000/60)

//-------------------------------------------------------------------------------------------------
PxsZone::PxsZone(QObject *parent)
    : QObject(parent)
    , mInputBody(NULL)
{
    qsrand(QTime::currentTime().minute() + QTime::currentTime().msec());
    mLastFps = 0;
    QTimer *t = new QTimer();
    connect(t, &QTimer::timeout, this, &PxsZone::heartBeat);
    t->start(GAME_INTERVAL);
}

//-------------------------------------------------------------------------------------------------
PxsZone::~PxsZone()
{
}

//-------------------------------------------------------------------------------------------------
void PxsZone::keyPressEvent(QKeyEvent *event)
{
    if (mInputBody)
        mInputBody->keyPressEvent(event);
}

//-------------------------------------------------------------------------------------------------
void PxsZone::keyReleaseEvent(QKeyEvent *event)
{
    if (mInputBody)
        mInputBody->keyReleaseEvent(event);
}

//-------------------------------------------------------------------------------------------------
void PxsZone::registerBody(PxsBody *bdy, bool isInputBody)
{
    Q_ASSERT(bdy);
    connect(bdy, SIGNAL(destroyed(QObject*)), this, SLOT(bodyDestroyed(QObject*)));
    mBodies << bdy;
    if (isInputBody)
        mInputBody = bdy;
}

//-------------------------------------------------------------------------------------------------
void PxsZone::bodyDestroyed(QObject *bdy)
{
    mBodies.removeAll((PxsBody*)bdy);
    if (mInputBody == (PxsBody*)bdy)
        mInputBody = NULL;
}

//-------------------------------------------------------------------------------------------------
void PxsZone::updateGravity()
{
    PxsForce g;
    for (int i=0; i<mBodies.count(); i++) {
        PxsBody *o = mBodies.at(i);
        for (int j=i+1; j<mBodies.count(); j++) {
            g = mBodies[j]->gravityTo(o);
            if (g.isNull())
                continue;
            mBodies[j]->addGravity(g);
            o->addGravity(-g);
        }
    }
}

//-------------------------------------------------------------------------------------------------
void PxsZone::heartBeat()
{
    if (mGameInterval.elapsed() <= 0) {
        mGameInterval.start();
        return;
    }
    mLastFps = 1000/mGameInterval.elapsed();
    process(mGameInterval.elapsed()/GAME_INTERVAL);
    mGameInterval.start();
}

//-------------------------------------------------------------------------------------------------
void PxsZone::process(double time)
{
    updateGravity();
    foreach(PxsObject *obj, mBodies) {
        while (obj->move(time)) {
        }
    }

    emit updateRequest();
}
