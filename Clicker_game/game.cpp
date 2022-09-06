#include "game.h"
#include "menu.h"

Game::Game(int h, int w)
{
    height=h;
    width=w;

    this->setMinimumWidth(w);
    this->setMaximumWidth(w);
    this->setMinimumHeight(h);
    this->setMaximumHeight(h);

    this->setWindowTitle("Clicker");

    this->frame->setStyleSheet("QFrame {background-color: rgb(255,214,77)}");

    this->label_upgrade_1->setGeometry(950,180,200,100);
    this->upgrade_1_button->setGeometry(950,250,200,100);
    this->label_upgrade_2->setGeometry(950,330,200,100);
    this->upgrade_2_button->setGeometry(950,400,200,100);
    this->reset_button->setGeometry(700,650,200,100);
    this->exit_button->setGeometry(950,650,200,100);
    this->label_nr_points->setGeometry(0,0,200,100);
    this->label_nr_points_per_sec->setGeometry(0,100,200,100);
    this->frame->setGeometry(300,200,600,400);

    timer->setInterval(1000);
    timer->start();
    time();

    press_upgrade_1_button();
    press_upgrade_2_button();
    press_reset_button();
    press_exit_button();
}

Game::Game(int h, int w,long long p, long long ppc, long long pps, long long c1,long long c2)
{
    height=h;
    width=w;
    points = p;
    points_per_click = ppc;
    points_per_second = pps;
    cost_u1=c1;
    label_upgrade_1->setText("Cost: "+QString::number(cost_u1));
    cost_u2=c2;
    label_upgrade_2->setText("Cost: "+QString::number(cost_u2));
    this->label_nr_points_per_sec->setText("Number of points per second: " + QString::number(points_per_second));

    this->setMinimumWidth(w);
    this->setMaximumWidth(w);
    this->setMinimumHeight(h);
    this->setMaximumHeight(h);

    this->setWindowTitle("Clicker");

    this->frame->setStyleSheet("QFrame {background-color: rgb(255,214,77)}");

    this->label_upgrade_1->setGeometry(950,180,200,100);
    this->upgrade_1_button->setGeometry(950,250,200,100);
    this->label_upgrade_2->setGeometry(950,330,200,100);
    this->upgrade_2_button->setGeometry(950,400,200,100);
    this->reset_button->setGeometry(700,650,200,100);
    this->exit_button->setGeometry(950,650,200,100);
    this->label_nr_points->setGeometry(0,0,200,100);
    this->label_nr_points_per_sec->setGeometry(0,100,200,100);
    this->frame->setGeometry(300,200,600,400);

    timer->setInterval(1000);
    timer->start();
    time();

    press_upgrade_1_button();
    press_upgrade_2_button();
    press_reset_button();
    press_exit_button();
}

void Game::buy_upgrade_1()
{
    if(points>=cost_u1)
    {
        points-=cost_u1;
        this->label_nr_points->setText("Number of points: " + QString::number(points));
        points_per_click++;
        cost_u1*=1.5;
        label_upgrade_1->setText("Cost: "+QString::number(cost_u1));
    }
}

void Game::press_upgrade_1_button()
{
    QWidget::connect(upgrade_1_button,SIGNAL(clicked()),this,SLOT(buy_upgrade_1()));
}

void Game::buy_upgrade_2()
{
    if(points>=cost_u2)
    {
        points-=cost_u2;
        points_per_second++;
        cost_u2*=1.5;
        label_upgrade_2->setText("Cost: "+QString::number(cost_u2));
        this->label_nr_points->setText("Number of points: " + QString::number(points));
        this->label_nr_points_per_sec->setText("Number of points per second: " + QString::number(points_per_second));
    }
}

void Game::press_upgrade_2_button()
{
    QWidget::connect(upgrade_2_button,SIGNAL(clicked()),this,SLOT(buy_upgrade_2()));
}

void Game::mousePressEvent(QMouseEvent *event)
{
    if(event->button()== Qt::LeftButton)
    {
        if(event->x()>300 && event->x()<900 && event->y()>200 && event->y()<600)
        {
            points+=points_per_click;
            this->label_nr_points->setText("Number of points: " + QString::number(points));
        }
    }
}

void Game::add_points_per_second()
{
    points+=points_per_second;
    this->label_nr_points->setText("Number of points: " + QString::number(points));
}

void Game::go_to_menu()
{
    Menu *menu = new Menu(600,400);
    this->close();
    menu->show();
    QFile file("save.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);
        out << points;
        out << "\n";
        out << points_per_click;
        out << "\n";
        out << points_per_second;
        out << "\n";
        out << cost_u1;
        out << "\n";
        out << cost_u2;
        file.close();
    }

}

void Game::press_exit_button()
{
    QWidget::connect(exit_button,SIGNAL(clicked()),this,SLOT(go_to_menu()));
}

void Game::time()
{
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(add_points_per_second()));
}

void Game::press_reset_button()
{
    QWidget::connect(reset_button,SIGNAL(clicked()),this,SLOT(reset()));
}

void Game::reset()
{
    points=0;
    this->label_nr_points->setText("Number of points: " + QString::number(points));
    points_per_click=1;
    points_per_second=0;
    this->label_nr_points_per_sec->setText("Number of points per second: " + QString::number(points_per_second));
    cost_u1=100;
    this->label_upgrade_1->setText( "Cost: "+QString::number(cost_u1));
    cost_u2=200;
    this->label_upgrade_2->setText( "Cost: "+QString::number(cost_u2));
}
