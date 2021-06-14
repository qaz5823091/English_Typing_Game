#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Player {
    private:
        QString name;
        double WPM;
        int ranking;

    public:
        Player();

        void setName(QString );
        void setWPM(double );
        void setRanking(int );

        QString getName();
        double getWPM();
        int getRanking();
};

#endif // PLAYER_H
