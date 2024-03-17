#include "game.h"

Game::Game() {
    setFixedSize(800, 600);

    // ******* Create the Scene ********
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0, 800, 600);

    // *******  Create the Player ********
    player = new Player();
    player->setRect(0, 0, 100, 100);
    scene->addItem(player);

    // *******  Setting the foucs to the Player ********
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // *******  Adjust the location of the Player (middle of the screen) ********
    int playerLength = 100;
    player->setPos(width()/2 - playerLength/2, height() - playerLength);

    // Add health
    health = new Health();
    health->setPos(0, 25);
    scene->addItem(health);

    // *******   Assign scene to the view   ***************
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // *******  Create the Enemies automatically ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),player,SLOT(createEnemy()));
    timer->start(2000);
}
