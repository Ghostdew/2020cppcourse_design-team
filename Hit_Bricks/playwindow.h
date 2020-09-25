#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QToolButton>
#include <QTimer>
#include <QMouseEvent>
#include <QLabel>
#include <time.h>
#include "ball.h"
#include "platform.h"
#include "brick.h"
#include "dataconfig.h"
#include "item.h"

class playwindow : public QMainWindow
{
    Q_OBJECT
public:
    playwindow(int num);
    void paintEvent(QPaintEvent *e);
    void createball();//初始化小球
    void createplatform();//初始化平台
    void createbrick();//初始化砖块
    void collision();//碰撞函数
    void mouseMoveEvent(QMouseEvent *event);//鼠标移动事件
    void mouseReleaseEvent(QMouseEvent *event);//鼠标释放事件
    ~playwindow();
private:
    int delta;//小球与板间距，粘性板用
    int levelNum;//关卡名
    int mousepos;//鼠标实时位置
    int gameSpeed = 20;//游戏速度**************基本不变，调速还是用ball->set_speed()好
    int levelData[7][9];//关卡砖块数据数组
    bool is_move = false;//球是否已离开板的判定器
    QTimer Ball_Timer,Platform_Timer;//定时器
    Ball *ball = nullptr;//球的判定方块指针
    Platform *board = nullptr;//板的判定方块指针
    QLabel *ball_label = nullptr,*platform_label = nullptr,*item_label = nullptr;//球和板和道具的贴图指针
    Item *item1=nullptr;//道具指针，最多同时出现一个道具
    Brick *bricks[7][9];//砖块指针数组

signals:
    void playwindowBack();

public slots:
};

#endif // PLAYWINDOW_H
