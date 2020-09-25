#include "item.h"


Item::Item( int numid,qreal x,qreal y,qreal width,qreal height)
{
    item = new QRectF(QPoint(x,y),QSize(width,height));
    ID = numid;
}


void Item::move()
{
    item->setTop(item->top()+5);
    item->setBottom(item->bottom()+5);
}

Item::~Item()
{
    delete item;
}
