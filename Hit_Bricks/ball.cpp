#include "ball.h"

Ball::Ball(qreal d,qreal x,qreal y)
{
    ball= new QRectF(QPoint(x,y),QSize(d,d));
    angel=0;
    speed=0;
    radius = d/2;
    set_ball_centralx();
    set_ball_centraly();
}
Ball::~Ball()
{
    delete ball;
    ball = nullptr;
}

void Ball::set_angel(float n)//设置角度的大小
{
    angel=n;
}

void Ball::set_speed(int n)//设置速度的大小
{
    speed=n;
}

void Ball::set_ball(QRectF n)//设置球的位置和大小
{
    ball->setRect(n.left(),n.top(),n.width(),n.height());
}

void Ball::set_radius(qreal n)//设置小球半径
{
    radius = n;
}

void Ball::set_ball_centralx()//设置小球的横坐标
{
    ball_centralx=ball->right()-ball->width()/2;
}

void Ball::set_ball_centraly()//设置小球的纵坐标
{
    ball_centraly=ball->top()+ball->height()/2;
}

void Ball::move()//移动小球
{
    float Pi=3.1415926;
    ball->setLeft(ball->left()+speed*qSin(angel*Pi/180));
    ball->setRight(ball->right()+speed*qSin(angel*Pi/180));
    ball->setTop(ball->top()-speed*qCos(angel*Pi/180));
    ball->setBottom(ball->bottom()-speed*qCos(angel*Pi/180));
    set_ball_centralx();
    set_ball_centraly();
}
