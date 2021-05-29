#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <QString>

class Player {
    private:
        QString firstName;
        QString lastName;
        int score;
        double WPM;
        int ranking;

    public:
        Player();

        void setFirstName(QString );
        void setLastName(QString );
        void setScore(int );
        void setWPM(double );
        void setRanking(int );

        QString getFirstName();
        QString getLastName();
        int getScore();
        double getWPM();
        int getRanking();
};

#endif // PLAYER_H

// game
// ranking
// exit
