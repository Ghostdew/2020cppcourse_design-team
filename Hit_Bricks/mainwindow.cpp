#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRectF>
#include <QTimer>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(800,550);
    setWindowIcon(QIcon(":/image/windowicon.jpg"));
    setWindowTitle("打砖块");
    ui->helplabel->setVisible(false);
    ui->continueButton->setVisible(false);
    ChooseWindow = new ChooseLevelWindow;//实例化关卡选择场景
    connect(ui->StartButton,&QToolButton::pressed,this,[=](){
        ui->StartButton->setStyleSheet("border-image: url(:/image/startbutton2.png);");
    });//开始按钮按下效果实现

    connect(ui->StartButton,&QToolButton::released,this,[=](){
        ui->StartButton->setStyleSheet("border-image: url(:/image/startbutton.png);");//开始按钮按下效果实现
        QTimer::singleShot(300,this,[=](){
            ui->helplabel->setVisible(true);
            ui->continueButton->setVisible(true);
        });//延时进入窗口
    });

    connect(ui->continueButton,&QToolButton::pressed,this,[=](){
        ui->continueButton->setStyleSheet("border-image: url(:/image/continue2.png);");
    });//继续按钮按下效果实现

    connect(ui->continueButton,&QToolButton::released,this,[=](){
        ui->continueButton->setStyleSheet("border-image: url(:/image/continue.png);");//开始按钮按下效果实现
        QTimer::singleShot(300,this,[=](){
            ui->helplabel->setVisible(false);
            ui->continueButton->setVisible(false);
            this->close();
            ChooseWindow->show();
        });//延时进入窗口
    });

    connect(ui->ExitButton,&QToolButton::pressed,this,[=](){
        ui->ExitButton->setStyleSheet("border-image: url(:/image/exit2.png);");
    });//退出按钮按下效果实现

    connect(ui->ExitButton,&QToolButton::released,this,[=](){
        ui->ExitButton->setStyleSheet("border-image: url(:/image/exit.png);");
        close();
    });//退出按钮按下效果实现

    connect(ChooseWindow,&ChooseLevelWindow::ChooseLevelWindowBack,this,&MainWindow::show);//监听选择关卡场景的返回信号
}



MainWindow::~MainWindow()
{
    delete ui;
}
