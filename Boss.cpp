#include "Boss.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"
#include <QMediaPlayer>

extern Game * game;

Boss::Boss(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    boss_sound = new QMediaPlayer();
    boss_sound->setMedia(QUrl("qrc:/GameObjects/Sounds/pacman_beatboss.mp3"));

    //set random x position
    int random_number = arc4random() % 700;
    setPos(random_number,0);

    hit = false;
    health = 10;

    QPixmap p(":/GameObjects/Ghost/rainbowghost.png");
    setPixmap(p.scaled(150, 150, Qt::KeepAspectRatio));

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Boss::check()
{
    if (hit == true)
    {
        health--;
        if (health == 0)
        {
            boss_sound->play();
            QPixmap p(":/GameObjects/Ghost/blue.png");
            setPixmap(p.scaled(150, 150, Qt::KeepAspectRatio));
            QTimer::singleShot(200, this, SLOT(delete_ghost()));
            return;
        }

         QTimer::singleShot(100, this, SLOT(flashblue()));
         QTimer::singleShot(200, this, SLOT(revert()));
    }
}

void Boss::move(){
    // move enemy down
    setPos(x(),y()+1);

    // destroy enemy when it goes out of the screen
    if (pos().y() > 600){
        //decrease the health

        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}

void Boss::delete_ghost()
{
    delete this;
}

void Boss::revert()
{
    QPixmap p(":/GameObjects/Ghost/rainbowghost.png");
    setPixmap(p.scaled(150, 150, Qt::KeepAspectRatio));
}

void Boss::flashblue()
{
    QPixmap p(":/GameObjects/Ghost/blue.png");
    setPixmap(p.scaled(150, 150, Qt::KeepAspectRatio));
}
