#include"bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <enemy.h>
#include <player.h>

Bullet::Bullet() : QObject(), QGraphicsRectItem() {

    // *******  Setting the bullets' size ********
    setRect(0,0,10,50);
    // *******  Generating the Bullets automatically ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
}

// Move function is used to 1-  move the bullet upwards
                         // 2- Handle the collision of the bullets with enemies
void Bullet:: move() {
    int offset = 10;
    // *******  Getting the colliding items with the Bullet ********
    QList<QGraphicsItem *> collided_items = collidingItems();
    foreach(auto& item, collided_items) {
        if(typeid(*item) == typeid(Enemy)) {
            scene()->removeItem(item);
            scene()->removeItem(this);
            delete item;
            delete this;
            return;
        }
    }

    // *******  Moving the bullets upward ********
    setPos(x(), y() - offset);
    if(y() + rect().height() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
