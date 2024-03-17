#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsScene>
#include "player.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game();
    Player* player;
    QGraphicsScene* scene;
};

#endif // GAME_H
