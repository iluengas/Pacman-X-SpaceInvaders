#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include "RedGhost.h"
#include "Boss.h"
#include "ShooterGhost.h"
#include "Cherry.h"

class Bullet: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent=0);
    RedGhost *ghost;
    Boss *boss;
    ShooterGhost *shootghost;
    Cherry *cherry;
public slots:
    void move();
};

#endif // BULLET_H
