#ifndef PXS_CAMERA_H
#define PXS_CAMERA_H

#include <QPainter>
#include <QObject>
#include <QSizeF>
#include <QPointF>
#include <QMatrix>
#include <QKeyEvent>

class PxsZone;
class PxsCameraEffect;
class PxsCamera : public QObject
{
    Q_OBJECT
public:
    enum AspectRatioMode {
        IgnoreAspectRatio, // Fit to Widget
        FitToScreen,
        AutoWidth,         // Calculate windowRect.width()
        AutoHeigh          // Calculate windowRect.height();
    };

    explicit PxsCamera(PxsZone *zone = NULL, QObject *parent = NULL);

    void    setProjectionRect(const QRect &projection);
    void    render(QPainter &p);
    QPointF center() const;

    void  keyPressEvent(QKeyEvent *event);
    void  keyReleaseEvent(QKeyEvent *event);

signals:
    void updateRequest();

public slots:
    void setAspectMode(int mode);
    void setAntialiasingEnabled(bool enabled);
    void setZone(PxsZone *zone);
    void lookTo(const QPointF &center);
    void rotate(float angle);
    void setWindow(const QSize &windowRect);
    void appendEffect(PxsCameraEffect *e);

private slots:
    void onFieldSizeChange();
    void effectDestroyed(QObject *effect);
    void setupWorldMatrix();

private:
    void setupFullscreenMatrix(const QRect &projectionRect, const QSize &windowRect);

    PxsZone        *mZone;
    QPointF         mCenter;
    QRect           mProjectionRect;
    QSize           mTargetWindowRect;
    QRectF          mCurrentWindowRect;
    float           mRotation;
    AspectRatioMode mAspectMode;
    bool            mAntialiasingEnabled;

    QMatrix         mMatrix;
    QList<PxsCameraEffect*> mEffects;
};

#endif // PXSCAMERA_H
