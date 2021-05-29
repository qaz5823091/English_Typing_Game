#include "Question.h"

Question::Question() {
    this->x = 0;
    this->y = 0;
    this->solved = false;
}

void Question::setX(int x) {
    this->x = x;

    return ;
}

void Question::setY(int y) {
    this->y = y;

    return ;
}

void Question::setSolved(bool s) {
    this->solved = s;

    return ;
}

int Question::getX() {
    return x;
}

int Question::getY() {
    return y;
}

bool Question::getSolved() {
    return solved;
}
