#ifndef PLATFORM_H
#define PLATFORM_H
#include <QRectF>


class Platform
{
    QRectF *platform = nullptr;//平台判定区指针
    qreal topCentralX;//平台顶部中心位置横坐标
public:
    Platform(qreal x,qreal y,qreal width,qreal height);
    ~Platform();
    bool is_stick = false;//平台的粘性
    void set_platform(QRectF n);//设置平台的位置及大小
    void set_left(qreal n);//设置平台左边界坐标
    void set_right(qreal n);//设置平台右边界坐标
    void set_topCentralX();//设置平台顶部中心横坐标
    void set_width(int width);//设置判定区长

    QRectF get_platform(){return QRectF(platform->left(),platform->top(),platform->width(),platform->height());}//得到平台的位置和大小
    qreal get_left(){return platform->left();}//得到平台左边界坐标
    qreal get_right(){return platform->right();}//得到平台右边界坐标
    qreal get_top(){return platform->top();}//得到平台上边界坐标
    qreal get_height(){return platform->height();}//得到平台高度
    qreal get_width(){return platform->width();}//得到平台宽度
    qreal get_topCentralX(){return topCentralX;}//得到每次移动距离

    void move(int n,int m);//移动
};

#endif // PLATFORM_H
