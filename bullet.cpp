#include"bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <enemy.h>
#include <player.h>
#include "Game.h"

extern Game * game; //external global variable

Bullet::Bullet() : QObject(), QGraphicsPixmapItem() {

    // set the bullet's image
    setPixmap(QPixmap(":/images/img/red_laser.png").scaled(35, 35));

    // *******  Generating the Bullets automatically ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
    killSound =  new QMediaPlayer;
    audioOutput =  new QAudioOutput;
    killSound->setAudioOutput(audioOutput);
    killSound->setSource(QUrl::fromEncoded("qrc:/sound/sound/chicken.mp3"));
    audioOutput->setVolume(25);

}

// Move function is used to 1-  move the bullet upwards
                         // 2- Handle the collision of the bullets with enemies
void Bullet:: move() {
    int offset = 10;
    // *******  Getting the colliding items with the Bullet ********
    QList<QGraphicsItem *> collided_items = collidingItems();
    foreach(auto& item, collided_items) {
        if(typeid(*item) == typeid(Enemy)) {

            // ***** increase score **********
            game->score->increase();
            // ****remove bullet from the scene*******
            scene()->removeItem(item);
            scene()->removeItem(this);
            killSound->play();
            delete item;
            delete this;
            return;
        }
    }

    // *******  Moving the bullets upward ********
    setPos(x(), y() - offset);
    if(y() + boundingRect().height() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
