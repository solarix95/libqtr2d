#include <QFontMetrics>
#include "qtr2doptionmenu.h"

#define SPACING 10

//-------------------------------------------------------------------------------------------------
Qtr2dMenuOption::Qtr2dMenuOption(const QPixmap &icon)
 : mIcon(icon)
{
}

//-------------------------------------------------------------------------------------------------
Qtr2dMenuOption::Qtr2dMenuOption(const QPixmap &icon, const QString &text, const QFont &font)
 : mIcon(icon), mText(text), mFont(font)
{
}

//-------------------------------------------------------------------------------------------------
Qtr2dMenuOption::Qtr2dMenuOption(const QString &text, const QFont &font)
 : mText(text), mFont(font)
{
}

//-------------------------------------------------------------------------------------------------
QSize Qtr2dMenuOption::size() const
{
    QFontMetrics fm(mFont);
    int width  = mIcon.width() + fm.width(mText);

    if (mIcon.width() > 0 && mText.length() > 0)
        width += SPACING;

    int height = qMax(mIcon.height(),fm.height());


    return QSize(width,height);
}

//-------------------------------------------------------------------------------------------------
//                                     OptionMenu
//-------------------------------------------------------------------------------------------------
Qtr2dOptionMenu::Qtr2dOptionMenu(Qtr2dMenuStyle &style,const Qtr2dMenuOptions &options)
 : Qtr2dMenu(style)
 , mOptions(options)
{
    mCurrentIndex = mOptions.count() > 0 ? 0 : -1;
}

//-------------------------------------------------------------------------------------------------
QSize Qtr2dOptionMenu::size() const
{

    int maxOptionWidth = 0;
    int optionsHeight  = 0;
    for(auto option : mOptions) {
        maxOptionWidth = qMax(maxOptionWidth,option.size().width());
        optionsHeight += option.size().height();
    }
    optionsHeight += (mOptions.count() - 1) * SPACING;
    return QSize(2*style().border() + 2*style().padding() + maxOptionWidth,
                 2*style().border() + 2*style().padding() + optionsHeight);
}

//-------------------------------------------------------------------------------------------------
void Qtr2dOptionMenu::renderContent(QPainter &p, const QSize &boxSize)
{
    p.translate(style().padding(),style().padding());
    p.setPen(QPen(Qt::black,1));

    int index = 0;
    for(const auto &option : mOptions) {
        QRect optionRect = QRect(0,0,option.size().width(), option.size().height());
        p.drawText(optionRect,option.text());
        if (index == mCurrentIndex) {
            p.save();
            p.setPen(Qt::blue);
            p.drawRect(optionRect);
            p.restore();
        }

        p.translate(0,option.size().height() + SPACING);
        index++;
    }
}

//-------------------------------------------------------------------------------------------------
void Qtr2dOptionMenu::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Down) {
        if (mCurrentIndex < mOptions.count()-1)
            mCurrentIndex++;
        else if (mOptions.count() > 0)
            mCurrentIndex = 0;
        emit updateRequest();
    }

    if (event->key() == Qt::Key_Up) {
        if (mCurrentIndex > 0)
            mCurrentIndex--;
        else if (mOptions.count() > 0)
            mCurrentIndex = mOptions.count()-1;
        emit updateRequest();
    }

}


