#include "Player.h"

Player::Player() {

}

void Player::setName(QString n) {
    this->name = n;

    return ;
}

void Player::setScore(int s) {
    this->score = s;

    return ;
}

void Player::setWPM(double w) {
    this->WPM = w;

    return ;
}

void Player::setRanking(int r) {
    this->ranking = r;

    return ;
}

QString Player::getName() {
    return name;
}

int Player::getScore() {
    return score;
}

double Player::getWPM() {
    return WPM;
}

int Player::getRanking() {
    return ranking;
}
