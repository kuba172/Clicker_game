#include "menu.h"
#include "game.h"

#include <iostream>

Menu::Menu(int h,int w)
{
    height = h;
    width = w;
    //this->resize(h,w);
    this->setMinimumWidth(w);
    this->setMaximumWidth(w);
    this->setMinimumHeight(h);
    this->setMaximumHeight(h);

    this->setWindowTitle("Clicker");

    this->start_button->setGeometry(100,50,200,100);
    this->load_button->setGeometry(100,160,200,100);
    this->quit_button->setGeometry(100,400,200,100);


    press_start_button();
    press_load_button();
    press_quit_button();
}

void Menu::start_game()
{
    Game *game = new Game(800,1200);
    this->close();
    game->show();
}

void Menu::load_game()
{
    long long values[5];
    int i = 0;

    QFile file("save.txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);
        while(!in.atEnd()){
                values[i]=in.readLine().toLong();
                //qDebug() << in.readLine();
                i++;
        }
        file.close();
    }
    Game *game = new Game(800,1200,values[0],values[1],values[2],values[3],values[4]);
    this->close();
    game->show();
}

void Menu::press_start_button()
{
    QWidget::connect(start_button,SIGNAL(clicked()),this,SLOT(start_game()));
}

void Menu::press_load_button()
{
    QWidget::connect(load_button,SIGNAL(clicked()),this,SLOT(load_game()));
}

void Menu::press_quit_button()
{
    QWidget::connect(quit_button,SIGNAL(clicked()),this,SLOT(close()));
}


