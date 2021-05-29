#include "RecordrRank.h"
#include "ui_RecordRank.h"

#include <QDebug>

RecordRank::RecordRank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecordRank)
{
    ui->setupUi(this);
    player = new Player();
}

RecordRank::~RecordRank()
{
    delete ui;
}

void RecordRank::setPlayer() {
    player->setFirstName( ui->firstNameEdit->toPlainText() );
    player->setLastName( ui->lastNameEdit->toPlainText() );
    player->setScore(100);
    player->setRanking(0);
}

void RecordRank::sendGrade(int number, int seconds) {
    player->setWPM( double(number  / (seconds / 60.0)) );
    qDebug() << number << " " << seconds << " " << player->getWPM() ;
    ui->wpmLabel->setText("速度：    " + QString::number(player->getWPM()) + "    字 / 分鐘");
}
