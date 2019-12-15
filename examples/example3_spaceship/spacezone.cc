#include "spaceship.h"
#include "spacezone.h"
#include "asteroid.h"

//-------------------------------------------------------------------------------------------------
Spacezone::Spacezone()
{
}

Spacezone::~Spacezone()
{
}

//-------------------------------------------------------------------------------------------------
void Spacezone::init()
{
    setFieldSize(QSize(200,100));
    registerBody(new Spaceship(QPointF(100,50),*this), true);
    createAsteroid();
}

//-------------------------------------------------------------------------------------------------
void Spacezone::renderBackground(QPainter &p, const QRectF &window)
{
    p.setBrush(Qt::black);
    p.drawRect(window);
}

//-------------------------------------------------------------------------------------------------
void Spacezone::createAsteroid()
{
    Asteroid *a = new Asteroid(QPointF(qrand()%fieldSize().width(),qrand()%fieldSize().height()),*this);
    connect(a, SIGNAL(destroyed(QObject*)), this, SLOT(createAsteroid()));
    registerBody(a);
}
