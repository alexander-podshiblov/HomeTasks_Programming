#pragma once
#include <QSignalMapper>
#include <QPushButton>
#include <QWidget>

namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT
    
public:
    explicit Game(QWidget *parent = 0);
    ~Game();
    QPushButton *field[9];

signals:
    void win(int p);

public slots:
    void pressed(int k);
    void reset();
    void somebodyWin(int p);
    
private:
    Ui::Game *ui;
    QSignalMapper *sm;
    int m[9];
    int player;
    int checkOfWinner();
};

