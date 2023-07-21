#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=0);
    bool hit;
    void check();
    int health;
public slots:
    void move();
    void delete_ghost();
    void flashblue();
    void revert();
};

#endif // ENEMY_H
