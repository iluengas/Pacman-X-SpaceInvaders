#ifndef SHOOTERGHOST_H
#define SHOOTERGHOST_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class ShooterGhost: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    ShooterGhost(QGraphicsItem * parent=0);
    bool hit;
    void check();
    int health;
public slots:
    void move();
    void delete_ghost();
    void flashblue();
    void revert();
    void shoot();
private:
    QMediaPlayer * green_sound;
};

#endif // SHOOTERGHOST_H
