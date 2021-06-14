#ifndef WORD_H
#define WORD_H

#include "Question.h"
#include <QString>

class Word: public Question {
    private:
        QString word;

    public:
        Word();
        Word(QString );

        void setWord(QString );
        QString getWord();
};

#endif // WORD_H
