#include "gamemap.h"
#include <QImage>

#define SCALE 25

//-------------------------------------------------------------------------------------------------
GameMap::GameMap(const QString &filename)
{
    initFromFile(filename);
}

//-------------------------------------------------------------------------------------------------
void GameMap::initFromFile(const QString &filename)
{
   mRects.clear();
   mColors.clear();

   QImage img(filename);
   if (img.isNull())
       return;

   for (int y=0; y<img.height(); y++) {
       for (int x=0; x<img.width(); x++) {
           QColor c = img.pixel(x,img.height()-y-1);
           if (c.blackF() > 0) {
                mRects << QRect(x*SCALE, y*SCALE, SCALE, SCALE);
                mColors << c;
           }
       }
   }
}
