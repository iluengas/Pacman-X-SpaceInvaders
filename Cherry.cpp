#include "Cherry.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"
#include <QMediaPlayer>

extern Game * game;

Cherry::Cherry(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    cherrysound = new QMediaPlayer();
    cherrysound->setMedia(QUrl("qrc:/GameObjects/Sounds/pacman_eatfruit.wav"));

    //set random x position
    int random_number = arc4random() % 700;
    setPos(random_number,0);

    hit = false;

    QPixmap p(":/GameObjects/Ghost/greenapple.png");
    setPixmap(p.scaled(75, 75, Qt::KeepAspectRatio));

    // make/connect a timer to move() the Cherry every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Cherry::check()
{
    if (hit == true)
    {
        cherrysound->play();
        QPixmap p(":/GameObjects/Ghost/heart.png");
        setPixmap(p.scaled(75, 75, Qt::KeepAspectRatio));
        game->health->increase();
    }
    QTimer::singleShot(200, this, SLOT(delete_cherry()));
}

void Cherry::move(){
    // move Cherry down
    setPos(x(),y() + 5);

    // destroy Cherry when it goes out of the screen
    if (pos().y() > 600){

        scene()->removeItem(this);
        delete this;
    }
}

void Cherry::delete_cherry()
{
    delete this;
}
