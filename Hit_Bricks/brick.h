#ifndef BRICK_H
#define BRICK_H

#include <QLabel>
#include <QRectF>

class Brick
{
    QLabel *brickLabel=nullptr;//砖块贴图
    QRectF *brick = nullptr;//砖块判定区
    int health;//砖块生命值
    int ID;//砖块颜色，1为蓝色，2为绿色，3为橘黄色，4为灰色
public:
    Brick(qreal x,qreal y,qreal width,qreal height,QLabel *p,int live,int id);
    QRectF get_brick(){return QRectF(brick->left(),brick->top(),brick->width(),brick->height());}//得到砖块的判定区域
    QLabel *get_label(){return brickLabel;}//得到砖块贴图指针
    void set_health(int num){health = num;}//设置小球生命值
    int get_id(){return ID;}//得到小球的类别
    int get_health(){return health;}//得到小球生命值
    int get_left(){return brick->left();}//得到砖块判定区左边界的坐标
    int get_right(){return brick->right();}//得到砖块判定区右边界的坐标
    int get_top(){return brick->top();}//得到砖块判定区上边界的坐标
    int get_bottom(){return brick->bottom();}//得到砖块判定区下边界的坐标
    ~Brick();
};

#endif // BRICK_H
