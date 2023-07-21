#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "RedGhost.h"
#include <QPushButton>
#include <QMediaPlayer>
#include <QApplication>
#include "Health.h"

/* References:
 * Abdullah on Youtube - C++ Qt Game Tutorial:
 * - Tutorials 1-8
 * blueskyson on Github:
 * - PacMan pngs
 * - Ghost pngs
 * - Animating PacMan
 */

Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

   // connect(health, SIGNAL(dead()), this, SLOT(end()) );
    call_start();
    show();
}

void Game::call_start()
{
    //play intro music first

    QMediaPlayer *intro = new QMediaPlayer();
    intro->setMedia(QUrl("qrc:/GameObjects/Sounds/pacman_beginning.wav"));
    intro->play();

    //set title
    QPixmap p(":/GameObjects/Ghost/pac.png");
    item = new QGraphicsPixmapItem();
    item->setPixmap(p.scaled(600, 500, Qt::KeepAspectRatio));
    scene->addItem(item);
    item->setPos(100, 100);
    setBackgroundBrush(Qt::black);

    // spawn Entities

    QTimer::singleShot(3000, this, SLOT(start()));

}

void Game::start()
{
    scene->removeItem(item);
    delete item;


    // create the player
    pacman = new Pacman();
   // pacman->setRect(0,0,100,100); // change the rect from 0x0 (default) to 100x100 pixels
    pacman->setPos(400,500); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    pacman->setFlag(QGraphicsItem::ItemIsFocusable);
    pacman->setFocus();
    // add the player to the scene
    scene->addItem(pacman);

    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    setBackgroundBrush(Qt::black);


    QTimer * redTimer = new QTimer();
    QTimer * bossTimer = new QTimer();
    QTimer * shooterTimer = new QTimer();
    QTimer * cherryTimer = new QTimer();

    QObject::connect(redTimer,SIGNAL(timeout()),pacman,SLOT(spawnRedGhost()));
    QObject::connect(bossTimer,SIGNAL(timeout()),pacman,SLOT(spawnBoss()));
    QObject::connect(shooterTimer,SIGNAL(timeout()),pacman,SLOT(spawnShooter()));
    QObject::connect(cherryTimer,SIGNAL(timeout()),pacman,SLOT(spawnCherry()));

    redTimer->start(3000);//3,000
    bossTimer->start(20000);//20,000
    shooterTimer->start(5000); //5,000
    cherryTimer->start(40000); //40,000

    connect(health, SIGNAL(dead()), this, SLOT(end()) );

}

void Game::end()
{
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    show();
    QPixmap p(":/GameObjects/Ghost/gameover.jpg");
    item = new QGraphicsPixmapItem();
    item->setPixmap(p.scaled(600, 500, Qt::KeepAspectRatio));
    scene->addItem(item);
    item->setPos(100, 100);
    setBackgroundBrush(Qt::black);
    scene->addItem(score);

    QMediaPlayer * ending = new QMediaPlayer();
    ending->setMedia(QUrl("qrc:/GameObjects/Sounds/pacman_death.wav"));
    ending->play();

    //QApplication::quit();

}
