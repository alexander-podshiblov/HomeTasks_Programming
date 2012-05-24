#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    player = 1;
    for (int i = 0; i < 9; i++)
        m[i] = 0;

    sm = new QSignalMapper(this);
    for (int i = 0; i < 9; i++)
    {
        field[i] = new QPushButton(" ", this);
        sm->setMapping(field[i], i);
        connect(field[i], SIGNAL(clicked()), sm, SLOT(map()));
    }

    ui->gridLayout->setSpacing(5);
    for(int i = 0; i < 9; i++)
        ui->gridLayout->addWidget(field[i], i / 3, i % 3);

    connect(sm, SIGNAL(mapped(int)), this, SLOT(pressed(int)));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(reset()));
    connect(this, SIGNAL(win(int)), this, SLOT(somebodyWin(int)));
    ui->lineEdit->setText("Course of the 'X' player");


}

void Game::pressed(int k)
{
    if (m[k] == 0)
    {
        if (player == 1)
        {
            m[k] = 1;
            field[k]->setText("X");
            ui->lineEdit->setText("Course of the '0' player");
        }
        else if (player == -1)
        {
            m[k] = -1;
            field[k]->setText("O");
            ui->lineEdit->setText("Course of the 'X' player");
        }
        player = player * (-1);
        ////////////////////////////////////

        int check = checkOfWinner();
        if (check != 0)
            emit win(check);
    }
}

int Game::checkOfWinner()
{
    for (int i = 0; i < 9; i = i + 3)
    {
        if (m[i] == m[i + 1] && m[i + 1] == m[i + 2])
            return m[i];
    }
    for (int i = 0; i < 3; i++)
    {
        if (m[i] == m[i + 3] && m[i + 3] == m[i + 6])
            return m[i];
    }
    if (m[0] == m[4] && m[4] == m[8])
        return m[0];
    else if (m[2] == m[4] && m[4] == m[6])
        return m[2];
    else
        return 0;
}

void Game::reset()
{
    ui->lineEdit->setText("Course of the 'X' player");
    player = 1;
    for (int i = 0; i < 9; i++)
    {
        m[i] = 0;
        field[i]->setText(" ");
    }
}


void Game::somebodyWin(int p)
{
    QString s;
    if (p == 1)
        s = "X WIN! Press RESET";
    else if (p == -1)
        s = "O WIN! Press RESET";
    ui->lineEdit->setText(s);
}

Game::~Game()
{
    for(int i = 0; i < 9; i++)
        delete field[i];
    delete sm;
    delete ui;
}
