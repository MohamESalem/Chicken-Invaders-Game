#include "game.h"
#include <QImage>
#include <QMessageBox>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QFont>

//external global variable to access the score
extern Game* game;

Game::Game() {
    setFixedSize(800, 600);
    setBackgroundBrush(QBrush(QImage(":/images/img/bg_img.jpg")));

    // ******* Create the Scene ********
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0, 800, 600);

    // *******  Create the Player ********
    player = new Player();
    scene->addItem(player);

    // *******  Setting the foucs to the Player ********
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // ************ Create the Score **************
    score = new Score();
    scene->addItem(score);

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

void Game::showGameOverMsg() {
    // get the score from Score class
    int score = game->score->getScore();

    // create a QMessageBox
    QMessageBox* msgBox = new QMessageBox();
    msgBox->setIcon(QMessageBox::Critical);
    msgBox->setWindowTitle("Game Over!");
    msgBox->setText("Your Score is " + QString::number(score));

    // Increase font size
    QFont font;
    font.setPointSize(12);
    msgBox->setFont(font);

    // hide the game and show the game over message
    hide();
    msgBox->exec();
}
