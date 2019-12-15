#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <QString>
#include <QRect>
#include <QList>
#include <QPainter>

class GameMap
{
public:
    GameMap(const QString &filename);

    void initFromFile(const QString &filename);

    inline const QList<QRect>  &rects()  const { return mRects; }
    inline const QList<QColor> &colors() const { return mColors; }

private:
    QList<QRect>  mRects;
    QList<QColor> mColors;
};

#endif // GAMEMAP_H
