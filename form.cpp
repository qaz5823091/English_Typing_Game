#include "form.h"
#include "ui_form.h"
#include "QStackedWidget"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    mainWindow = new MainWindow();
    custom = new Custom();


}

Form::~Form()
{
    delete ui;
}
