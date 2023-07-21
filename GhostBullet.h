#ifndef GHOSTBULLET_H
#define GHOSTBULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include "Pacman.h"

class GhostBullet: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    GhostBullet(QGraphicsItem * parent=0);
    Pacman *pacman;
    float size;
    float position;

public slots:
    void move();
};

#endif // GHOSTBULLET_H
