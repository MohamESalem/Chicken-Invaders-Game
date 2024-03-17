#include "health.h"
#include "game.h"
#include <QFont>

extern Game* game;

Health::Health() {
    // initialize heatlth to 3
    health = 3;
    // draw the score
    setPlainText("Health: " + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));

}

void Health::decrease() {
    health--;
    setPlainText("Health: " + QString::number(health));
    if(!health) game->showGameOverMsg();
}

int Health::getHealthVal() {return health;}
