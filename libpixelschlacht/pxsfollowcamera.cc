#include "pxsobject.h"
#include "pxsfollowcamera.h"

//----------------------------------------------------------------------------------
PxsFollowCamera::PxsFollowCamera(PxsZone *zone, QObject *parent)
 : PxsCamera(zone,parent)
 , mFollowMe(NULL)
{
}

//----------------------------------------------------------------------------------
void PxsFollowCamera::followObject(const PxsObject *obj)
{
    if (mFollowMe)
        mFollowMe->disconnect(this);

    mFollowMe = obj;
    if (!mFollowMe)
        return;

    connect(obj, SIGNAL(destroyed(QObject*)), this, SLOT(objDestroyed(QObject*)));
    connect(obj, SIGNAL(changed(PxsObject*)), this, SLOT(updateCam()));
    updateCam();
}

//----------------------------------------------------------------------------------
void PxsFollowCamera::objDestroyed(QObject *obj)
{
    if (mFollowMe != obj)
        return;
    mFollowMe = NULL;
    updateCam();
}

//----------------------------------------------------------------------------------
void PxsFollowCamera::updateCam()
{
    if (!mFollowMe)
        return;
    lookTo(mFollowMe->pos());
    rotate(mFollowMe->angle());
}
