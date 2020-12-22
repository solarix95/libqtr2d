#ifndef PXSFOLLOWCAMERA_H
#define PXSFOLLOWCAMERA_H

#include <QFlags>
#include "pxscamera.h"

class PxsObject;
class PxsFollowCamera : public PxsCamera
{
    Q_OBJECT
public:
    enum Option {
        NoOptions      = 0x00,
        FollowPosition = 0x01,
        FollowAngle    = 0x02
    };
    Q_DECLARE_FLAGS(Options, Option)

    PxsFollowCamera(PxsZone *zone = NULL, QObject *parent = NULL);

    void followObject(const PxsObject *obj,Options options = FollowPosition);

private slots:
    void objDestroyed(QObject *obj);
    void updateCam();

private:
    Options          mOptions;
    const PxsObject *mFollowMe;
};

#endif // PXSFOLLOWCAMERA_H
