#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include "qtr2dwidget.h"
#include "qtr2dcamera.h"
#include "qtr2dfollowcamera.h"
#include "gamezone.h"

class GameWidget : public Qtr2dWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);

protected:
    virtual void keyPressEvent(QKeyEvent *event);

private:
    GameZone         mZone;
    Qtr2dCamera        mCam1;
    Qtr2dFollowCamera  mCam2;
};

#endif // GAMEWIDGET_H
