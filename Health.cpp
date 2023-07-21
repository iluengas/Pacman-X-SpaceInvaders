#include "Health.h"
#include <QFont>
#include <QApplication>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    health = 3;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",24));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
    if(health == 0)
        emit dead();
}

int Health::getHealth(){
    return health;
}

void Health::increase()
{
    health++;
    setPlainText(QString("Health: ") + QString::number(health));
}

