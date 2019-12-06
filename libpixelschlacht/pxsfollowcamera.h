#ifndef PXSFOLLOWCAMERA_H
#define PXSFOLLOWCAMERA_H

#include "pxscamera.h"

class PxsObject;
class PxsFollowCamera : public PxsCamera
{
    Q_OBJECT
public:
    PxsFollowCamera(PxsZone *zone = NULL, QObject *parent = NULL);

    void followObject(const PxsObject *obj);

private slots:
    void objDestroyed(QObject *obj);
    void updateCam();

private:
    const PxsObject *mFollowMe;
};

#endif // PXSFOLLOWCAMERA_H
