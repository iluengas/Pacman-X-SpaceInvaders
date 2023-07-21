#ifndef REDGHOST_H
#define REDGHOST_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class RedGhost: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    RedGhost(QGraphicsItem * parent=0);
    bool hit;
    void check();
    int health;
public slots:
    void move();
    void moveback();
    void delete_ghost();
    void flashblue();
    void revert();
private:
    QMediaPlayer * redghostsound;
};

#endif // REDGHOST_H
