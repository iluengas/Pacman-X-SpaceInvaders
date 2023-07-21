#include "GhostBullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Game.h"
#include "Pacman.h"
#include "Health.h"

extern Game * game; // there is an external global object called game

GhostBullet::GhostBullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // drew the bullet (a rectangle)
    //setRect(0,0,10,50);
    QPixmap p(":/GameObjects/Bullets/ghostbullet.png");
    setPixmap(p.scaled(20, 20, Qt::KeepAspectRatio));
    // make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    /*bullet size incrementer*/
    size = 20;

    // start the timer
    timer->start(50);
}

void GhostBullet::move(){
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Pacman)){

            game->health->decrease();

            // remove them from the scene (still on the heap)
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }

    }

    // if there was no collision with Pacman, move the bullet downward



    if (pos().y() > 300)
    {
        if (position > 500)
        {
            if (pos().x() == game->pacman->pos().x())
            {
                setPos(x(),y()+25);
            }
            else
            {
                setPos(x() -10,y()+3);
            }
        }
        else if (position < 300)
        {
            if (pos().x() == game->pacman->pos().x())
            {
                setPos(x(),y()+25);
            }
            else
            {
                setPos(x() + 10,y()+3);
            }

        }
        else if (position <= 500 && position >= 300)
        {
            if (pos().x() == game->pacman->pos().x())
            {
                setPos(x(),y()+25);
            }
            else
            {
                setPos(x(),y() + 10);
            }
        }
    }
    else
    {
        setPos(x(),y() + 10);
    }


    /*ghostbullet slowly grows bigger*/
    size = size + 0.5;
    QPixmap p(":/GameObjects/Bullets/ghostbullet.png");
    setPixmap(p.scaled(size, size, Qt::KeepAspectRatio));


    // if the bullet is off the screen, destroy it
    if (pos().y() > 600){
        scene()->removeItem(this);
        delete this;
    }
}
