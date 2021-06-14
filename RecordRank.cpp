#include "RecordrRank.h"
#include "ui_RecordRank.h"

#include <QDebug>

RecordRank::RecordRank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecordRank)
{
    ui->setupUi(this);
    player = nullptr;
}

RecordRank::~RecordRank()
{
    delete ui;
}

void RecordRank::sendGrade(int number, int seconds) {
    player = new Player();
    player->setName( ui->nameEdit->text() );
    player->setRanking(0);
    player->setWPM( double(number  / (seconds / 60.0)) );
    // qDebug() << number << " " << seconds << " " << player->getWPM() ;
    ui->wpmLabel->setText("速度：    " + QString::number(player->getWPM()) + "    字 / 分鐘");
}


void RecordRank::on_check_accepted() {
    this->close();
}

void RecordRank::on_check_rejected() {
    player->setName("Unknown");
    this->close();
}

