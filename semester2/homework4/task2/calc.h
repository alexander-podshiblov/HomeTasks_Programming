#pragma once

#include <QMainWindow>

namespace Ui {
class Calc;
}

class Calc : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Calc(QWidget *parent = 0);
    ~Calc();

private slots:
    void result();
    
private:
    Ui::Calc *ui;
};
