#include "enemy.h"
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> to generate really large integer
#include <QTimer>
#include <QDebug>
#include <QMessageBox>
#include <QGraphicsView>
#include "game.h"

extern Game* game;

Enemy::Enemy() {
    // *******  Setting the size of the enemy ********
    setPixmap(QPixmap(":/images/img/chicken.png").scaled(80, 80));

    // *******  Setting the postion of the enemy within the view dimensions ********
    int random_number = rand() % 701;
    setPos(random_number,0);

    // *******  Moving the enemies downwards automatically every 50 milli second ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}
// Function move: move the enemy downwards untill the end of the scene then remove it and delete it
void Enemy:: move() {
    // check if the enemy hits the player
    QList<QGraphicsItem *> collided_items = collidingItems();
    foreach(auto& item, collided_items) {
        if(typeid(*item) == typeid(Player)) {
            // game over
            game->showGameOverMsg();
            return;
        }
    }

    // move the enemy down
    setPos(x(),y()+5);
    if(y() > 600) {
        scene()->removeItem(this);
        delete this;
        game->health->decrease();
    }
}
