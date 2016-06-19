#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,957,525);
    scene->addPixmap(QPixmap(":/image/back.png"));
    ui->graphicsView->setScene(scene);
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());
    // Create ground (You can edit here)
    itemList.push_back(new Land(16,1.5,32,3,QPixmap(":/ground.png").scaled(width(),height()/6.0),world,scene));
    global::count++;
   // itemList.push_back(new Land(16,1.5,32,3,QPixmap(":/ground.png").scaled(width(),height()/6.0),world,scene));
    // Create bird (You can edit here)
  //  Bird *birdie = new Bird(3.0f,3.0f,0.40f,&timer,QPixmap(":/image/head.png").scaled(height()/9.0,height()/9.0),world,scene);
    // Setting the Velocity
    shit = new Bird(25.0f,3.5f,0.40f,&timer,QPixmap(":/image/shit.png").scaled(height()/9.0,height()/9.0),world,scene);
  //  birdie->setLinearVelocity(b2Vec2(5,15));
 //   connect(timer, SIGNAL(timeout()), birdie,SLOT(paint()));
    wood = new barrier(12.0f,6.5f,1.7f,3.0f,&timer,QPixmap(":/image/wood.png").scaled(height()/9.0,height()/3.0),world,scene);


    restart->setIconSize(QSize(200,100));
    restart->setFixedSize(200,100);
    restart->setGeometry(755,0,200,100);
    scene->addWidget(restart);
    end->setIconSize(QSize(200,100));
    end->setFixedSize(200,100);
    end->setGeometry(755,100,200,100);
    scene->addWidget(end);
    music->setMedia(QUrl("qrc:/John_Cena-WWE_-_The_Time_Is_Now_John_Cena_Theme_Song_AE_Arena_Effect_mp4.mp3"));
    music->play();
    // Timer
    connect(end,QPushButton::clicked,this,QWidget::close);
    connect(restart,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);
    connect(&timer,SIGNAL(timeout()),this,SLOT(check()));
    connect(&timer1,SIGNAL(timeout()),this,SLOT(born()));
}
int bird1=0;
int bird2=0;
int bird3=0;
int bird4=0;
int bird2a=0;
int bird3a=0;
int bird4a=0;
int shi=1;
int temp=0;
bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
    QPoint pt = mouseEvent->pos();
    int Vx;
    int Vy;
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress)
    {
        global::flag=true;
        mouseEvent = static_cast<QMouseEvent*>(event);
        global::y = pt.y();
        global::x = pt.x();

        /* TODO : add your code here */
        //std::cout << "Press !" << std::endl ;
    }
    if(event->type() == QEvent::MouseMove)
    {
        /* TODO : add your code here */

        //std::cout << "Move !" << std::endl ;
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {

        if(global::flag && bird1==0){


            birdie1 = new Bird(3.0f,5.0f,0.40f,&timer,QPixmap(":/image/head.png").scaled(height()/9.0,height()/9.0),world,scene);
            Vx = 132-global::x;
            Vy = global::y-430;

            Vx=Vx/5;
            Vy=Vy/5;

            birdie1->setLinearVelocity(b2Vec2(Vx,Vy));
            itemList.push_back(birdie1);
            global::count++;
            global::flag=false;
            global::Flag1=1;
            bird1=1;
        }
        if(global::flag && bird1==1 && bird2==0){
            birdie2 = new Bird(3.0f,5.0f,0.40f,&timer,QPixmap(":/image/black.png").scaled(height()/9.0,height()/9.0),world,scene);
            Vx = 132-global::x;
            Vy = global::y-430;
            Vx=Vx/5;
            Vy=Vy/5;
            birdie2->setLinearVelocity(b2Vec2(Vx,Vy));
            global::flag=false;
            bird2=1;
            bird2a=1;
        }
        if(global::flag && bird1==1 && bird2==1 && bird2a==1){
            birdie2->setLinearVelocity(b2Vec2(0,-50));
            global::flag=false;
            bird2a=0;
        }

        if(global::flag && bird1==1 && bird2==1 && bird2a==0 && bird3==0){
            birdie3 = new Bird(3.0f,5.0f,0.40f,&timer,QPixmap(":/image/white.png").scaled(height()/9.0,height()/9.0),world,scene);
            Vx = 132-global::x;
            Vy = global::y-430;
            Vx=Vx/5;
            Vy=Vy/5;
            birdie3->setLinearVelocity(b2Vec2(Vx,Vy));
            global::flag=false;
            bird3=1;
            bird3a=1;
        }
        if(global::flag && bird1==1 && bird2==1 && bird2a==0 && bird3==1 &&bird3a==1){
            birdie3->setLinearVelocity(b2Vec2(50,0));
            global::flag=false;
            bird3a=0;
        }
        if(global::flag && bird1==1 && bird2==1 && bird3==1 && bird3a==0 && bird4==0){
            birdie4 = new Bird(3.0f,5.0f,0.40f,&timer,QPixmap(":/image/yellow.png").scaled(height()/9.0,height()/9.0),world,scene);
            Vx = 132-global::x;
            Vy = global::y-430;
            Vx=Vx/5;
            Vy=Vy/5;
            birdie4->setLinearVelocity(b2Vec2(Vx,Vy));
            global::flag=false;
            bird4=1;
            bird4a=1;
        }
        if(global::flag && bird1==1 && bird2==1 && bird2a==0 && bird3a==0 && bird3==1 && bird4==1 && bird4a==1){
            timer1.start(500);

            global::flag=false;
            bird4a=0;
        }
        /* TODO : add your code here */

    }
    return false;
}


void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event

    emit quitGame();
}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
}

void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
}
void MainWindow::close(){

    if(shi==1)
        delete shit;
    if(bird1==1){
        delete birdie1;
        bird1=0;
    }
    if(bird2==1){
        delete birdie2;
        bird2=0;
    }
    if(bird3==1){
        delete birdie3;
        bird3=0;
    }
    if(bird4==1){
        delete birdie4;
        bird4=0;
    }
    for(int i=temp;i>0;i--)
        delete egg[i-1];
    delete wood;
    build();

}
void MainWindow::build(){
    itemList.push_back(new Land(16,1.5,32,3,QPixmap(":/ground.png").scaled(width(),height()/6.0),world,scene));
    shit = new Bird(25.0f,3.0f,0.40f,&timer,QPixmap(":/image/shit.png").scaled(height()/9.0,height()/9.0),world,scene);
    shi=1;
    temp=0;

    wood = new barrier(12.0f,6.5f,1.7f,3.0f,&timer,QPixmap(":/image/wood.png").scaled(height()/9.0,height()/3.0),world,scene);
}

void MainWindow::check(){
    if(shi==1){
        if(shit->g_body->GetPosition().x>25.1 || shit->g_body->GetPosition().x<24.9){
            delete shit;
            shi=0;
        }
    }
}
void MainWindow::born(){
    egg[temp]= new Bird(birdie4->g_body->GetPosition().x,birdie4->g_body->GetPosition().y-1.0,0.40f,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene);
    temp++;
    if(temp>3)
        timer1.stop();
}
