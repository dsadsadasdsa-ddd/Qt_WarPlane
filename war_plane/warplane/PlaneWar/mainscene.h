#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>
#include <map.h>
#include "heroplane.h"
#include <QMouseEvent>
#include "bullet.h"
#include "enemyplane.h"
#include "bomb.h"

class MainScene : public QWidget
{
    Q_OBJECT

    //成员函数
public:
    void initScene();//初始化场景

    //启动游戏  用于启动定时器对象
    void playGame();
    //更新坐标
    void updatePosition();
    //绘图事件
    void paintEvent(QPaintEvent *event);//  重写事件 函数写法不能改，是Qt自带的事件

    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);

    //敌机出场
    void enemyToScene();

    //碰撞检测
    void collisionDetection();



    //成员变量
public:
    QTimer m_Timer;//用于定时更新窗口的东西
    //地图对象
    Map m_map;

    //飞机对象
    HeroPlane m_hero;

    //测试子弹代码
    Bullet temp_bullet;


    //敌机数组
    EnemyPlane m_enemys[ENEMY_NUM];

    //敌机出场间隔记录
    int m_recorder;

    //爆炸数组
    Bomb m_bombs[BOMB_NUM];



public:
    MainScene(QWidget *parent = 0);
    ~MainScene();
};

#endif // MAINSCENE_H
