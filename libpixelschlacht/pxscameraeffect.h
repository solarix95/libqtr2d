#ifndef PXSCAMERAEFFECT_H
#define PXSCAMERAEFFECT_H

#include <QObject>
#include <QTime>
#include <QMatrix>

class PxsCameraEffect : public QObject
{
    Q_OBJECT
public:
    PxsCameraEffect(int fps = 30);

    virtual void process(QMatrix &matrix) = 0;

signals:
    void updateRequest();

protected slots:
    virtual void update();

protected:
    int  elapsedMs() const;

private:
    QTime  mTime;
};

#endif // PXSCAMERAEFFECT_H
