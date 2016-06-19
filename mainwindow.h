#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>
#include <QPushButton>
#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include <barrier.h>
#include <global.h>
#include <QMouseEvent>
#include <QMediaPlayer>
#include <QtMath>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
    void build();

signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    // For debug slot
    void QUITSLOT();
    void close();
    void check();
    void born();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QTimer timer;
    QTimer timer1;
    Bird *shit;
    barrier *wood;
    Bird *birdie1;
    Bird *birdie2;
    Bird *birdie3;
    Bird *birdie4;
    Bird *egg[4];
    QIcon *btn = new QIcon(QPixmap(":/image/restart.png"));
    QIcon *btn1 = new QIcon(QPixmap(":/image/end.png"));
    QPushButton *restart = new QPushButton(*btn,"");
    QPushButton *end = new QPushButton(*btn1,"");
    QMediaPlayer *music = new QMediaPlayer();
};

#endif // MAINWINDOW_H
