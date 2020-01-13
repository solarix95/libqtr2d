#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <QString>
#include <QRect>
#include <QList>
#include <QPointF>
#include <QPainter>

class GameMap
{
public:
    GameMap(const QString &filename);
    ~GameMap();

    void initFromFile(const QString &filename);

    inline     int scale() const               { return mScale;        }
    inline     int width() const               { return mWidth;        }
    inline     int height() const              { return mHeight;       }
    inline QColor *color(int x, int y) const   { return mRaster[y][x]; }

    inline QPoint  map(const QPointF &p) const { return QPoint((int)(p.x()/scale()),(int)(p.y()/scale())); }

    enum Element {
        Start,
        End,

        Swirl,
        Fishes
    };

    QList<QPointF> positionsOf(Element e) const;

private:
    void destroy();

    int           mScale;
    int           mWidth;
    int           mHeight;
    QColor     ***mRaster;

    QMap<Element, QList<QPointF> > mPositions;
};

#endif // GAMEMAP_H
