#ifndef ITEM_H
#define ITEM_H


#include <QLabel>
#include <QRectF>

class Item
{
    QRectF *item = nullptr;//道具判定区
    int ID;//道具的类别,1为板增长道具，2为板缩短道具，3为球加快道具，4为球减速道具，5为板变粘道具，6为加命道具
public:
    Item(int numid,qreal x,qreal y,qreal width,qreal height);
    void move();//贴图移动
    int get_id(){return ID;}//得到道具的类别
    int get_left(){return item->left();}//得到道具判定区左边界的坐标
    int get_right(){return item->right();}//得到道具判定区右边界的坐标
    int get_top(){return item->top();}//得到道具判定区上边界的坐标
    int get_bottom(){return item->bottom();}//得到砖道具判定区下边界的坐标
    bool is_hit = false;//道具是否已经使用\丢弃
    ~Item();

};

#endif // ITEM_H
