#include "calc.h"
#include "ui_calc.h"

Calc::Calc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calc)
{
    dot = false;
    first = 0;
    second = 0;
    oper = " ";
    k = 10;

    ui->setupUi(this);
    digitSM = new QSignalMapper(this);
    signSM = new QSignalMapper(this);

    for(int i = 0; i < 10; ++i)
    {
        digit[i] = new QPushButton(QString::number(i), this);
        digitSM->setMapping(digit[i], i);
        connect(digit[i], SIGNAL(clicked()), digitSM, SLOT(map()));
    }

    sign[0] = new QPushButton(".", this);
    signSM->setMapping(sign[0], ".");
    sign[1] = new QPushButton("+", this);
    signSM->setMapping(sign[1], "+");
    sign[2] = new QPushButton("-", this);
    signSM->setMapping(sign[2], "-");
    sign[3] = new QPushButton("*", this);
    signSM->setMapping(sign[3], "*");
    sign[4] = new QPushButton("/", this);
    signSM->setMapping(sign[4], "/");
    sign[5] = new QPushButton("=", this);
    signSM->setMapping(sign[5], "=");

    for (int i =0; i < 6; i++)
    {
        connect(sign[i], SIGNAL(clicked()), signSM, SLOT(map()));
    }

    ui->gridLayout->setSpacing(5);
    for(int i = 0; i < 9; ++i)
        ui->gridLayout->addWidget(digit[i + 1], i / 3, i % 3);
    for(int i = 1; i < 5; ++i)
        ui->gridLayout->addWidget(sign[i], i - 1, 3);
    ui->gridLayout->addWidget(digit[0], 3, 0);
    ui->gridLayout->addWidget(sign[0], 3, 1);
    ui->gridLayout->addWidget(sign[5], 3, 2);

    ui->lineEdit->setText(QString::number(0));

    connect(digitSM, SIGNAL(mapped(int)), this, SLOT(setFirst(int)));
    connect(digitSM, SIGNAL(mapped(int)), this, SLOT(setSecond(int)));
    connect(this, SIGNAL(argChanged(QString)), ui->lineEdit, SLOT(setText(QString)));
    connect(signSM, SIGNAL(mapped(QString)), this, SLOT(operation(QString)));






}

double result (double a, double b, QString oper)
{
    if (oper == "+")
        return a + b;
    else  if (oper == "-")
        return a - b;
    else  if (oper == "*")
        return a * b;
    else  if (oper == "/")
        if (b != 0)
            return a / b;
        else
            return INT_MIN;
}

void Calc::setFirst(int a)
{
    if (oper == " ")
    {
        if (!dot)
            first = first * 10 + a;
        else
        {
            double a1 = a;
            first = first + a1 / k;
            k = k * 10;
        }
        emit argChanged(QString::number(first));
    }
}

void Calc::setSecond(int a)
{
    if (oper != " ")
    {
        if (!dot)
            second = second * 10 + a;
        else
        {
            double a1 = a;
            second = second + a1 / k;
            k = k * 10;
        }
        emit argChanged(QString::number(second));
    }
}

void Calc::operation(QString s)
{
    if (s == ".")
        dot = true;

    else if (s == "=")
    {
        ui->lineEdit->setText(QString::number(result(first, second, oper)));
        dot = false;
        first = 0;
        second = 0;
        oper = " ";
        k = 10;
    }

    else
    {
        if (oper == " ")
        {
            oper = s;
            k = 10;
            dot = false;
        }
        else
        {
            first = result(first, second, oper);
            oper = s;
            second = 0;
            k = 10;
            dot = false;
        }
    }
}


Calc::~Calc()
{
    for(int i = 0; i < 10; i++)
        delete digit[i];
    for(int i = 0; i < 6; i++)
        delete sign[i];
    delete digitSM;
    delete signSM;
    delete ui;
}
