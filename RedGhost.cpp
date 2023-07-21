#include "RedGhost.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"
#include <QMediaPlayer>

extern Game * game;

RedGhost::RedGhost(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    redghostsound = new QMediaPlayer();
    redghostsound->setMedia(QUrl("qrc:/GameObjects/Sounds/pacman_eatghost.wav"));

    //set random x position
    int random_number = arc4random() % 700;
    setPos(random_number,0);

    hit = false;
    health = 3;

    QPixmap p(":/GameObjects/Ghost/red.png");
    setPixmap(p.scaled(75, 75, Qt::KeepAspectRatio));

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void RedGhost::check()
{
    if (hit == true)
    {
        health--;
        if (health == 0)
        {
            redghostsound->play();
            QPixmap p(":/GameObjects/Ghost/blue.png");
            setPixmap(p.scaled(75, 75, Qt::KeepAspectRatio));

            QTimer::singleShot(1000, this, SLOT(delete_ghost()));
            return;
        }

         QTimer::singleShot(100, this, SLOT(flashblue()));
         QTimer::singleShot(200, this, SLOT(revert()));
    }

}

void RedGhost::move(){
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

void RedGhost::moveback()
{
    setPos(pos().x(), pos().y() - 20);
}

void RedGhost::delete_ghost()
{
    delete this;
}

void RedGhost::flashblue()
{
    QPixmap p(":/GameObjects/Ghost/blue.png");
    setPixmap(p.scaled(75, 75, Qt::KeepAspectRatio));
}

void RedGhost::revert()
{
    QPixmap p(":/GameObjects/Ghost/red.png");
    setPixmap(p.scaled(75, 75, Qt::KeepAspectRatio));
}
