#ifndef RECORDRRANK_H
#define RECORDRRANK_H

#include <QDialog>
#include "Player.h"

namespace Ui {
class RecordRank;
}

class RecordRank : public QDialog
{
    Q_OBJECT

public:
    explicit RecordRank(QWidget *parent = nullptr);
    ~RecordRank();

    void setPlayer();
    void sendGrade(int number, int seconds);

private:
    Ui::RecordRank *ui;
    Player *player;
};

#endif // RECORDRRANK_H
