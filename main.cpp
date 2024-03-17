#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include <QTimer>
#include <QDebug>
#include <QBrush>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // *******  Create the View ********
    QGraphicsView* view = new QGraphicsView();
    view->setFixedSize(800, 600);

    // ******* Create the Scene ********
    QGraphicsScene* scene = new QGraphicsScene();
    scene->setSceneRect(0,0, 800, 600);

    // *******  Create the Player ********
    Player * rect = new Player();
    rect->setRect(0, 0, 100, 100);
    scene->addItem(rect);
    rect->setBrush(Qt::yellow);


    // *******  Setting the foucs to the Player ********
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();


    // *******  Adjust the location of the Player (middle of the screen) ********
    int playerWidth = 100, playerHeight = 100;
    rect->setPos(view->width()/2 - playerWidth/2, view->height() - playerHeight);

    // *******   Assign scene to the view   ***************
    view->setScene(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // *******  Create the Enemies automatically ********
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),rect,SLOT(createEnemy()));
    time->start(2000);

    view->show();

    return a.exec();
}
