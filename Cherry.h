#ifndef CHERRY_H
#define CHERRY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Cherry: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Cherry(QGraphicsItem * parent=0);
    bool hit;
    void check();

public slots:
    void move();
    void delete_cherry();

private:
    QMediaPlayer * cherrysound;
};

#endif // CHERRY_H
