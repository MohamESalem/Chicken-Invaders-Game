#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "bullet.h"
#include "enemy.h"

Player::Player() {
    setPixmap(QPixmap(":/images/img/ship.png").scaled(100, 100));
}

void Player::keyPressEvent(QKeyEvent *event)
{
        // *******  Event Handling for the Player ********
    int offset = 10;
    if(event->key()== Qt::Key_Left) {
        if(x()>0) // to prevent the player from getting out of the screen
            setPos(x()-offset,y());
    } else if(event->key()== Qt::Key_Right) {
        if(x() + 100 < 800) // to prevent the player from getting out of the screen
            setPos(x()+offset,y());
    } else if(event->key()== Qt::Key_Space) {
        Bullet * bullet = new Bullet();
        Bullet * bullet2 = new Bullet();

        bullet->setPos(x(),y());
        bullet2->setPos(x()+60,y());
        scene()->addItem(bullet);
        scene()->addItem(bullet2);

    }
}
 // CreateEnemy function used to create the eneimes
void Player::createEnemy() {
  Enemy* enemy = new Enemy();
  scene()->addItem(enemy);
}
