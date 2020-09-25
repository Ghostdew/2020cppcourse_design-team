#include "platform.h"

Platform::Platform(qreal x,qreal y,qreal width,qreal height)
{
    platform = new QRectF(QPoint(x,y),QSize(width,height));
    set_topCentralX();
}


Platform::~Platform()
{
    delete platform;
    platform = nullptr;
}


void Platform::set_platform(QRectF n)//设置球的位置和大小
{
    platform->setRect(n.left(),n.top(),n.width(),n.height());
}



void Platform::set_left(qreal n)//设置左边界坐标
{
    platform->setLeft(n);
}



void Platform::set_right(qreal n)//设置右边界坐标
{
    platform->setRight(n);
}



void Platform::set_topCentralX()//设置平台的中心横坐标
{
    topCentralX=platform->right()-platform->width()/2;
}

void Platform::set_width(int width)
{
    platform->setWidth(width);
}

void Platform::move(int n,int m)//移动
{
    set_left(n-m);
    set_right(n+m);
    set_topCentralX();
}
