#include "gamemap.h"
#include <QImage>

#define SCALE 25

//-------------------------------------------------------------------------------------------------
GameMap::GameMap(const QString &filename)
    :  mScale(SCALE)
    ,  mWidth(0)
    ,  mHeight(0)
    ,  mRaster(NULL)
{
    initFromFile(filename);
}

//-------------------------------------------------------------------------------------------------
GameMap::~GameMap()
{
    destroy();
}

//-------------------------------------------------------------------------------------------------
void GameMap::initFromFile(const QString &filename)
{
   destroy();

   QImage img(filename);
   if (img.isNull())
       return;

   mWidth = img.width();
   mHeight = img.height();
   Q_ASSERT(mWidth * mHeight > 0);
   mRaster = new QColor**[mHeight];

   for (int y=0; y<mHeight; y++) {
       mRaster[y] = new QColor*[mWidth];

       for (int x=0; x<mWidth; x++) {
           QColor c = img.pixel(x,img.height()-y-1);

           mRaster[y][x] = NULL;
           if (c == Qt::red)
               mPositions[Start] << QPointF(x*mScale + mScale/2,y*mScale + mScale/2);
           else if (c == Qt::magenta)
               mPositions[Swirl] << QPointF(x*mScale + mScale/2,y*mScale + mScale/2);
           else if (c == Qt::yellow)
               mPositions[Fishes] << QPointF(x*mScale + mScale/2,y*mScale + mScale/2);
           else if ((c.red() + c.green() + c.blue()) && c != Qt::white)
                mRaster[y][x] = new QColor(c);
       }
   }
}

//-------------------------------------------------------------------------------------------------
QList<QPointF> GameMap::positionsOf(GameMap::Element e) const
{
    return mPositions[e];
}

//-------------------------------------------------------------------------------------------------
void GameMap::destroy()
{
    if (!mRaster)
        return;

    for (int y=0;y < mHeight; y++) {
        for (int x=0; x < mWidth; x++) {
            if (mRaster[y][x])
                delete mRaster[y][x];
        }
        delete [] mRaster[y];
    }
    delete [] mRaster;
    mRaster = NULL;
}
