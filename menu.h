#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QCloseEvent>
#include "mainwindow.h"
#include "ranklist.h"
namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

    void keyPressEvent(QKeyEvent *event);

    void closeEvent(QCloseEvent *event);

private slots:

    void on_buttonEasy_clicked();

    void on_buttonToeic_clicked();

    void on_buttonNewGame_clicked();

    void on_buttonRank_clicked();

private:
    Ui::Menu *ui;
    MainWindow *mainWindow;
    ranklist *Ranklist;
};

#endif // MENU_H
