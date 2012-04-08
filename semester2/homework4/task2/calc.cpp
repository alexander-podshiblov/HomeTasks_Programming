#include "calc.h"
#include "ui_calc.h"

Calc::Calc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calc)
{
    ui->setupUi(this);

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(result()));
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(result()));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(result()));

}

void Calc::result()
{
    int a = ui->spinBox->value();
    int b = ui->spinBox_2->value();
    char c = 0;
    int index = ui->comboBox->currentIndex();
    if (index == 0)
        c = a + b;
    else if (index == 1)
        c = a - b;
    else if (index == 2)
        c = a * b;
    else
    {
        if (b == 0)
            ui->lineEdit->setText("Error");
        else
            c = a / b;
    }
    if ((index != 3) || (b != 0))
        ui->lineEdit->setText(QString::number(c));
}

Calc::~Calc()
{
    delete ui;
}
