#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include "pxswidget.h"
#include "pxscamera.h"
#include "pxsfollowcamera.h"
#include "gamezone.h"

class GameWidget : public PxsWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);

protected:
    virtual void keyPressEvent(QKeyEvent *event);

private:
    GameZone         mZone;
    PxsCamera        mCam1;
    PxsFollowCamera  mCam2;
};

#endif // GAMEWIDGET_H
