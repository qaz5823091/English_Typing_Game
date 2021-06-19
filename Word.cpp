#include "Word.h"

Word::Word() {
    word = "";
}

Word::Word(QString w) {
    //setX(0);
    //setY(0);
    setSolved(false);
    setWord(w);
}

void Word::setWord(QString w) {
    word = w;

    return ;
}

QString Word::getWord() {
    return word;
}
