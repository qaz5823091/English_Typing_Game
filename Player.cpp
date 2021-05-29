#include "Player.h"

Player::Player() {

}

void Player::setFirstName(QString f) {
    this->firstName = f;

    return ;
}

void Player::setLastName(QString l) {
    this->lastName = l;

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

QString Player::getFirstName() {
    return firstName;
}

QString Player::getLastName() {
    return lastName;
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
