#ifndef QUESTION_H
#define QUESTION_H

class Question {
    private:
        int x;
        int y;
        bool solved;

    public:
        Question();

        void setX(int );
        void setY(int );
        void setSolved(bool );

        int getX();
        int getY();
        bool getSolved();
};

#endif // QUESTION_H
