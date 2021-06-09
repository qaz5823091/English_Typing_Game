#include "whichgame.h"
#include "ui_whichgame.h"

WhichGame::WhichGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WhichGame)
{
    ui->setupUi(this);
}

WhichGame::~WhichGame()
{
    delete ui;
}
