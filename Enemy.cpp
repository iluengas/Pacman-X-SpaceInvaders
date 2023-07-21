#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //set random x position
    int random_number = arc4random() % 700;
    setPos(random_number,0);

    hit = false;
    health = 3;

    QPixmap p("://PNGIcons/red.png");
    setPixmap(p.scaled(75, 75, Qt::KeepAspectRatio));

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Enemy::check()
{
    if (hit == true)
    {
        health--;
        if (health == 0)
        {
            QPixmap p("://PNGIcons/blueghost.png");
            setPixmap(p.scaled(75, 75, Qt::KeepAspectRatio));
            QTimer::singleShot(200, this, SLOT(delete_ghost()));
            return;
        }

         QTimer::singleShot(100, this, SLOT(flashblue()));
         QTimer::singleShot(200, this, SLOT(revert()));
    }

}

void Enemy::move(){
    // move enemy down
    setPos(x(),y()+2);

    // destroy enemy when it goes out of the screen
    if (pos().y() > 600){
        //decrease the health

        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}

void Enemy::delete_ghost()
{
    delete this;
}

void Enemy::flashblue()
{
    QPixmap p("://PNGIcons/blueghost.png");
    setPixmap(p.scaled(75, 75, Qt::KeepAspectRatio));
}

void Enemy::revert()
{
    QPixmap p("://PNGIcons/red.png");
    setPixmap(p.scaled(75, 75, Qt::KeepAspectRatio));
}
