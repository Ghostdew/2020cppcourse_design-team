#ifndef BRICK_H
#define BRICK_H

#include <QLabel>
#include <QRectF>

class Brick
{
    QLabel *brickLabel=nullptr;
    QRectF *brick = nullptr;
    int health = 1;
public:
    Brick(qreal x,qreal y,qreal width,qreal height,QLabel *p);
    QRectF get_brick(){return QRectF(brick->left(),brick->top(),brick->width(),brick->height());}//得到砖块的判定区域
    QLabel *get_label(){return brickLabel;}
    void set_health(int num){health = num;}
    int get_health(){return health;}
    int get_left(){return brick->left();}//得到砖块判定区左边界的坐标
    int get_right(){return brick->right();}//得到砖块判定区右边界的坐标
    int get_top(){return brick->top();}//得到砖块判定区上边界的坐标
    int get_bottom(){return brick->bottom();}//得到砖块判定区下边界的坐标
    ~Brick();
};

#endif // BRICK_H
