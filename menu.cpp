#include "menu.h"
#include "ui_menu.h"
#include <QStackedWidget>

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
    ui->stackedWidget->setCurrentIndex(1);
}

void Menu::on_buttonEasy_clicked()
{
    mainWindow = new MainWindow(nullptr, ":/txt/vocabulary.txt");
    mainWindow->show();
}

void Menu::on_buttonToeic_clicked()
{
    mainWindow = new MainWindow(nullptr, ":/txt/Toeic.txt");
    mainWindow->show();
}
