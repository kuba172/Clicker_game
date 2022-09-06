#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QFrame>
#include <QMouseEvent>
#include <QTimer>
#include <QFile>
#include <QString>

class Game : public QWidget
{
    Q_OBJECT
public:
    Game(int h, int w);
    Game(int h, int w,long long p, long long ppc, long long pps, long long c1, long long c2);

private:
    int height;
    int width;
    long long points = 0;
    long long points_per_second = 0;
    long long points_per_click = 1;
    long long cost_u1 = 100;
    long long cost_u2 = 200;

    QTimer *timer = new QTimer(this);
    QLabel *label_nr_points = new QLabel("Number of points: " + QString::number(points),this);
    QLabel *label_nr_points_per_sec = new QLabel("Number of points per second: " + QString::number(points_per_second),this);
    QFrame *frame = new QFrame(this);
    QLabel *label_tap_here = new QLabel("Tap here",frame);
    QLabel *label_upgrade_1 = new QLabel("Cost: "+QString::number(cost_u1),this);
    QPushButton *upgrade_1_button = new QPushButton("+1 per click",this);
    QLabel *label_upgrade_2 = new QLabel("Cost: "+QString::number(cost_u2),this);
    QPushButton *upgrade_2_button = new QPushButton("+1 per second",this);
    QPushButton *reset_button = new QPushButton("Reset",this);
    QPushButton *exit_button = new QPushButton("Exit",this);

public:
    void press_exit_button();
    void time();
    void mousePressEvent(QMouseEvent *event);
    void press_upgrade_1_button();
    void press_upgrade_2_button();
    void press_reset_button();

public slots:
    void go_to_menu();
    void buy_upgrade_1();
    void buy_upgrade_2();
    void add_points_per_second();
    void reset();
};

#endif // GAME_H
