#ifndef PXS_WIDGET_H
#define PXS_WIDGET_H

#include <QWidget>

class PxsCamera;
class PxsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PxsWidget(QWidget *parent = NULL);
    explicit PxsWidget(PxsCamera *camera, QWidget *parent = NULL);

    void setCamera(PxsCamera *camera);

protected:
    virtual void resizeEvent(QResizeEvent *event);
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);

signals:

public slots:

private:
    PxsCamera *mCamera;
};

#endif // PXS_WIDGET_H
