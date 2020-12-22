#ifndef PXSBACKGROUND_H
#define PXSBACKGROUND_H

#include <QObject>
#include <QPainter>

class PxsZone;
class PxsObject;
class PxsBackground : public QObject
{
    Q_OBJECT
public:
    PxsBackground();

    virtual void setZone(const PxsZone *zone);
    virtual bool testCollision(PxsObject *bdy) const;

    void render(QPainter &p, const QRectF &window);

signals:
    void updateRequest();

protected:
    const PxsZone &zone() const;
    virtual void renderBkgnd(QPainter &p, const QRectF &window) = 0;

private:
    const PxsZone *mZone;
};

#endif // PXSBACKGROUND_H
