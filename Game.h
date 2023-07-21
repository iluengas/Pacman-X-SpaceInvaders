#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QObject>

#include "Score.h"
#include "Health.h"
#include "Pacman.h"

class Game: public QGraphicsView{

    Q_OBJECT

public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Score * score;
    Health * health;
    Pacman *pacman;
    QGraphicsPixmapItem *item;

    void call_start();

public slots:
    void start();
    void end();
};


#endif // GAME_H
