#ifndef BOSS_H
#define BOSS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Boss: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Boss(QGraphicsItem * parent=0);
    bool hit;
    void check();
    int health;
public slots:
    void move();
    void delete_ghost();
    void flashblue();
    void revert();
private:
    QMediaPlayer * boss_sound;
};

#endif // BOSS_H
