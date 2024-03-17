#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health : public QGraphicsTextItem {
public:
    Health();
    void decrease();
    int getHealthVal();
private:
    int health;
};

#endif // HEALTH_H
