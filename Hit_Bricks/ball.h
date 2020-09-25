#ifndef BALL_H
#define BALL_H
#include <QRectF>
#include <QtMath>
class Ball
{
    float angel;//小球运动的角度
    int speed;//小球运动的速度
    qreal ball_centralx,ball_centraly,radius;//球心横坐标、小球半径
    QRectF *ball = nullptr;//小球判定区指针
public:
    Ball(qreal r,qreal x,qreal y);
    ~Ball();
    void set_angel(float n);//设置角度的大小
    void set_speed(int n);//设置速度的大小

    void set_ball(QRectF n);//设置球的位置及大小

    void set_radius(qreal n);//设置小球半径
    void set_ball_centralx();//设置小球的中心横坐标
    void set_ball_centraly();//设置小球的中心纵坐标

    float get_angel(){return angel;}//得到角度的大小
    int get_speed(){return speed;}//得到速度的大小

    int get_left(){return ball->left();}//得到小球判定区左边界的坐标
    int get_right(){return ball->right();}//得到小球判定区右边界的坐标
    int get_top(){return ball->top();}//得到小球判定区上边界的坐标
    int get_bottom(){return ball->bottom();}//得到小球判定区下边界的坐标
    int get_radius(){return radius;}//得到小球的半径
    qreal get_Pointx(){return ball->topLeft().x();}//得到小球判定区左上点的横坐标
    qreal get_Pointy(){return ball->topLeft().y();}//得到小球判定区左上点的纵坐标

    QRectF get_ball(){return QRectF(ball->left(),ball->top(),ball->width(),ball->height());}//得到球的判定区域
    qreal get_ball_centralx(){return ball_centralx;}//得到球心横坐标
    qreal get_ball_centraly(){return ball_centraly;}//得到球心纵坐标

    void move();//移动小球
};

#endif // BALL_H
