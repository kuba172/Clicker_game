#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QFile>


class Menu : public QWidget
{
    Q_OBJECT

public:
    Menu(int h, int w);
private:
    int height;
    int width;


    QPushButton *start_button = new QPushButton("Start",this);
    QPushButton *load_button = new QPushButton("Load",this);
    QPushButton *quit_button = new QPushButton("Quit",this);

public:
    void press_start_button();
    void press_quit_button();
    void press_load_button();

public slots:
    void start_game();
    void load_game();
};

#endif // MENU_H
