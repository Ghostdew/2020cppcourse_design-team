#include "playwindow.h"
#include <QDebug>

playwindow::playwindow(int num)
{
    levelNum = num;

    for(int i=0;i<7;i++)
    {
        for(int j=0;j<9;j++)
            bricks[i][j] = nullptr;
    }//砖块指针置空

    setFixedSize(800,550);
    setWindowIcon(QIcon(":/image/windowicon.jpg"));
    setWindowTitle("打砖块");

    QToolButton *backButton = new QToolButton(this);
    backButton->setFixedSize(91,41);
    backButton->move(720,10);
    backButton->setStyleSheet("border-image: url(:/image/BackButton.png);");

    connect(backButton,&QToolButton::pressed,this,[=](){
        backButton->setStyleSheet("border-image: url(:/image/BackButtonSelected.png);");
    });//退出按钮按下效果实现

    connect(backButton,&QToolButton::released,this,[=](){
        backButton->setStyleSheet("border-image: url(:/image/BackButton.png);");
        QTimer::singleShot(300,this,[=](){
            this->hide();
            emit playwindowBack();
        });
    });

    dataconfig config;

    for(int i=0;i<7;i++)
    {
        for(int j=0;j<9;j++)
        {
            levelData[i][j] = config.Data[levelNum][i][j];//读取对应关卡数据
        }
    }



    createplatform();//创建平台实例
    createball();//创建小球实例
    createbrick();//创建砖块

    setMouseTracking(true);//设置鼠标追踪
    Platform_Timer.start(gameSpeed);//启动初始定时器

    connect(&Ball_Timer,&QTimer::timeout,this,[=](){
       platform_label->move(mousepos-platform_label->width()/2,500);//捕捉鼠标移动label平台
       board->move(mousepos,platform_label->width()/2);//捕捉鼠标移动矩形类平台
       collision();//判断是否发生碰撞
       ball->move();//小球移动
       ball_label->move((int)ball->get_Pointx(),(int)ball->get_Pointy());//label小球随矩形类小球一起运动
       if(item1!=nullptr)//道具掉落
       {
           if(!item1->is_hit)
           {
               item1->move();
               item_label->move(item1->get_left(),item1->get_top());
           }

       }
    });//设置小球移动

    connect(&Platform_Timer,&QTimer::timeout,this,[=](){
        platform_label->move(mousepos-platform_label->width()/2,500);//捕捉鼠标移动label平台
        board->move(mousepos,platform_label->width()/2);//捕捉鼠标移动矩形类平台
        if(!board->is_stick)
        {
            ball->set_ball(QRectF(mousepos-ball->get_radius(),ball->get_top(),ball->get_radius()*2,ball->get_radius()*2));//捕捉鼠标的移动来移动小球判定框
        }else
        {
            ball->set_ball(QRectF(mousepos+delta,ball->get_top(),(ball->get_radius()-3)*2,(ball->get_radius()-3)*2));//捕捉鼠标的移动来移动小球判定框
        }

        collision();//碰撞函数，为了道具的正常掉落及拾取
        ball_label->move((int)ball->get_Pointx(),(int)ball->get_Pointy());//小球贴图随判定区移动
        if(item1!=nullptr)
        {
            if(!item1->is_hit)
            {
                item1->move();
                item_label->move(item1->get_left(),item1->get_top());
            }

        }

    });//鼠标释放事件之前小球和平台随鼠标移动
}

void playwindow::paintEvent(QPaintEvent *e)//绘制背景图片
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/background.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

void playwindow::createball()//小球初始化
{
    ball = new Ball(board->get_height(),0,board->get_top()-board->get_height());//球的直径是板的高度，球的位置也由板的位置确定
    ball_label = new QLabel(this);//球贴图的创建
    ball_label->setFixedSize(ball->get_radius()*2-3,ball->get_radius()*2-3);//根据矩形类小球的大小来设置label小球的大小
    ball_label->setStyleSheet("border-image: url(:/image/ball.png);");
}

void playwindow::createplatform()//平台初始化
{
    platform_label = new QLabel(this);
    platform_label->resize(130,20);//设定板长
    platform_label->setStyleSheet("border-image: url(:/image/platform.png);");
    platform_label->move(340,500);

    board = new Platform(340,500,platform_label->width(),platform_label->height());//根据label平台的大小设置矩形类平台的大小
}

void playwindow::createbrick()//砖块初始化
{
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(levelData[i][j]==0)
            {
                continue;
            }else
            {
                QLabel *tlabel = new QLabel(this);
                switch(levelData[i][j]){
                    case 1:
                        tlabel->setStyleSheet("border-image: url(:/image/bluebrick.png);");
                        break;
                    case 2:
                        tlabel->setStyleSheet("border-image: url(:/image/greenbrick.png);");
                        break;
                    case 3:
                        tlabel->setStyleSheet("border-image: url(:/image/orangebrick.png);");
                        break;
                }
                tlabel->setFixedSize(55,23);
                tlabel->move(120+62*j,90+30*i);
                bricks[i][j] = new Brick(120+62*j,90+30*i,tlabel->width(),tlabel->height(),tlabel);
            }
        }
    }
}

void playwindow::collision()//碰撞
{
    if(ball->get_bottom()<520)
    {
        if(ball->get_top()<=0)
        {
            ball->set_angel(180-ball->get_angel());
        }
        else if(ball->get_left()<=0||ball->get_right()>=800)
        {
            ball->set_angel(-ball->get_angel());
        }
        else if(ball->get_bottom()>board->get_top()&&abs(ball->get_ball_centralx()-mousepos)<=(board->get_width()/2)&&is_move)
        {
            if(!board->is_stick)
            {
                ball->set_angel(40*(ball->get_ball_centralx()-mousepos)/(board->get_width()/2));
                delta = ball->get_left()-mousepos;
            }else
            {
                ball->set_angel(40*(ball->get_ball_centralx()-mousepos)/(board->get_width()/2));
                delta = ball->get_left()-mousepos;
                Ball_Timer.stop();
                Platform_Timer.start(gameSpeed);
            }

        }
    }

    //*************************************
    //*******小球与砖块碰撞******************
    bool is_hit=false;//判定一次碰撞只能消灭一个小球
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(bricks[i][j]!=nullptr&&bricks[i][j]->get_health()>0&&ball->get_ball().intersects(bricks[i][j]->get_brick()))
            {
                is_hit = true;

                int RAND = rand()%1000+1;

                if((item1!=nullptr&&item1->is_hit)||(item1==nullptr))//随机掉落道具
                {

                    if(RAND>0&&RAND<=100)
                    {
                        QLabel *ilabel = new QLabel(this);
                        ilabel->setStyleSheet("border-image: url(:/image/item1.png);");
                        ilabel->setVisible(true);
                        ilabel->setFixedSize(21,27);
                        ilabel->move(bricks[i][j]->get_left(),bricks[i][j]->get_top());
                        item_label = ilabel;
                        item1 = new Item(1,bricks[i][j]->get_left(),bricks[i][j]->get_top(),ilabel->width(),ilabel->height());
                    }

                    if(RAND>100&&RAND<=200)
                    {
                        QLabel *ilabel = new QLabel(this);
                        ilabel->setStyleSheet("border-image: url(:/image/item2.png);");
                        ilabel->setVisible(true);
                        ilabel->setFixedSize(21,27);
                        ilabel->move(bricks[i][j]->get_left(),bricks[i][j]->get_top());
                        item_label = ilabel;
                        item1 = new Item(2,bricks[i][j]->get_left(),bricks[i][j]->get_top(),ilabel->width(),ilabel->height());
                    }
                    if(RAND>200&&RAND<=300)
                    {
                        QLabel *ilabel = new QLabel(this);
                        ilabel->setStyleSheet("border-image: url(:/image/item3.png);");
                        ilabel->setVisible(true);
                        ilabel->setFixedSize(21,27);
                        ilabel->move(bricks[i][j]->get_left(),bricks[i][j]->get_top());
                        item_label = ilabel;
                        item1 = new Item(3,bricks[i][j]->get_left(),bricks[i][j]->get_top(),ilabel->width(),ilabel->height());
                    }
                    if(RAND>300&&RAND<=400)
                    {
                        QLabel *ilabel = new QLabel(this);
                        ilabel->setStyleSheet("border-image: url(:/image/item4.png);");
                        ilabel->setVisible(true);
                        ilabel->setFixedSize(21,27);
                        ilabel->move(bricks[i][j]->get_left(),bricks[i][j]->get_top());
                        item_label = ilabel;
                        item1 = new Item(4,bricks[i][j]->get_left(),bricks[i][j]->get_top(),ilabel->width(),ilabel->height());
                    }
                    if(RAND>400&&RAND<=500)
                    {
                        QLabel *ilabel = new QLabel(this);
                        ilabel->setStyleSheet("border-image: url(:/image/item5.png);");
                        ilabel->setVisible(true);
                        ilabel->setFixedSize(21,27);
                        ilabel->move(bricks[i][j]->get_left(),bricks[i][j]->get_top());
                        item_label = ilabel;
                        item1 = new Item(5,bricks[i][j]->get_left(),bricks[i][j]->get_top(),ilabel->width(),ilabel->height());
                    }

                }

                bricks[i][j]->set_health(bricks[i][j]->get_health()-1);
                bricks[i][j]->get_label()->setVisible(false);
                if(ball->get_left()<bricks[i][j]->get_right()&&ball->get_right()>bricks[i][j]->get_left()&&ball->get_top()>bricks[i][j]->get_top())
                {
                    ball->set_angel(180-ball->get_angel());
                    //qDebug()<<"打中下边";
                }
                else if(ball->get_left()<bricks[i][j]->get_right()&&ball->get_right()>bricks[i][j]->get_left()&&ball->get_bottom()<bricks[i][j]->get_bottom())
                {
                    ball->set_angel(180-ball->get_angel());
                    //qDebug()<<"打中上边";
                }
                else if(ball->get_bottom()>bricks[i][j]->get_top()&&ball->get_top()<bricks[i][j]->get_bottom()&&ball->get_right()>bricks[i][j]->get_left())
                {
                    ball->set_angel(-ball->get_angel());
                    //qDebug()<<"打中右边";
                }
                else if(ball->get_bottom()>bricks[i][j]->get_top()&&ball->get_top()<bricks[i][j]->get_bottom()&&ball->get_left()<bricks[i][j]->get_right())
                {
                    ball->set_angel(-ball->get_angel());
                    //qDebug()<<"打中左边";
                }
            }
            if(is_hit)
                break;
        }
        if(is_hit)
            break;
    }
    //****************************************
    //************道具生效*********************
    if(item1!=nullptr&&!item1->is_hit)
    {
        if(item1->get_bottom()>board->get_top()&&item1->get_right()>board->get_left()&&item1->get_left()<board->get_right())
        {
            qDebug() << "hit";
            switch(item1->get_id())
            {
                case 1:
                    platform_label->resize(200,20);
                    board->set_width(200);
                    QTimer::singleShot(10000,this,[=](){
                        platform_label->resize(130,20);
                        board->set_width(130);
                    });
                    break;
                 case 2:
                    platform_label->resize(60,20);
                    board->set_width(60);
                    QTimer::singleShot(10000,this,[=](){
                        platform_label->resize(130,20);
                        board->set_width(130);
                    });
                    break;
                 case 3:
                    ball->set_speed(16);
                    QTimer::singleShot(10000,this,[=](){
                        ball->set_speed(10);
                    });
                    break;
                 case 4:
                    ball->set_speed(5);
                    QTimer::singleShot(10000,this,[=](){
                        ball->set_speed(10);
                    });
                    break;
                 case 5:
                    platform_label->setStyleSheet("border-image: url(:/image/stickplatform.png);");
                    board->is_stick = true;
                    QTimer::singleShot(10000,this,[=](){
                        platform_label->setStyleSheet("border-image: url(:/image/platform.png);");
                        board->is_stick = false;
                        Platform_Timer.stop();
                        Ball_Timer.start(gameSpeed);
                    });
                    break;
            }
            item_label->move(10000,10000);
            item_label->setVisible(false);
            item1->is_hit = true;
        }
        if(item1->get_bottom()>550)
        {
            qDebug()<<"miss";
            item_label->move(0,0);
            item_label->setVisible(false);
            item1->is_hit = true;
        }
    }

}

void playwindow::mouseMoveEvent(QMouseEvent *event)//捕捉鼠标位置
{

    mousepos = event->x();

}

void playwindow::mouseReleaseEvent(QMouseEvent *event)//鼠标释放事件
{
     ball->set_speed(10);//*******************************一开始为10，如果想要加速可改成16,减速改为5
     Platform_Timer.stop();
     is_move = true;
     Ball_Timer.start(gameSpeed);
}

playwindow::~playwindow()
{
    delete ball;
    delete board;
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<9;j++)
        {
            delete bricks[i][j];
            bricks[i][j] = nullptr;
        }
    }
}
