#include "brick.h"

Brick::Brick(qreal x,qreal y,qreal width,qreal height,QLabel *p,int live,int id)
{
    brick = new QRectF(QPoint(x,y),QSize(width,height));
    health = live;
    brickLabel = p;
    ID = id;
}

Brick::~Brick()
{
    delete brickLabel;
    delete brick;
    brick = nullptr;
    brickLabel = nullptr;
}
