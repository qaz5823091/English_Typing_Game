#ifndef ARTICLE_H
#define ARTICLE_H

#include "Question.h"
#include "Word.h"
#include <vector>


class Article: public Question {
    private:
        std::vector<Word> words;

    public:
        Article();
};

#endif // ARTICLE_H
