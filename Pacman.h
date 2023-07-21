#ifndef PACMAN_H
#define PACMAN_H

#include <QGraphicsRectItem>//if you want to make a yellow square
#include <QKeyEvent>
#include <QGraphicsPixmapItem>// to use a png
#include <QObject>
#include <QMediaPlayer>

class Pacman : public QObject, public QGraphicsPixmapItem
{
    /*do not delete this MACRO*/
    Q_OBJECT
public:
    Pacman();
    void keyPressEvent(QKeyEvent *event);

    /* change the animation gradually by calling these functions */
    void moveup();
    void movedown();
    void moveleft();
    void moveright();
    /* change the animation gradually by calling these functions */

    /* this code chunk will change the animation of pacman */
    //vector that holds aniamtions
    QVector<QPixmap> anim[4];
    // index of current animation
    int anim_index = 0;
    //an enum to make it more readable what direction pacman is moving
    enum Dir {Up = 0, Down = 1, Left = 2, Right = 3, Stop = 4};
    /* this code chunk will change the animation of pacman */


public slots:
    void spawnRedGhost();
    void spawnBoss();
    void spawnShooter();
    void spawnCherry();

private:
    QMediaPlayer * bulletsound;
};

#endif // PACMAN_H
