#include "menu.h"
#include "ui_menu.h"
#include "ranklist.h"
#include <QStackedWidget>
#include <QMessageBox>
#include <QDebug>

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

void Menu::on_buttonNewGame_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Menu::on_buttonEasy_clicked()
{
    mainWindow = new MainWindow(nullptr, ":/txt/vocabulary.txt");
    mainWindow->setFixedSize(mainWindow->width(), mainWindow->height());
    mainWindow->show();
    ui->stackedWidget->setCurrentIndex(0);
    //this->close();
}

void Menu::on_buttonToeic_clicked()
{
    mainWindow = new MainWindow(nullptr, ":/txt/Toeic.txt");
    mainWindow->setFixedSize(mainWindow->width(), mainWindow->height());
    mainWindow->show();

    //this->close();
}


void Menu::keyPressEvent(QKeyEvent *event) {
    char key;
    key = char(event->key());
    switch(key) {
        case 'A':
            ui->stackedWidget->setCurrentIndex(0);
            break;
        case 'D':
            ui->stackedWidget->setCurrentIndex(1);
            break;
        default:
            break;
    }
}

void Menu::closeEvent(QCloseEvent *event) {
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "EnglishTypingGame",
                                                                    tr("Are you sure to exit?\n"),
                                                                    QMessageBox::No | QMessageBox::Yes,
                                                                    QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes)
        event->ignore();
    else
        event->accept();
}

void Menu::on_buttonRank_clicked() {
    Ranklist = new ranklist(this);
    Ranklist->setFixedSize(Ranklist->width(), Ranklist->height());
    Ranklist->show();
}
