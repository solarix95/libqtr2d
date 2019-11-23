#include "spaceship.h"
#include "spacezone.h"

//-------------------------------------------------------------------------------------------------
Spacezone::Spacezone()
{
}

//-------------------------------------------------------------------------------------------------
void Spacezone::init()
{
    setFieldSize(QSize(100,100));
    registerBody(new Spaceship(QPointF(50,50),bodies()));
}
