#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QTimer>
#include <QGraphicsScene>
#include "player.h"
#include "health.h"
#include "Score.h"


class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game();
    QGraphicsScene* scene;
    Player* player;
    Health* health;
    Score* score;
    // methods
    void showGameOverMsg();
};

#endif // GAME_H
