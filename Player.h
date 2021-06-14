#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <QString>

class Player {
    private:
        QString name;
        int score;
        double WPM;
        int ranking;

    public:
        Player();

        void setName(QString );
        void setScore(int );
        void setWPM(double );
        void setRanking(int );

        QString getName();
        int getScore();
        double getWPM();
        int getRanking();
};

#endif // PLAYER_H
