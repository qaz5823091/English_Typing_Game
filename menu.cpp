#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_clicked()
{
    mainWindow = new MainWindow();
    mainWindow->show();
}

void Menu::on_pushButton_3_clicked()
{
    custom = new Custom();
    custom->show();
}
