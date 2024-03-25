#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "bullet.h"
#include "enemy.h"

Player::Player() {
    setPixmap(QPixmap(":/images/img/ship.png").scaled(100, 100));
    setTransformOriginPoint(50, 50);
    bulletSound =  new QMediaPlayer;
    audioOutput =  new QAudioOutput;
    bulletSound->setAudioOutput(audioOutput);
    bulletSound->setSource(QUrl::fromEncoded("qrc:/sound/sound/bullet.mp3"));
    audioOutput->setVolume(25);
}


void Player::keyPressEvent(QKeyEvent *event)
{
        // *******  Event Handling for the Player ********
    int offset = 10;
    int rotAngle = 8;
    if(event->key()== Qt::Key_Left) {
        // to prevent the player from getting out of the screen
        if(x()>0) {
            setPos(x()-offset,y());
            setRotation(-rotAngle);
        }
    } else if(event->key()== Qt::Key_Right) {
        // to prevent the player from getting out of the screen
        if(x() + 100 < 800) {
            setPos(x()+offset,y());
            setRotation(rotAngle);
        }
    } else if(event->key()== Qt::Key_Space) {
        bulletSound->stop();
        Bullet * bullet = new Bullet();
        Bullet * bullet2 = new Bullet();

        bulletSound->play();
        bullet->setPos(x(),y());
        bullet2->setPos(x()+60,y());
        scene()->addItem(bullet);
        scene()->addItem(bullet2);
    }
}

void Player::keyReleaseEvent(QKeyEvent* event) {
    if(event->key())
        setRotation(0);
}

 // CreateEnemy function used to create the eneimes
void Player::createEnemy() {
  Enemy* enemy = new Enemy();
  scene()->addItem(enemy);
}
