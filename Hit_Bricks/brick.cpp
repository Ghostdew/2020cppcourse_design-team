#include "brick.h"

Brick::Brick(qreal x,qreal y,qreal width,qreal height,QLabel *p)
{
    brick = new QRectF(QPoint(x,y),QSize(width,height));
    brickLabel = p;
}

Brick::~Brick()
{
    delete brickLabel;
    delete brick;
    brick = nullptr;
    brickLabel = nullptr;
}
