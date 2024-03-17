#include <QApplication>
#include "game.h"

Game* game;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // create a game object
    game = new Game();

    // show the game's view
    game->show();

    return a.exec();
}
