#ifndef WHICHGAME_H
#define WHICHGAME_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class WhichGame;
}

class WhichGame : public QWidget
{
    Q_OBJECT

public:
    explicit WhichGame(QWidget *parent = nullptr);
    ~WhichGame();

private:
    Ui::WhichGame *ui;
};

#endif // WHICHGAME_H
