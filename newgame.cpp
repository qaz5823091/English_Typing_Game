#include "newgame.h"
#include "ui_newgame.h"

NewGame::NewGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewGame)
{
    ui->setupUi(this);
}

NewGame::~NewGame()
{
    delete ui;
}
