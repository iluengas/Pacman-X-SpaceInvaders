#include "ShooterGhost.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"
#include "GhostBullet.h"
#include <QMediaPlayer>

extern Game * game;

ShooterGhost::ShooterGhost(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    green_sound = new QMediaPlayer();
    green_sound->setMedia(QUrl("qrc:/GameObjects/Sounds/pacman_eatgreen.mp3"));

    //set random x position
    int random_number = arc4random() % 700;
    setPos(random_number,0);

    hit = false;
    health = 3;

    QPixmap p(":/GameObjects/Ghost/green.png");
    setPixmap(p.scaled(75, 75, Qt::KeepAspectRatio));

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);

    QTimer::singleShot(2000, this, SLOT(shoot()));


}

void ShooterGhost::check()
{
    if (hit == true)
    {
        health--;
        if (health == 0)
        {
            green_sound->play();
            QPixmap p(":/GameObjects/Ghost/blue.png");
            setPixmap(p.scaled(75, 75, Qt::KeepAspectRatio));
            QTimer::singleShot(200, this, SLOT(delete_ghost()));
            return;
        }

         QTimer::singleShot(100, this, SLOT(flashblue()));
         QTimer::singleShot(200, this, SLOT(revert()));
    }

}

void ShooterGhost::move(){
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

void ShooterGhost::delete_ghost()
{
    delete this;
}

void ShooterGhost::flashblue()
{
    QPixmap p(":/GameObjects/Ghost/blue.png");
    setPixmap(p.scaled(75, 75, Qt::KeepAspectRatio));
}

void ShooterGhost::revert()
{
    QPixmap p(":/GameObjects/Ghost/green.png");
    setPixmap(p.scaled(75, 75, Qt::KeepAspectRatio));
}

void ShooterGhost::shoot()
{
    GhostBullet *ghostBullet = new GhostBullet();
    ghostBullet->setPos(x() + 20, y());
    ghostBullet->position = pos().x();

    scene()->addItem(ghostBullet);
//    qDebug() << "ghostBullet shot";
}
