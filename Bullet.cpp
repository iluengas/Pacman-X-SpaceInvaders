#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "RedGhost.h"
#include "Game.h"
#include "Boss.h"
#include "ShooterGhost.h"
#include "Cherry.h"

extern Game * game; // there is an external global object called game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // drew the bullet (a rectangle)
    //setRect(0,0,10,50);
    QPixmap p(":/GameObjects/Bullets/bullet.png");
    setPixmap(p.scaled(20, 20, Qt::KeepAspectRatio));
    // make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Bullet::move(){
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(RedGhost)){
            // increase the score
            game->score->increase();

            ghost = (RedGhost*) colliding_items[i];
            ghost->hit = true;
            ghost->check();

            // remove them from the scene (still on the heap)
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }

        else if (typeid(*(colliding_items[i])) == typeid(Boss)){
            // increase the score by 2 since this is the boss
            game->score->increase();
            game->score->increase();

            boss = (Boss*) colliding_items[i];
            boss->hit = true;
            boss->check();

            // remove them from the scene (still on the heap)
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }

        else if (typeid(*(colliding_items[i])) == typeid(ShooterGhost)){
            // increase the score by 2 since this is the boss
            game->score->increase();
            game->score->increase();

            shootghost = (ShooterGhost*) colliding_items[i];
            shootghost->hit = true;
            shootghost->check();

            // remove them from the scene (still on the heap)
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }

        else if (typeid(*(colliding_items[i])) == typeid(Cherry)){
            // increase the score by 2 since this is the boss
            game->score->increase();

            cherry = (Cherry*) colliding_items[i];
            cherry->hit = true;
            cherry->check();

            // remove them from the scene (still on the heap)
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }

    }

    // if there was no collision with an Enemy, move the bullet forward
    setPos(x(),y()-25);
    // if the bullet is off the screen, destroy it
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
