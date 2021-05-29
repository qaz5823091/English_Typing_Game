#include "custom.h"
#include "ui_custom.h"

Custom::Custom(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Custom)
{
    ui->setupUi(this);
}

Custom::~Custom()
{
    delete ui;
}
