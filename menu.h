#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QStackedWidget>
#include "mainwindow.h"

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:

    void on_buttonEasy_clicked();

    void on_buttonToeic_clicked();

    void on_buttonNewGame_clicked();

private:
    Ui::Menu *ui;
    MainWindow *mainWindow;
};

#endif // MENU_H
