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

private slots:
    void on_check_accepted();

    void on_check_rejected();

private:
    Ui::RecordRank *ui;
    Player *player;
};

#endif // RECORDRRANK_H
