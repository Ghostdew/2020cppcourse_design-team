#include "chooselevelwindow.h"
#include "ui_chooselevelwindow.h"
#include <QTimer>
#include <QLabel>
#include <QDebug>

ChooseLevelWindow::ChooseLevelWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChooseLevelWindow)
{
    ui->setupUi(this);
    setFixedSize(800,550);
    setWindowIcon(QIcon(":/image/windowicon.jpg"));
    setWindowTitle("打砖块");

    connect(ui->BackButton,&QToolButton::pressed,this,[=](){
        ui->BackButton->setStyleSheet("border-image: url(:/image/BackButtonSelected.png);");
    });//退出按钮按下效果实现

    connect(ui->BackButton,&QToolButton::released,this,[=](){
        ui->BackButton->setStyleSheet("border-image: url(:/image/BackButton.png);");
        QTimer::singleShot(300,this,[=](){
            this->hide();
            emit ChooseLevelWindowBack();
        });
    });//退出按钮按下效果实现



    for(int i=0;i<9;i++)// 创建选择关卡按钮
    {
        QToolButton *btn = new QToolButton;
        btn->setParent(this);
        btn->setStyleSheet("border-image: url(:/image/levelbutton.png);");
        btn->move(260+i%3*100,150+i/3*100);
        btn->setFixedSize(71,71);

        connect(btn,&QToolButton::pressed,this,[=](){
            btn->setStyleSheet("border-image: url(:/image/levelbutton2.png);");
        });//选关按钮按下效果实现

        connect(btn,&QToolButton::released,this,[=](){
            btn->setStyleSheet("border-image: url(:/image/levelbutton.png);");
            qDebug() << "进入第"+QString::number(i+1)+"关";
            play = new playwindow(i+1);
            connect(play,&playwindow::playwindowBack,this,[=](){
                delete play;
                play = nullptr;
                this->show();
            });//监听游戏窗口返回信号
            QTimer::singleShot(300,this,[=](){
                this->hide();
                play->show();
            });
        });//进入指定关卡

        QLabel *label = new QLabel;
        label->setParent(this);
        label->setText(QString::number(i+1));
        label->setFixedSize(71,71);
        label->move(260+i%3*100,150+i/3*100);
        label->setAlignment(Qt::AlignCenter);
        QFont font("Yu Gothic UI Semibold",50,75);
        label->setFont(font);
        label->setAttribute(Qt::WA_TransparentForMouseEvents);//让label不挡住对toolbutton的点击
    }
}

ChooseLevelWindow::~ChooseLevelWindow()
{
    delete ui;
}
