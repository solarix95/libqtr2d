#include "simplebody.h"
#include "simplezone.h"

//-------------------------------------------------------------------------------------------------
SimpleZone::SimpleZone()
{
}

//-------------------------------------------------------------------------------------------------
void SimpleZone::init()
{
    setFieldSize(QSize(100,100));
    registerBody(new SimpleBody(QPointF(50,50),*this));
}
