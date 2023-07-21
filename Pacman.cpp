#include "Pacman.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Bullet.h"
#include "RedGhost.h"
#include "Boss.h"
#include "ShooterGhost.h"
#include <QMediaPlayer>

Pacman::Pacman() : QGraphicsPixmapItem()
{
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/GameObjects/Sounds/shoot.mp3"));

    /* This sets pacman with the close png */
    setPixmap(QPixmap(":/GameObjects/Pacman/a1.png").scaled(50, 50, Qt::KeepAspectRatio));

    /* This sets pacman opening and closing png while moving UP */
    anim[Up].push_back(QPixmap(":/GameObjects/Pacman/a1.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Up].push_back(QPixmap(":/GameObjects/Pacman/b2.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Up].push_back(QPixmap(":/GameObjects/Pacman/b3.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Up].push_back(QPixmap(":/GameObjects/Pacman/b4.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Up].push_back(QPixmap(":/GameObjects/Pacman/b5.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Up].push_back(QPixmap(":/GameObjects/Pacman/b6.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Up].push_back(QPixmap(":/GameObjects/Pacman/b5.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Up].push_back(QPixmap(":/GameObjects/Pacman/b4.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Up].push_back(QPixmap(":/GameObjects/Pacman/b3.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Up].push_back(QPixmap(":/GameObjects/Pacman/b2.png").scaled(50, 50, Qt::KeepAspectRatio));


    /* This changes the png so that pacman is animated moving DOWN */
    anim[Down].push_back(QPixmap(":/GameObjects/Pacman/a1.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Down].push_back(QPixmap(":/GameObjects/Pacman/d2.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Down].push_back(QPixmap(":/GameObjects/Pacman/d3.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Down].push_back(QPixmap(":/GameObjects/Pacman/d4.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Down].push_back(QPixmap(":/GameObjects/Pacman/d5.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Down].push_back(QPixmap(":/GameObjects/Pacman/d6.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Down].push_back(QPixmap(":/GameObjects/Pacman/d5.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Down].push_back(QPixmap(":/GameObjects/Pacman/d4.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Down].push_back(QPixmap(":/GameObjects/Pacman/d3.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Down].push_back(QPixmap(":/GameObjects/Pacman/d2.png").scaled(50, 50, Qt::KeepAspectRatio));

    /* This changes the png so that pacman is animated moving RIGHT */
    anim[Right].push_back(QPixmap(":/GameObjects/Pacman/a1.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Right].push_back(QPixmap(":/GameObjects/Pacman/a2.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Right].push_back(QPixmap(":/GameObjects/Pacman/a3.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Right].push_back(QPixmap(":/GameObjects/Pacman/a4.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Right].push_back(QPixmap(":/GameObjects/Pacman/a5.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Right].push_back(QPixmap(":/GameObjects/Pacman/a6.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Right].push_back(QPixmap(":/GameObjects/Pacman/a5.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Right].push_back(QPixmap(":/GameObjects/Pacman/a4.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Right].push_back(QPixmap(":/GameObjects/Pacman/a3.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Right].push_back(QPixmap(":/GameObjects/Pacman/a2.png").scaled(50, 50, Qt::KeepAspectRatio));

    /* This changes the png so that pacman is animated moving LEFT */
    anim[Left].push_back(QPixmap(":/GameObjects/Pacman/a1.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Left].push_back(QPixmap(":/GameObjects/Pacman/c2.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Left].push_back(QPixmap(":/GameObjects/Pacman/c3.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Left].push_back(QPixmap(":/GameObjects/Pacman/c4.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Left].push_back(QPixmap(":/GameObjects/Pacman/c5.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Left].push_back(QPixmap(":/GameObjects/Pacman/c6.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Left].push_back(QPixmap(":/GameObjects/Pacman/c5.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Left].push_back(QPixmap(":/GameObjects/Pacman/c4.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Left].push_back(QPixmap(":/GameObjects/Pacman/c3.png").scaled(50, 50, Qt::KeepAspectRatio));
    anim[Left].push_back(QPixmap(":/GameObjects/Pacman/c2.png").scaled(50, 50, Qt::KeepAspectRatio));
}



/* this block of code changes the animation of pacman as he is moving */
void Pacman::moveup()
{
    anim_index++;
    if (anim_index == anim[Up].size()) {
        anim_index = 0;
    }
    setPixmap(anim[Up][anim_index]);
    setY(static_cast<int>(y()) - 1);
}

void Pacman::movedown()
{
    anim_index++;
    if (anim_index == anim[Down].size()) {
        anim_index = 0;
    }
    setPixmap(anim[Down][anim_index]);
    setY(static_cast<int>(y()) + 1);
}

void Pacman::moveright()
{
    anim_index++;
    if (anim_index == anim[Right].size()) {
        anim_index = 0;
    }
    setPixmap(anim[Right][anim_index]);
    setX(static_cast<int>(x()) + 1);
}

void Pacman::spawnRedGhost()
{
    /*create an enemy*/
    RedGhost *ghost = new RedGhost();
    scene()->addItem(ghost);


}

void Pacman::spawnBoss()
{
    Boss *boss = new Boss();
    scene()->addItem(boss);
}

void Pacman::spawnShooter()
{
    ShooterGhost *shooterghost = new ShooterGhost();
    scene()->addItem(shooterghost);
}

void Pacman::spawnCherry()
{
    Cherry *cherry = new Cherry();
    scene()->addItem(cherry);
}

void Pacman::moveleft()
{
    anim_index++;
    if (anim_index == anim[Left].size()) {
        anim_index = 0;
    }
    setPixmap(anim[Left][anim_index]);
    setX(static_cast<int>(x()) - 1);
}
/* this block of code changes the animation of pacman as he is moving */



/* checks to see if a key has been pressed */
void Pacman::keyPressEvent(QKeyEvent *event)
{

    switch(event->key())
    {
    case Qt::Key_W:
            if (pos().y() > 200)
            {
                setPos(x(), y() - 10);
//                qDebug() << "pacman move up";
                //change png to slowly move up
                moveup();
                break;
            }
            else
            {
                break;
            }

    case Qt::Key_A:

            if (pos().x() - 20 > 0)
            {
                setPos(x() - 30, y());
//                qDebug() << "pacman moved left";
                //change animation to move left
                moveleft();
                break;
            }
            else
            {
                break;
            }

    case Qt::Key_S:
            if (pos().y() + 40 < 600)
            {
                setPos(x(), y() + 10);
//                qDebug() << "pacman moved down";
                //change animation to moving down
                movedown();
                break;
            }
            else
            {
                break;
            }

    case Qt::Key_D:
        if (pos().x() + 50 < 800)
        {
            setPos(x() + 30, y());
//            qDebug() << "pacman moved right";
            //change animation to move right
            moveright();
            break;
        }
        else
        {
            break;
        }

    case Qt::Key_Space:

        Bullet *bullet = new Bullet();
        bullet->setPos(x() + 20, y());
        scene()->addItem(bullet);

        //play bullet sound
        if (bulletsound->state() == QMediaPlayer::PlayingState) {
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState) {
            bulletsound->play();
        }

//        qDebug() << "bullet shot";
        break;
    }
}
