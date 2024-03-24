#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>

class Bullet: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet();
public slots:
    void move();
private:
    QMediaPlayer * killSound;
    QAudioOutput * audioOutput;
};

#endif // BULLET_H
