#include "health.h"
#include <QFont>

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
}

int Health::getHealthVal() {return health;}
