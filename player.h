#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
public:
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
public slots:
    void createEnemy();
private:
    QMediaPlayer * bulletSound;
    QAudioOutput * audioOutput;

};

#endif // PLAYER_H
