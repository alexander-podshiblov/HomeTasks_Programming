#pragma once
#include <QSignalMapper>
#include <QPushButton>
#include <QWidget>

namespace Ui {
class Calc;
}

class Calc : public QWidget
{
    Q_OBJECT
    
public:
    explicit Calc(QWidget *parent = 0);
    ~Calc();
    QPushButton *digit[10];
    QPushButton *sign[6];

signals:
    void argChanged(QString);

public slots:
    void setFirst(int);
    void setSecond(int);
    void operation(QString);
    
private:
    Ui::Calc *ui;
    QSignalMapper *digitSM;
    QSignalMapper *signSM;
    bool dot;
    double first;
    double second;
    QString oper;
    int k;
};
